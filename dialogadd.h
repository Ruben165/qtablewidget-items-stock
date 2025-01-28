#ifndef DIALOGADD_H
#define DIALOGADD_H

#include "ui_dialogadd.h"

class DialogAdd : public QDialog, public Ui::DialogAdd
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr);
private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOGADD_H
// By: 2540124633 - Lie Reubensto
