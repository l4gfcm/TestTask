#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include <fstream>
#include <QMessageBox>
#include <iostream>
#include <sstream>
#include <QListWidgetItem>
#include "dataitem.h"
#include "editdialog.h"
namespace Ui {
class ListDialog;
}

class ListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ListDialog(QWidget *parent = nullptr);
    ~ListDialog();


private slots:
    void on_LoadButton_clicked();

    void on_ExitButton_clicked();

    void on_DeleteButton_clicked();


    void on_InsertButton_clicked();

    void on_SaveButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void timeOut();

private:
    Ui::ListDialog *ui;
    QString fileName;
    QTimer* timer;
};

#endif // LISTDIALOG_H
