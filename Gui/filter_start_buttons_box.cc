#include "filter_start_buttons_box.h"


FilterStartButtonsBox::FilterStartButtonsBox (QWidget *parent) : QGroupBox (parent)
{
    m_currentOrderMult = 1;

    loadFonts();
    initControls();
    computeSizes();
    initLayouts();

    this->setTitle (tr ("Фильтры"));
}

FilterStartButtonsBox::~FilterStartButtonsBox()
{
}

void FilterStartButtonsBox::loadFonts()
{
    this->setFont (FontManager::instance().regular (9));
}

void FilterStartButtonsBox::initControls()
{
    m_btnContinuousDiscreteGaussAof = new QPushButton (tr ("Г-АОФ"));
    connect (m_btnContinuousDiscreteGaussAof, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteGaussAofClicked()));

    m_btnContinuousDiscreteLinearAof = new QPushButton (tr ("Л-АОФ"));
    connect (m_btnContinuousDiscreteLinearAof, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteLinearAofClicked()));

    m_btnContinuousDiscreteGaussFos = new QPushButton (tr ("Г-ФМП"));
    connect (m_btnContinuousDiscreteGaussFos, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteGaussFosClicked()));

    m_btnContinuousDiscreteLinearFos = new QPushButton (tr ("Л-ФМП"));
    connect (m_btnContinuousDiscreteLinearFos, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteLinearFosClicked()));

    m_btnContinuousDiscreteGaussDfos = new QPushButton (tr ("Г-ФМПд"));
    connect (m_btnContinuousDiscreteGaussDfos, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteGaussDfosClicked()));

    m_btnContinuousDiscreteLinearDfos = new QPushButton (tr ("Л-ФМПд"));
    connect (m_btnContinuousDiscreteLinearDfos, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteLinearDfosClicked()));

    m_btnContinuousDiscreteGaussDfosbo = new QPushButton (tr ("Г-ФКП"));
    connect (m_btnContinuousDiscreteGaussDfosbo, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteGaussDfosboClicked()));

    m_btnContinuousDiscreteLinearDfosbo = new QPushButton (tr ("Л-ФКП"));
    connect (m_btnContinuousDiscreteLinearDfosbo, SIGNAL (clicked()), this,
             SLOT (btnContinuousDiscreteLinearDfosboClicked()));

    m_btnDiscreteLinearFOSmp = new QPushButton (tr ("Л-ФОСмп"));
    connect (m_btnDiscreteLinearFOSmp, SIGNAL (clicked()), this,
             SLOT (btnDiscreteLinearFOSmpClicked()));

    m_btnDiscreteGaussFOSmp = new QPushButton (tr ("Г-ФОСмп"));
    connect (m_btnDiscreteGaussFOSmp, SIGNAL (clicked()), this,
             SLOT (btnDiscreteGaussFOSmpClicked()));

    m_btnDiscreteLinearMFOSmp = new QPushButton (tr ("Л-MФОСмп"));
    connect (m_btnDiscreteLinearMFOSmp, SIGNAL (clicked()), this,
             SLOT (btnDiscreteLinearMFOSmpClicked()));

    m_btnDiscreteGaussMFOSmp = new QPushButton (tr ("Г-MФОСмп"));
    connect (m_btnDiscreteGaussMFOSmp, SIGNAL (clicked()), this,
             SLOT (btnDiscreteGaussMFOSmpClicked()));

}

void FilterStartButtonsBox::computeSizes()
{
}

void FilterStartButtonsBox::initLayouts()
{
    QTabWidget *tabWidget = new QTabWidget;

    QWidget *tab1 = new QWidget;
    QWidget *tab2 = new QWidget;
    QWidget *tab3 = new QWidget;

    tabWidget->addTab (tab1, tr ("Непрерывно-дискретные"));
    tabWidget->addTab (tab2, tr ("Непрерывные"));
    tabWidget->addTab (tab3, tr ("Дискретные"));

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin (5);
    mainLayout->setSpacing (0);
    mainLayout->addWidget (tabWidget);
    this->setLayout (mainLayout);

    // tab1:
    QHBoxLayout *tab1MainLayout = new QHBoxLayout;
    tab1MainLayout->setMargin (5);
    tab1MainLayout->setSpacing (5);

    // tab2:
    QHBoxLayout *tab2MainLayout = new QHBoxLayout;
    tab2MainLayout->setMargin (5);
    tab2MainLayout->setSpacing (5);

    // tab3:
    QHBoxLayout *tab3MainLayout = new QHBoxLayout;
    tab3MainLayout->setMargin (5);
    tab3MainLayout->setSpacing (5);

    // непрерывно-дискретные фильтры
    QVBoxLayout *layoutCDAof = new QVBoxLayout;
    layoutCDAof->setMargin (0);
    layoutCDAof->setSpacing (5);
    layoutCDAof->addWidget (m_btnContinuousDiscreteGaussAof);
    layoutCDAof->addWidget (m_btnContinuousDiscreteLinearAof);
    tab1MainLayout->addLayout (layoutCDAof);

    QVBoxLayout *layoutCDFos = new QVBoxLayout;
    layoutCDFos->setMargin (0);
    layoutCDFos->setSpacing (5);
    layoutCDFos->addWidget (m_btnContinuousDiscreteGaussFos);
    layoutCDFos->addWidget (m_btnContinuousDiscreteLinearFos);
    tab1MainLayout->addLayout (layoutCDFos);

    QVBoxLayout *layoutCDDfos = new QVBoxLayout;
    layoutCDDfos->setMargin (0);
    layoutCDDfos->setSpacing (5);
    layoutCDDfos->addWidget (m_btnContinuousDiscreteGaussDfos);
    layoutCDDfos->addWidget (m_btnContinuousDiscreteLinearDfos);
    tab1MainLayout->addLayout (layoutCDDfos);

    QVBoxLayout *layoutCDDfosbo = new QVBoxLayout;
    layoutCDDfosbo->setMargin (0);
    layoutCDDfosbo->setSpacing (5);
    layoutCDDfosbo->addWidget (m_btnContinuousDiscreteGaussDfosbo);
    layoutCDDfosbo->addWidget (m_btnContinuousDiscreteLinearDfosbo);
    tab1MainLayout->addLayout (layoutCDDfosbo);


    // дискретные фильтры
    QVBoxLayout *layoutDformp = new QVBoxLayout;
    layoutDformp->setMargin (0);
    layoutDformp->setSpacing (5);
    layoutDformp->addWidget (m_btnDiscreteGaussFOSmp);
    layoutDformp->addWidget (m_btnDiscreteLinearFOSmp);
    tab3MainLayout->addLayout (layoutDformp);

    QVBoxLayout *layoutDmformp = new QVBoxLayout;
    layoutDmformp->setMargin (0);
    layoutDmformp->setSpacing (5);
    layoutDmformp->addWidget (m_btnDiscreteGaussMFOSmp);
    layoutDmformp->addWidget (m_btnDiscreteLinearMFOSmp);
    tab3MainLayout->addLayout (layoutDmformp);

    tab1->setLayout (tab1MainLayout);
    tab2->setLayout(tab2MainLayout);
    tab3->setLayout(tab3MainLayout);
}

void FilterStartButtonsBox::clearAll()
{
    m_usedForLinear.clear();
    m_usedForGauss.clear();
    m_btnContinuousDiscreteGaussAof->setEnabled (true);
    m_btnContinuousDiscreteLinearAof->setEnabled (true);
    m_btnContinuousDiscreteGaussFos->setEnabled (true);
    m_btnContinuousDiscreteLinearFos->setEnabled (true);
    m_btnContinuousDiscreteGaussDfos->setEnabled (true);
    m_btnContinuousDiscreteLinearDfos->setEnabled (true);
    m_btnContinuousDiscreteGaussDfosbo->setEnabled (true);
    m_btnContinuousDiscreteLinearDfosbo->setEnabled (true);

    m_btnDiscreteLinearFOSmp->setEnabled(true);
    m_btnDiscreteGaussFOSmp->setEnabled(true);
    m_btnDiscreteLinearMFOSmp->setEnabled(true);
    m_btnDiscreteGaussMFOSmp->setEnabled(true);
}

void FilterStartButtonsBox::filterOrderMultiplicityChanged (uint l)
{
    if (m_currentOrderMult == l) {
        return;
    }

    bool enableG = true;
    bool enableL = true;
    for (int i = 0; i < m_usedForGauss.size(); i++) {
        if (m_usedForGauss[i] == l) {
            enableG = false;
            i       = 100500;
        }
    }
    for (int i = 0; i < m_usedForLinear.size(); i++) {
        if (m_usedForLinear[i] == l) {
            enableL = false;
            i       = 100500;
        }
    }

    m_btnContinuousDiscreteGaussDfosbo->setEnabled (enableG);
    m_btnContinuousDiscreteLinearDfosbo->setEnabled (enableL);
    m_currentOrderMult = l;
}


void FilterStartButtonsBox::btnContinuousDiscreteGaussAofClicked()
{
    m_btnContinuousDiscreteGaussAof->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::AOF, APPROX_TYPE::Gauss);
}

void FilterStartButtonsBox::btnContinuousDiscreteLinearAofClicked()
{
    m_btnContinuousDiscreteLinearAof->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::AOF, APPROX_TYPE::Linear);
}

void FilterStartButtonsBox::btnContinuousDiscreteGaussFosClicked()
{
    m_btnContinuousDiscreteGaussFos->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::FOS, APPROX_TYPE::Gauss);
}

void FilterStartButtonsBox::btnContinuousDiscreteLinearFosClicked()
{
    m_btnContinuousDiscreteLinearFos->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::FOS, APPROX_TYPE::Linear);
}

void FilterStartButtonsBox::btnContinuousDiscreteGaussDfosClicked()
{
    m_btnContinuousDiscreteGaussDfos->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::DFOS, APPROX_TYPE::Gauss);
}

void FilterStartButtonsBox::btnContinuousDiscreteLinearDfosClicked()
{
    m_btnContinuousDiscreteLinearDfos->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::DFOS, APPROX_TYPE::Linear);
}

void FilterStartButtonsBox::btnContinuousDiscreteGaussDfosboClicked()
{
    m_usedForGauss.append (m_currentOrderMult);
    m_btnContinuousDiscreteGaussDfosbo->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::DFOSBO, APPROX_TYPE::Gauss);
}

void FilterStartButtonsBox::btnContinuousDiscreteLinearDfosboClicked()
{
    m_usedForLinear.append (m_currentOrderMult);
    m_btnContinuousDiscreteLinearDfosbo->setEnabled (false);
    emit filterStart (FILTER_TYPE::ContinuousDiscrete, FILTER_ID::DFOSBO, APPROX_TYPE::Linear);
}

// Дискретные

void FilterStartButtonsBox::btnDiscreteGaussFOSmpClicked() {
    m_btnDiscreteGaussFOSmp->setEnabled(false);
    emit filterStart (FILTER_TYPE::Discrete, FILTER_ID::FOSmp, APPROX_TYPE::Gauss);
}

void FilterStartButtonsBox::btnDiscreteLinearFOSmpClicked() {
    m_btnDiscreteLinearFOSmp->setEnabled(false);
    emit filterStart (FILTER_TYPE::Discrete, FILTER_ID::FOSmp, APPROX_TYPE::Linear);
}

void FilterStartButtonsBox::btnDiscreteLinearMFOSmpClicked() {
    m_btnDiscreteLinearMFOSmp->setEnabled(false);
    emit filterStart (FILTER_TYPE::Discrete, FILTER_ID::FOSmp, APPROX_TYPE::Linear);
}

void FilterStartButtonsBox::btnDiscreteGaussMFOSmpClicked() {
    m_btnDiscreteGaussMFOSmp->setEnabled(false);
    emit filterStart (FILTER_TYPE::Discrete, FILTER_ID::FOSmp, APPROX_TYPE::Gauss);
}
