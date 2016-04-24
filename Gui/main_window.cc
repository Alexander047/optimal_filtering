#include "main_window.h"
#include <QVBoxLayout>

MainWindow::MainWindow (QWidget *parent)
      : QMainWindow (parent),
        m_taskId (TASK_ID::Landing),
        m_colorManager (new ColorManager),
        m_randSeed (1447528517)
{
    initControls();
    initLayouts();
    initStatusBar();
    loadFonts();

    QRect screenRect = QApplication::desktop()->availableGeometry();
    setGeometry (screenRect.x() + 25, screenRect.y() + 50, this->minimumWidth(),
                 screenRect.height() - 75);

    initGraphWindow();
}

MainWindow::~MainWindow()
{
    delete m_graphWindow;
}

void MainWindow::loadFonts()
{
    this->setFont (FontManager::instance().regular (9));
    this->statusBar()->setFont (FontManager::instance().regularItalic (9));
}

void MainWindow::initControls()
{
    m_taskWidget         = new TaskWidget;
    m_filterParamsWidget = new FilterParametersWidget;
    m_filterStartWidget  = new FilterStartButtonsBox;
    m_btnClear           = new QPushButton (tr ("Очистить"));

    connect (m_btnClear, SIGNAL (clicked()), m_filterStartWidget, SLOT (clearAll()));
    connect (m_btnClear, SIGNAL (clicked()), m_taskWidget, SLOT (clearAll()));
    connect (m_btnClear, SIGNAL (clicked()), this, SLOT (clearAll()));

    connect (m_taskWidget, SIGNAL (taskChanged (TASK_ID)), this, SLOT (taskChanged (TASK_ID)));
    connect (this, SIGNAL (blockParams (bool) ), m_filterParamsWidget, SLOT (blockParams (bool) ));
    connect (m_filterStartWidget, SIGNAL (filterStart (FILTER_TYPE, FILTER_ID, APPROX_TYPE)), this,
             SLOT (filterStart (FILTER_TYPE, FILTER_ID, APPROX_TYPE)));
}

void MainWindow::initLayouts()
{
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin (5);
    layout->setSpacing (5);
    layout->addWidget (m_taskWidget);
    layout->addWidget (m_filterParamsWidget);
    layout->addWidget (m_filterStartWidget);
    layout->addItem (new QSpacerItem (0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
    layout->addWidget (m_btnClear);

    if (!centralWidget()) {
        setCentralWidget (new QWidget);
    }
    centralWidget()->setLayout (layout);

    centralWidget()->setMinimumWidth (layout->margin() * 2 +
                                       m_filterParamsWidget->minimumWidth());
    this->setMinimumWidth (this->layout()->margin() * 2 + centralWidget()->minimumWidth());
}

void MainWindow::initStatusBar()
{
    int w = centralWidget()->minimumWidth() / 3;
    int h = QFontMetrics (statusBar()->font()).height();

    m_statusProgressBar = new QProgressBar;
    m_statusProgressBar->setMinimumWidth (w);
    m_statusProgressBar->setMaximumWidth (w);
    m_statusProgressBar->setMinimumHeight (h);
    m_statusProgressBar->setMaximumHeight (h);
    m_statusProgressBar->setEnabled (false);
    m_statusProgressBar->setValue (0);

    if (!statusBar()) {
        setStatusBar (new QStatusBar);
    }
    statusBar()->addPermanentWidget (m_statusProgressBar);
    statusBar()->layout()->setMargin (centralWidget()->layout()->margin());
    statusBar()->layout()->setSpacing (centralWidget()->layout()->spacing());
    statusBar()->showMessage (tr ("Состояние: ничего не выполняется"));
}

void MainWindow::initGraphWindow()
{
    m_graphWindow = new GraphWindow;
    m_graphWindow->setWindowFlags (Qt::Window | Qt::WindowMinimizeButtonHint |
                                   Qt::WindowMaximizeButtonHint | Qt::CustomizeWindowHint);
    m_graphWindow->setWindowTitle (tr ("Графики"));
    QRect screenRect = QApplication::desktop()->availableGeometry();
    m_graphWindow->setGeometry (this->x() + this->width() + 25, screenRect.y() + 50,
                                screenRect.width() - this->width() - 75,
                                screenRect.height() - 75);

    connect (m_btnClear, SIGNAL (clicked()), m_graphWindow, SLOT (clearAll()));

    m_graphWindow->setCountSheets (1);
    m_graphWindow->updatePlotter();
    m_graphWindow->show();
}

void MainWindow::closeEvent (QCloseEvent *)
{
    QApplication::closeAllWindows();
}


// slots:

void MainWindow::clearAll()
{
    // emit blockParams (false); //TODO
    delete m_colorManager;
    m_colorManager = new ColorManager;
}

void MainWindow::filterStart (FILTER_TYPE ftype, FILTER_ID id, APPROX_TYPE atype)
{
    // TODO:
    // emit blockParams (true); // заблокировать изменение SS, dt, delta_t...

    FilterFactory factory;
    Filters::Filter *filter =
    factory.createFilter (ftype, id, m_taskId, atype, m_filterParamsWidget->filterParameters());
    connect (filter, SIGNAL (updatePercent (int) ), this, SLOT (filterUpdatePercent (int) ));

    m_statusProgressBar->setEnabled (true);
    QString status = "Состояние: выполняется " + QString::fromStdString (filter->name());
    statusBar()->showMessage (status);

    Rand::setRandSeed (m_randSeed);
    filter->run();

    showData (filter, m_colorManager->nextColor());
    this->statusBar()->showMessage (tr ("Состояние: ничего не выполняется"));
    m_statusProgressBar->setEnabled (false);
    m_statusProgressBar->setValue (0);
    delete filter;
}

void MainWindow::taskChanged (TASK_ID id)
{
    if (m_taskId != id) {
        emit m_btnClear->clicked();
    }
    m_taskId = id;
}

void MainWindow::filterUpdatePercent (int p)
{
    m_statusProgressBar->setValue (p);
}

void MainWindow::showData (Filters::Filter *filter, const QColor &color)
{
    int dim      = filter->result()[0].mx.size();
    int out_step = 1;
    int s = int(filter->result().size()) / out_step;
    while (s * out_step > (int) filter->result().size()) {
        s -= out_step;
    }

    QVector< double > x (s), y (s);

    for (int j = 0; j < s; j += out_step) {
        x[j] = filter->result()[j].time;
    }

    QVector< double > mm (dim);  //множители (1 если не "спуск", иначе необходимый)
    if (m_taskId == TASK_ID::Landing) {
        mm[0] = mm[2] = 1000;
        mm[1] = RadToDeg (1.0);
    }
    else {
        for (int i = 0; i < dim; i++) {
            mm[i] = 1.0;
        }
    }

    QPen mx_pen;
    mx_pen.setWidthF (2.0);
    mx_pen.setColor (Qt::darkMagenta);

    QPen sx_pen;
    sx_pen.setWidthF (1.5);
    sx_pen.setColor (Qt::darkGray);
    sx_pen.setStyle (Qt::DashLine);

    QPen se_pen;
    se_pen.setWidthF (1.5);
    se_pen.setColor (color);

    QString fname = QString::fromStdString (filter->name());

    if (m_graphWindow->countSheets() != dim) {
        m_graphWindow->setCountSheets (dim);
    }
    QString title = QString ("Статистика <") + m_taskWidget->taskName() + QString (">");
    QString subTitle =
    QString ("Размер выборки ") +
    QString::number (m_filterParamsWidget->filterParameters().sampleSize()) +
    QString (", шаг интегрирования ") +
    QString::number (m_filterParamsWidget->filterParameters().integrationStep()) +
    QString (", между измерениями ") +
    QString::number (m_filterParamsWidget->filterParameters().measurementStep());
    for (int i = 0; i < dim; i++) {
        m_graphWindow->sheet (i).setTitleLabel (title);
        m_graphWindow->sheet (i).setSubTitleLabel (subTitle);
    }
    if (m_taskId == TASK_ID::Landing) {
        m_graphWindow->sheet (0).setXLabel ("Время (с)");
        m_graphWindow->sheet (1).setXLabel ("Время (с)");
        m_graphWindow->sheet (2).setXLabel ("Время (с)");
        m_graphWindow->sheet (0).setYLabel ("Скорость (м/c)");
        m_graphWindow->sheet (1).setYLabel ("Угол наклона (°)");
        m_graphWindow->sheet (2).setYLabel ("Высота (м)");
    }

    for (int i = 0; i < dim; i++) {
        // M [X]  :
        for (int j = 0; j < s; j += out_step) {
            y[j] = filter->result()[j * out_step].mx[i] * mm[i];
        }
        m_graphWindow->sheet (i).addCurve (x, y, "Mx" + QString::number (i + 1), mx_pen, false);

        // S [X]  :
        for (int j = 0; j < s; j += out_step) {
            y[j] = std::sqrt (filter->result()[j * out_step].Dx (i, i)) * mm[i];
        }
        m_graphWindow->sheet (i).addCurve (x, y, "Sx" + QString::number (i + 1), sx_pen, false);

        // S [E]  :
        for (int j = 0; j < s; j += out_step) {
            y[j] = std::sqrt (filter->result()[j * out_step].De (i, i)) * mm[i];
        }
        m_graphWindow->sheet(i).addCurve (x, y, "Se" +
                                          QString::number (i + 1) + " " +
                                          fname, se_pen, true);
    }

    m_graphWindow->updatePlotter();
}
