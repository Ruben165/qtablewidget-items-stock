#include "mainwindow.h"
#include <QMessageBox>
#include <QTableView>
#include "dialogadd.h"
#include <QInputDialog>

void MainWindow::addTableWidgetRow(const QString& kode, const QString& nama, const QString& hargaSatuan, const QString& jumlah)
{
    int nRowCount = tableWidgetMain->rowCount();
    tableWidgetMain->setRowCount(nRowCount+1);

    QTableWidgetItem kode_ = QTableWidgetItem(kode);
    kode_.setTextAlignment(Qt::AlignCenter);
    QFont font0 = kode_.font();
    font0.setBold(true);
    font0.setPointSize(11);
    kode_.setFont(font0);

    QTableWidgetItem nama_ = QTableWidgetItem(nama);
    nama_.setTextAlignment(Qt::AlignCenter);
    QFont font1 = nama_.font();
    font1.setBold(true);
    font1.setPointSize(11);
    nama_.setFont(font1);

    QTableWidgetItem hargaSatuan_ = QTableWidgetItem(hargaSatuan);
    hargaSatuan_.setTextAlignment(Qt::AlignCenter);
    QFont font2 = hargaSatuan_.font();
    font2.setBold(true);
    font2.setPointSize(11);
    hargaSatuan_.setFont(font2);

    QTableWidgetItem jumlah_ = QTableWidgetItem(jumlah);
    jumlah_.setTextAlignment(Qt::AlignCenter);
    QFont font3 = jumlah_.font();
    font3.setBold(true);
    font3.setPointSize(11);
    jumlah_.setFont(font3);

    tableWidgetMain->setItem(nRowCount, 0, new QTableWidgetItem(kode_));
    tableWidgetMain->setItem(nRowCount, 1, new QTableWidgetItem(nama_));
    tableWidgetMain->setItem(nRowCount, 2, new QTableWidgetItem(hargaSatuan_));
    tableWidgetMain->setItem(nRowCount, 3, new QTableWidgetItem(jumlah_));
}

void MainWindow::InitTableWidget() {
    QStringList tableHeader;
    tableHeader << "Kode" << "Nama" << "Harga Satuan" << "Jumlah";
    tableWidgetMain->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidgetMain->setColumnCount(4);
    tableWidgetMain->setHorizontalHeaderLabels(tableHeader);

    tableWidgetMain->setAlternatingRowColors(true);
    tableWidgetMain->setSelectionBehavior(QTableView::SelectRows);

    tableWidgetMain->horizontalHeader()->setStretchLastSection(true);
    tableWidgetMain->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidgetMain->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

    InitTableWidget();

    addTableWidgetRow("B001", "Indomie Goreng", "10", "3000");
    addTableWidgetRow("B002", "Gula Pasir 1kg", "5", "10000");
}

MainWindow::~MainWindow() {}

void MainWindow::on_actionAdd_triggered()
{
    DialogAdd da;

    if(da.exec() == QDialog::Accepted) {
        QString kode = da.lineEditKode->text();
        QString nama = da.lineEditNama->text();
        QString hargaSatuan = da.lineEditHargaSatuan->text();
        QString jumlah =  da.lineEditJumlah->text();
        addTableWidgetRow(kode, nama, hargaSatuan, jumlah);
        qDebug("Data berhasil diinput!");
    }
}


void MainWindow::on_actionDelete_triggered()
{
    bool ok;
    int i = QInputDialog::getInt(this, tr("Baris yang akan dihapus"), tr("# Baris"), 1, 1, tableWidgetMain->rowCount(), 1, &ok);
    if(ok) {
        tableWidgetMain->removeRow(i-1);
    }
}


void MainWindow::on_tableWidgetMain_cellDoubleClicked(int row, int column)
{
    QString str = QString("Apakah Anda ingin menghapus baris ke-%1 (di-klik di: kolom ke-%2)?").arg(row+1).arg(column+1);
    int ret = QMessageBox::warning(this, "Konfirmasi Hapus", str, QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel);
    if(ret==QMessageBox::Ok) {
        tableWidgetMain->removeRow(row);
    } else if(ret==QMessageBox::Cancel) {
        tableWidgetMain->clearSelection();
        tableWidgetMain->setCurrentCell(row-1, column-1);
    }
}

// By: 2540124633 - Lie Reubensto
