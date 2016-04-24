#ifndef RANGES_DIALOG_H
#define RANGES_DIALOG_H

#include <QDialog>
#include <QFontMetrics>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include "Core/matrix.h"
#include <climits>
#include "font_manager.h"
#include "Libs/QCustomPlot/qcustomplot.h"


class RangesDialog : public QDialog
{
    Q_OBJECT

public:

    RangesDialog (const Vector2 &x, const Vector2 &y, QWidget *parent = nullptr);
    ~RangesDialog();


private slots:

    void yMaxChanged (double yMax);
    void yMinChanged (double yMin);
    void xMaxChanged (double xMax);
    void xMinChanged (double xMin);
    void acceptedClicked();
    void rejectedClicked();


signals:

    void rangesChanged (Vector2 x, Vector2 y);


private:
    QDoubleSpinBox *m_dsbXMin;
    QDoubleSpinBox *m_dsbXMax;
    QDoubleSpinBox *m_dsbYMin;
    QDoubleSpinBox *m_dsbYMax;

    QCustomPlot *m_plotter;

    QDialogButtonBox *m_buttonBox;

    void loadFonts();
    void initControls (const Vector2 &x, const Vector2 &y);
    void initPlotter();
    void initLayouts();
};

#endif  // RANGES_DIALOG_H
