#ifndef FILTERPARAMETERSWIDGET_H
#define FILTERPARAMETERSWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include "font_manager.h"
#include "Filters/filters.h"


class SingleParamHBox : public QHBoxLayout
{

public:

    SingleParamHBox (QWidget *w1, QWidget *w2, QWidget *w3, QWidget *w4, int height, int width1,
                     int width2, int width3, int width4);
};


class FilterParametersWidget : public QGroupBox
{
    Q_OBJECT

public:

    explicit FilterParametersWidget (QWidget *parent = nullptr);
    ~FilterParametersWidget();

    const Filters::FilterParameters &filterParameters() const;
    const Tasks::SpecificParameters &specificParameters() const;


signals:

    void filterParametersChanged (Filters::FilterParameters input);
    void filterOrderMultiplicityChanged (uint);


public slots:

    void blockParams (bool block);


private slots:

    void maxTimeChanged (double arg1);
    void measurementStepChanged (double arg1);
    void predictionStepChanged (double arg1);
    void predictionCountChanged (int arg1);
    void integrationStepChanged (double arg1);
    void checkFixAllToggled (bool checked);
    void radioPredictionStepToggled (bool checked);
    void radioPredictionCountToggled (bool checked);
    void orderMultiplicityChanged (int arg1);
    void sampleSizeChanged (int arg1);
    void btnUpdateClicked();


private:

    QFont m_regularFont;
    QFont m_monotypeFont;

    QDoubleSpinBox *m_dsbMaxTime;
    QDoubleSpinBox *m_dsbMeasurementStep;
    QDoubleSpinBox *m_dsbPredictionStep;
    QSpinBox *m_sbPredictionCount;
    QDoubleSpinBox *m_dsbIntegrationStep;
    QSpinBox *m_sbOrderMultiplicity;
    QSpinBox *m_sbSampleSize;
    QRadioButton *m_radioPredictionStep;
    QRadioButton *m_radioPredictionCount;
    QCheckBox *m_checkFixAll;
    QPushButton *m_btnUpdate;

    bool m_updateOn;
    Filters::FilterParameters m_filterParams;
    Tasks::SpecificParameters m_specificParams;

    QFont m_labelsFont;
    QFont m_spinBoxesFont;

    void setRange (QDoubleSpinBox *dsb, double min, double max);
    void setRange (QSpinBox *sb, int min, int max);
    void loadFonts();
    void computeSizes (int &h, int &w1, int &w2, int &w3, int &w4);
    void initLayouts();
    void initControls();
};

#endif  // FILTERPARAMETERSWIDGET_H
