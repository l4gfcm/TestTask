#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QTimer>
#include "dataitem.h"
namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();
    void setData(dataItem&);
    dataItem getData();

private:
    Ui::EditDialog *ui;
    dataItem data;
};

#endif // EDITDIALOG_H
