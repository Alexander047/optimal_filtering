#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QCloseEvent>
#include <QVector>
#include <QColor>
#include <QStatusBar>
#include <QProgressBar>
#include "Gui/task_widget.h"
#include "Gui/filter_parameters_widget.h"
#include "Gui/filter_start_buttons_box.h"
#include "Gui/graph_window.h"
#include "font_manager.h"


class ColorManager
{

public:

    ColorManager()
    {
        m_current_index = 0;
        m_colors.resize (12);

        m_colors[0] = QColor::fromHsv (359, 255, 255);
        m_colors[1] = QColor::fromHsv (179, 230, 230);
        m_colors[2] = QColor::fromHsv (59, 255, 255);
        m_colors[3] = QColor::fromHsv (239, 255, 255);
        m_colors[4] = QColor::fromHsv (119, 255, 255);
        m_colors[5] = QColor::fromHsv (299, 255, 255);

        m_colors[6]  = QColor::fromHsv (149, 204, 204);
        m_colors[7]  = QColor::fromHsv (29, 204, 204);
        m_colors[8]  = QColor::fromHsv (209, 204, 204);
        m_colors[9]  = QColor::fromHsv (89, 204, 204);
        m_colors[10] = QColor::fromHsv (269, 204, 204);
        m_colors[11] = QColor::fromHsv (329, 255, 153);
    }

    const QColor &nextColor()
    {
        int index = m_current_index;
        m_current_index++;
        if (m_current_index >= m_colors.size()) {
            m_current_index = 0;
        }
        return m_colors[index];
    }


private:

    int m_current_index;
    QVector< QColor > m_colors;
};


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow (QWidget *parent = nullptr);
    ~MainWindow();

signals:

    void blockParams (bool);

public slots:

private slots:

    void clearAll();
    void filterStart (FILTER_TYPE ftype, FILTER_ID id, APPROX_TYPE atype);
    void taskChanged (TASK_ID id);
    void filterUpdatePercent (int p);


protected:
    void closeEvent (QCloseEvent *);

private:
    TASK_ID m_taskId;
    ColorManager *m_colorManager;
    int m_randSeed;

    QProgressBar *m_statusProgressBar;
    GraphWindow *m_graphWindow;
    TaskWidget *m_taskWidget;
    FilterParametersWidget *m_filterParamsWidget;
    FilterStartButtonsBox *m_filterStartWidget;
    QPushButton *m_btnClear;

    void initControls();
    void initLayouts();
    void initStatusBar();
    void loadFonts();
    void initGraphWindow();
    void showData (Filters::Filter *filter, const QColor &color);
};

#endif  // MAINWINDOW_H
