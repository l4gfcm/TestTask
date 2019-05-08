#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);

}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::setData(dataItem& item){
    ui->NameLineEdit->setText(item.name);
    ui->surNameLineEdit->setText(item.surName);
    ui->dateEdit->setDate(item.birthDay);
    ui->emailLineEdit->setText(item.email);
}

dataItem EditDialog::getData(){
    dataItem result;
    result.name = ui->NameLineEdit->text();
    result.surName = ui->NameLineEdit->text();
    result.birthDay = ui->dateEdit->date();
    result.email = ui->emailLineEdit->text();
    return result;
}
