#include "dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    this->lineEditKode->setFocus(Qt::OtherFocusReason);
}

void DialogAdd::on_buttonBox_accepted() {
    if(lineEditKode->text().length()>0 && lineEditNama->text().length()>0 && lineEditHargaSatuan->text().length()>0 && lineEditJumlah->text().length()>0) {
        accept();
    }
}

// By: 2540124633 - Lie Reubensto
