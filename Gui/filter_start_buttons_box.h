#ifndef FILTERSTARTBUTTONSBOX_H
#define FILTERSTARTBUTTONSBOX_H

#include <QWidget>
#include <QGroupBox>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "font_manager.h"
#include "Filters/filter_factory.h"


class FilterStartButtonsBox : public QGroupBox
{
    Q_OBJECT

public:

    explicit FilterStartButtonsBox (QWidget *parent = nullptr);
    ~FilterStartButtonsBox();

    const Filters::FilterParameters &filterParameters() const;
    const Tasks::SpecificParameters &specificParameters() const;


signals:

    void filterStart (FILTER_TYPE ftype, FILTER_ID id, APPROX_TYPE atype);


public slots:

    void clearAll();
    void filterOrderMultiplicityChanged (uint l);


private slots:

    void btnContinuousDiscreteGaussAofClicked();
    void btnContinuousDiscreteLinearAofClicked();
    void btnContinuousDiscreteGaussFosClicked();
    void btnContinuousDiscreteLinearFosClicked();
    void btnContinuousDiscreteGaussDfosClicked();
    void btnContinuousDiscreteLinearDfosClicked();
    void btnContinuousDiscreteGaussDfosboClicked();
    void btnContinuousDiscreteLinearDfosboClicked();

    void btnContinuousGaussAofClicked();
    void btnContinuousLinearAofClicked();
    void btnContinuousGaussFosClicked();
    void btnContinuousLinearFosClicked();

    void btnDiscreteLinearFOSmpClicked();
    void btnDiscreteGaussFOSmpClicked();
    void btnDiscreteLinearMFOSmpClicked();
    void btnDiscreteGaussMFOSmpClicked();

private:

    QVector< uint > m_usedForGauss;
    QVector< uint > m_usedForLinear;
    uint m_currentOrderMult;

    QPushButton *m_btnContinuousDiscreteGaussAof;
    QPushButton *m_btnContinuousDiscreteLinearAof;
    QPushButton *m_btnContinuousDiscreteGaussFos;
    QPushButton *m_btnContinuousDiscreteLinearFos;
    QPushButton *m_btnContinuousDiscreteGaussDfos;
    QPushButton *m_btnContinuousDiscreteLinearDfos;
    QPushButton *m_btnContinuousDiscreteGaussDfosbo;
    QPushButton *m_btnContinuousDiscreteLinearDfosbo;

    QPushButton *m_btnContinuousGaussAof;
    QPushButton *m_btnContinuousLinearAof;
    QPushButton *m_btnContinuousGaussFos;
    QPushButton *m_btnContinuousLinearFos;

    QPushButton *m_btnDiscreteLinearFOSmp;
    QPushButton *m_btnDiscreteGaussFOSmp;
    QPushButton *m_btnDiscreteLinearMFOSmp;
    QPushButton *m_btnDiscreteGaussMFOSmp;

    void loadFonts();
    void initLayouts();
    void initControls();
    void computeSizes();
};

#endif  // FILTERSTARTBUTTONSBOX_H
