#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addTableWidgetRow(const QString& kode, const QString& nama, const QString& hargaSatuan, const QString& jumlah);
    void InitTableWidget();
    ~MainWindow();

private slots:
    void on_actionAdd_triggered();
    void on_actionDelete_triggered();
    void on_tableWidgetMain_cellDoubleClicked(int row, int column);
};
#endif // MAINWINDOW_H
// By: 2540124633 - Lie Reubensto
