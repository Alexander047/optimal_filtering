#ifndef TASK_WIDGET_H
#define TASK_WIDGET_H

#include <QGroupBox>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "Filters/filter_factory.h"


class TaskWidget : public QGroupBox
{
    Q_OBJECT

public:

    explicit TaskWidget (QWidget *parent = nullptr);
    ~TaskWidget();

    TASK_ID taskId() const
    {
        return m_taskId;
    }

    QString taskName() const;


signals:

    void taskChanged (TASK_ID id);


public slots:

    void clearAll();


private slots:

    void cbTaskChanged (int index);
    void btnSpecificParametersClicked();


private:

    QComboBox *m_cbTask;
    QPushButton *m_btnSpecificParameters;
    bool m_specParamsWindowHidden;

    TASK_ID m_taskId;
    void loadFonts();
    void initControls();
    void initLayouts();
};

#endif  // TASK_WIDGET_H
