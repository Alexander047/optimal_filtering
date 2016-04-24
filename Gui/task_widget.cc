#include "task_widget.h"
#include <QDebug>
#include "font_manager.h"


TaskWidget::TaskWidget (QWidget *parent) : QGroupBox (parent), m_taskId (TASK_ID::Landing)
{
    m_specParamsWindowHidden = true;

    loadFonts();
    initControls();
    initLayouts();

    this->setTitle (tr ("Решаемая задача"));
}

TaskWidget::~TaskWidget()
{
}

void TaskWidget::loadFonts()
{
    this->setFont (FontManager::instance().regular (9));
}

void TaskWidget::initControls()
{
    m_cbTask = new QComboBox;
    m_cbTask->addItem (tr ("Спуск ЛА на планету"));
    m_cbTask->addItem (tr ("Осциллятор Ван-дер-Поля"));
    m_cbTask->setCurrentIndex (0);
    connect (m_cbTask, SIGNAL (currentIndexChanged (int) ), this, SLOT (cbTaskChanged (int) ));

    m_btnSpecificParameters = new QPushButton (tr ("Показать"));
    connect (m_btnSpecificParameters, SIGNAL (clicked()), this,
             SLOT (btnSpecificParametersClicked()));
}

void TaskWidget::initLayouts()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin (5);
    mainLayout->setSpacing (5);

    mainLayout->addWidget (m_cbTask);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->setMargin (5);
    layout->setSpacing (5);
    QLabel *lbl = new QLabel (tr ("Специфические параметры"));
    lbl->setMinimumWidth (QFontMetrics (this->font()).width (lbl->text()));
    layout->addWidget (lbl);
    layout->addItem (new QSpacerItem (0, 0, QSizePolicy::Expanding));
    m_btnSpecificParameters->setMinimumWidth (
    QFontMetrics (this->font()).width ("    " + m_btnSpecificParameters->text()));
    layout->addWidget (m_btnSpecificParameters);

    mainLayout->addLayout (layout);

    this->setLayout (mainLayout);
}

QString TaskWidget::taskName() const
{
    return m_cbTask->currentText();
}

void TaskWidget::clearAll()
{
    // TODO
}

void TaskWidget::btnSpecificParametersClicked()
{
    if (m_specParamsWindowHidden) {
        m_btnSpecificParameters->setText (tr ("Показать"));
        m_specParamsWindowHidden = false;
    }
    else {
        m_btnSpecificParameters->setText (tr ("Скрыть"));
        m_specParamsWindowHidden = true;
    }
    // TODO
}

void TaskWidget::cbTaskChanged (int index)
{
    switch (index) {
    case 0:
        m_taskId = TASK_ID::Landing;
        emit taskChanged (m_taskId);
        break;
    case 1:
        m_taskId = TASK_ID::VanDerPol;
        emit taskChanged (m_taskId);
        break;
    default:
        break;
    }
}
