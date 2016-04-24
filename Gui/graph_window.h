#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QPen>
#include <QMenu>
#include <QAction>
#include "Core/array.h"
#include "Core/matrix.h"
#include "Gui/ranges_dialog.h"
#include "Gui/graph_sheet.h"
#include <QFileDialog>
#include <QDebug>
#include "Libs/QCustomPlot/qcustomplot.h"
#include <QFrame>
#include "font_manager.h"


class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit GraphWindow (QWidget *parent = nullptr);
    ~GraphWindow();

    int countSheets() const;

    GraphSheet &sheet (int index);
    GraphSheet &currentSheet();

    void setCountSheets (int count);
    void updatePlotter();


public slots:

    void clearAll();


private slots:

    void selectionChanged();
    void mousePress();
    void mouseWheel();
    void menuRequest (QPoint pos);
    void moveLegend();

    void rangesChanged (Vector2 x, Vector2 y);
    void savePng();
    void showSetRangesDialog();
    void setAutoRanges (bool checked);
    void hideCurve (QAction *action);
    void showCurve (QAction *action);
    void currentSheetChanged (QAction *action);


private:

    QCustomPlot *m_plotter;

    QVector< GraphSheet > m_sheets;
    GraphSheet *m_currentSheet;

    QFont m_plotterTitleFont;
    QFont m_plotterSubTitleFont;
    QFont m_plotterLegendFont;
    QFont m_plotterAxesLabelFont;
    QFont m_plotterAxesTickLabelFont;

    QAction *m_actionSavePng;
    QAction *m_actionShowSetRangesDialog;
    QAction *m_actionSetAutoRanges;

    QMenu *m_menuFile;
    QMenu *m_menuView;
    QMenu *m_menuSheet;
    QMenu *m_menuShow;
    QMenu *m_menuHide;

    void loadFonts();
    void initActions();
    void initMenus();
    void initLayouts();
    void initPlotter();
    void updateMenu();
};

#endif  // GRAPH_WINDOW_H
