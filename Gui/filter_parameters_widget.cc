#include "filter_parameters_widget.h"


SingleParamHBox::SingleParamHBox (QWidget *w1, QWidget *w2, QWidget *w3, QWidget *w4, int height,
                                  int width1, int width2, int width3, int width4)
{
    setSpacing (5);
    setMargin (0);

    w1->setMinimumHeight (height);
    w1->setMaximumHeight (height);
    w1->setMinimumWidth (width1);
    w1->setMaximumWidth (width1);

    w2->setMinimumHeight (height);
    w2->setMaximumHeight (height);
    w2->setMinimumWidth (width2);
    w2->setMaximumWidth (width2);

    w3->setMinimumHeight (height);
    w3->setMaximumHeight (height);
    w3->setMinimumWidth (width3);
    w3->setMaximumWidth (width3);

    w4->setMinimumHeight (height);
    w4->setMaximumHeight (height);
    w4->setMinimumWidth (width4);
    w4->setMaximumWidth (width4);

    addWidget (w1);
    addItem (new QSpacerItem (0, 0, QSizePolicy::Expanding));
    addWidget (w2);
    addWidget (w3);
    addWidget (w4);
}


FilterParametersWidget::FilterParametersWidget (QWidget *parent)
      : QGroupBox (parent),
        m_updateOn (true),
        m_filterParams (Filters::FilterParameters (20.0, 1.0, 0.1, 0.01, 1, 100))
{
    loadFonts();
    initControls();
    initLayouts();

    this->setTitle (tr ("Параметры фильтрации"));

    emit btnUpdateClicked();
}

FilterParametersWidget::~FilterParametersWidget()
{
}

void FilterParametersWidget::loadFonts()
{
    m_regularFont  = FontManager::instance().regular (9);
    m_monotypeFont = FontManager::instance().mono (9);
    this->setFont (m_regularFont);
}
#include <QDebug>
void FilterParametersWidget::computeSizes (int &h, int &w1, int &w2, int &w3, int &w4)
{
    QDoubleSpinBox *dsbTemp = new QDoubleSpinBox (this);
    dsbTemp->setFont (m_monotypeFont);
    h = dsbTemp->height();
    delete dsbTemp;

    w1 = h + QFontMetrics (m_regularFont).width (tr ("Количество прогнозов на интервале δt"));

    w2 = QFontMetrics (m_regularFont).width ("δτ");
    w2 = qMax (w2, QFontMetrics (m_regularFont).width ("δt"));
    w2 = qMax (w2, QFontMetrics (m_regularFont).width ("Δt"));

    w3 = QFontMetrics (m_regularFont).width ("=");
    w4 = h + QFontMetrics (m_monotypeFont).width ("499.9999");
}

void FilterParametersWidget::initControls()
{
    m_dsbMaxTime = new QDoubleSpinBox;
    m_dsbMaxTime->setDecimals (2);
    m_dsbMaxTime->setMinimum (1.0);
    m_dsbMaxTime->setMaximum (1000.0);
    m_dsbMaxTime->setSingleStep (1.0);
    m_dsbMaxTime->setValue (100.0);
    m_dsbMaxTime->setFont (m_monotypeFont);
    connect (m_dsbMaxTime, SIGNAL (valueChanged (double) ), this, SLOT (maxTimeChanged (double) ));

    m_dsbMeasurementStep = new QDoubleSpinBox;
    m_dsbMeasurementStep->setDecimals (4);
    m_dsbMeasurementStep->setMinimum (0.1);
    m_dsbMeasurementStep->setMaximum (50.0);
    m_dsbMeasurementStep->setSingleStep (0.1);
    m_dsbMeasurementStep->setValue (1.0);
    m_dsbMeasurementStep->setFont (m_monotypeFont);
    connect (m_dsbMeasurementStep, SIGNAL (valueChanged (double) ), this,
             SLOT (measurementStepChanged (double) ));

    m_dsbPredictionStep = new QDoubleSpinBox;
    m_dsbPredictionStep->setDecimals (4);
    m_dsbPredictionStep->setMinimum (0.0001);
    m_dsbPredictionStep->setMaximum (1.0);
    m_dsbPredictionStep->setSingleStep (0.0001);
    m_dsbPredictionStep->setValue (0.1);
    m_dsbPredictionStep->setFont (m_monotypeFont);
    connect (m_dsbPredictionStep, SIGNAL (valueChanged (double) ), this,
             SLOT (predictionStepChanged (double) ));

    m_sbPredictionCount = new QSpinBox;
    m_sbPredictionCount->setMinimum (0);
    m_sbPredictionCount->setMaximum (199);
    m_sbPredictionCount->setSingleStep (1);
    m_sbPredictionCount->setValue (9);
    m_sbPredictionCount->setFont (m_monotypeFont);
    connect (m_sbPredictionCount, SIGNAL (valueChanged (int) ), this,
             SLOT (predictionCountChanged (int) ));

    m_dsbIntegrationStep = new QDoubleSpinBox;
    m_dsbIntegrationStep->setDecimals (4);
    m_dsbIntegrationStep->setMinimum (0.001);
    m_dsbIntegrationStep->setMaximum (0.1);
    m_dsbIntegrationStep->setSingleStep (0.0001);
    m_dsbIntegrationStep->setValue (0.01);
    m_dsbIntegrationStep->setFont (m_monotypeFont);
    connect (m_dsbIntegrationStep, SIGNAL (valueChanged (double) ), this,
             SLOT (integrationStepChanged (double) ));

    m_sbOrderMultiplicity = new QSpinBox;
    m_sbOrderMultiplicity->setMinimum (1);
    m_sbOrderMultiplicity->setMaximum (10);
    m_sbOrderMultiplicity->setSingleStep (1);
    m_sbOrderMultiplicity->setValue (1);
    m_sbOrderMultiplicity->setFont (m_monotypeFont);
    connect (m_sbOrderMultiplicity, SIGNAL (valueChanged (int) ), this,
             SLOT (orderMultiplicityChanged (int) ));

    m_sbSampleSize = new QSpinBox;
    m_sbSampleSize->setMinimum (20);
    m_sbSampleSize->setMaximum (5000);
    m_sbSampleSize->setSingleStep (50);
    m_sbSampleSize->setValue (100);
    m_sbSampleSize->setFont (m_monotypeFont);
    connect (m_sbSampleSize, SIGNAL (valueChanged (int) ), this, SLOT (sampleSizeChanged (int) ));

    m_radioPredictionStep = new QRadioButton (tr ("Интервал между прогнозами"));
    m_radioPredictionStep->setChecked (true);
    connect (m_radioPredictionStep, SIGNAL (toggled (bool) ), this,
             SLOT (radioPredictionStepToggled (bool) ));

    m_radioPredictionCount = new QRadioButton (tr ("Количество прогнозов на интервале δt"));
    m_radioPredictionCount->setChecked (false);
    connect (m_radioPredictionCount, SIGNAL (toggled (bool) ), this,
             SLOT (radioPredictionCountToggled (bool) ));

    m_checkFixAll = new QCheckBox (tr ("Зафиксировать параметры"));
    m_checkFixAll->setChecked (false);
    connect (m_checkFixAll, SIGNAL (toggled (bool) ), this, SLOT (checkFixAllToggled (bool) ));

    m_btnUpdate = new QPushButton (tr ("Обновить"));
    connect (m_btnUpdate, SIGNAL (clicked()), this, SLOT (btnUpdateClicked()));
}

void FilterParametersWidget::initLayouts()
{
    int h, w1, w2, w3, w4;
    computeSizes (h, w1, w2, w3, w4);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMargin (5);
    mainLayout->setSpacing (5);

    mainLayout->addLayout (new SingleParamHBox (new QLabel (tr ("Терминальное время")),
                                                new QLabel (tr ("T")), new QLabel ("="),
                                                m_dsbMaxTime, h, w1, w2, w3, w4));

    mainLayout->addLayout (new SingleParamHBox (new QLabel (tr ("Интервал между измерениями")),
                                                new QLabel (tr ("δt")), new QLabel ("="),
                                                m_dsbMeasurementStep, h, w1, w2, w3, w4));

    mainLayout->addLayout (new SingleParamHBox (m_radioPredictionStep, new QLabel (tr ("δτ")),
                                                new QLabel ("="), m_dsbPredictionStep, h, w1, w2,
                                                w3, w4));

    mainLayout->addLayout (new SingleParamHBox (m_radioPredictionCount, new QLabel (tr ("L")),
                                                new QLabel ("="), m_sbPredictionCount, h, w1, w2,
                                                w3, w4));

    mainLayout->addLayout (new SingleParamHBox (new QLabel (tr ("Шаг интегрирования")),
                                                new QLabel (tr ("Δt")), new QLabel ("="),
                                                m_dsbIntegrationStep, h, w1, w2, w3, w4));

    mainLayout->addLayout (new SingleParamHBox (
    new QLabel (tr ("Кратность порядка фильтра (для ФПП)")), new QLabel (tr ("l")),
    new QLabel ("="), m_sbOrderMultiplicity, h, w1, w2, w3, w4));

    mainLayout->addLayout (new SingleParamHBox (new QLabel (tr ("Размер выборок")),
                                                new QLabel (tr ("S")), new QLabel ("="),
                                                m_sbSampleSize, h, w1, w2, w3, w4));

    mainLayout->addLayout (new SingleParamHBox (m_checkFixAll, new QLabel (" "), new QLabel (" "),
                                                m_btnUpdate, h, w1, w2, w3, w4));

    this->setLayout (mainLayout);
    this->setMinimumWidth (this->layout()->margin() * 2 + 15 + w1 + w2 + w3 + w4);
}


void FilterParametersWidget::setRange (QDoubleSpinBox *dsb, double min, double max)
{
    dsb->setMinimum (min);
    dsb->setMaximum (max);
    dsb->setSingleStep (0.01 * (max - min));
}

void FilterParametersWidget::setRange (QSpinBox *sb, int min, int max)
{
    sb->setMinimum (min);
    sb->setMaximum (max);
    sb->setSingleStep (1);
}

const Filters::FilterParameters &FilterParametersWidget::filterParameters() const
{
    return m_filterParams;
}


void FilterParametersWidget::maxTimeChanged (double arg1)
{
    if (m_updateOn) {
        m_filterParams.setMaxTime (arg1);
        emit filterParametersChanged (m_filterParams);
        setRange (m_dsbMeasurementStep, m_dsbPredictionStep->value(),
                  0.25 * m_dsbMaxTime->value());
    }
}

void FilterParametersWidget::measurementStepChanged (double arg1)
{
    if (m_updateOn) {
        m_filterParams.setMeasurementStep (arg1);

        setRange (m_dsbPredictionStep, m_dsbIntegrationStep->value(),
                  m_dsbMeasurementStep->value());
        setRange (m_sbPredictionCount, 0,
                  int(m_dsbPredictionStep->maximum() / m_dsbIntegrationStep->minimum()) - 1);

        m_updateOn = false;
        //если L = const :
        if (m_radioPredictionCount->isChecked()) {
            int L       = m_sbPredictionCount->value();
            double dtau = arg1 / double(L + 1);
            m_filterParams.setPredictionStep (dtau);
            m_dsbPredictionStep->setValue (dtau);
        }
        else {
            double dtau = m_dsbPredictionStep->value();
            int L = int(arg1 / dtau) - 1;
            if (arg1 - (L + 1) * dtau >= 0.5 * dtau) {
                L++;
            }
            m_sbPredictionCount->setValue (L);
        }
        m_updateOn = true;

        emit filterParametersChanged (m_filterParams);
    }
}

void FilterParametersWidget::predictionStepChanged (double arg1)
{
    if (m_updateOn) {
        m_filterParams.setPredictionStep (arg1);

        setRange (m_dsbIntegrationStep, 0.0001, m_dsbPredictionStep->value());
        setRange (m_dsbPredictionStep, m_dsbIntegrationStep->value(),
                  m_dsbMeasurementStep->value());
        setRange (m_dsbMeasurementStep, m_dsbPredictionStep->value(),
                  0.25 * m_dsbMaxTime->value());
        setRange (m_sbPredictionCount, 0,
                  int(m_dsbPredictionStep->maximum() / m_dsbIntegrationStep->minimum()) - 1);

        //вместе с stepPrediction корректируется maxTime:
        m_updateOn = false;
        int L = int(m_dsbMeasurementStep->value() / arg1) - 1;
        if (m_dsbMeasurementStep->value() - (L + 1) * arg1 >= 0.5 * arg1) {
            L++;
        }
        m_sbPredictionCount->setValue (L);
        m_updateOn = true;

        emit filterParametersChanged (m_filterParams);
    }
}

void FilterParametersWidget::predictionCountChanged (int arg1)
{
    if (m_updateOn) {
        m_dsbPredictionStep->setValue (m_dsbMeasurementStep->value() / double(arg1 + 1));
    }
}

void FilterParametersWidget::integrationStepChanged (double arg1)
{
    m_filterParams.setIntegrationStep (arg1);
    emit filterParametersChanged (m_filterParams);

    setRange (m_dsbPredictionStep, m_dsbIntegrationStep->value(), m_dsbMeasurementStep->value());
    setRange (m_sbPredictionCount, 0,
              int(m_dsbPredictionStep->maximum() / m_dsbIntegrationStep->minimum()) - 1);
}

void FilterParametersWidget::checkFixAllToggled (bool checked)
{
    m_dsbMaxTime->setEnabled (!checked);
    m_dsbMeasurementStep->setEnabled (!checked);
    m_dsbIntegrationStep->setEnabled (!checked);
    m_sbOrderMultiplicity->setEnabled (!checked);
    m_sbSampleSize->setEnabled (!checked);
    m_radioPredictionCount->setEnabled (!checked);
    m_radioPredictionStep->setEnabled (!checked);

    m_dsbPredictionStep->setEnabled (!checked && m_radioPredictionStep->isChecked());
    m_sbPredictionCount->setEnabled (!checked && m_radioPredictionCount->isChecked());
}
void FilterParametersWidget::radioPredictionStepToggled (bool checked)
{
    m_sbPredictionCount->setEnabled (!checked);
}

void FilterParametersWidget::radioPredictionCountToggled (bool checked)
{
    m_dsbPredictionStep->setEnabled (!checked);
}
void FilterParametersWidget::orderMultiplicityChanged (int arg1)
{
    m_filterParams.setOrderMultiplicity (arg1);
    emit filterOrderMultiplicityChanged (arg1);
    emit filterParametersChanged (m_filterParams);
}

void FilterParametersWidget::sampleSizeChanged (int arg1)
{
    m_filterParams.setSampleSize (arg1);
}

void FilterParametersWidget::btnUpdateClicked()
{
    m_dsbMaxTime->setValue (m_filterParams.maxTime());
    m_dsbMeasurementStep->setValue (m_filterParams.measurementStep());
    m_dsbPredictionStep->setValue (m_filterParams.predictionStep());
    m_dsbIntegrationStep->setValue (m_filterParams.integrationStep());
    m_sbPredictionCount->setValue (m_filterParams.predictionCount() - 1);
    emit filterParametersChanged (m_filterParams);
}

void FilterParametersWidget::blockParams (bool block)
{
    m_dsbMeasurementStep->setEnabled (block);
    m_sbSampleSize->setEnabled (block);
    m_dsbIntegrationStep->setEnabled (block);
    // TODO соглосовать с fixAll
}
