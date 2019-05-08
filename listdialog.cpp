#include "listdialog.h"
#include "ui_listdialog.h"
#include "QFileDialog"


ListDialog::ListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListDialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeOut()));
    timer->start(1000 * 30);
}

ListDialog::~ListDialog()
{
    delete ui;
}

void ListDialog::timeOut(){
    if(ui->checkBox->isChecked()){
        ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
        return;
    }
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item = dataItem(ui->listWidget->item(i)->text());
        if(!item.isGood())
            delete ui->listWidget->takeItem(i);
    }
}

void ListDialog::on_LoadButton_clicked()
{
     fileName = QFileDialog::getOpenFileName(this, "Open File", "data.txt");
     std::ifstream dataFile(fileName.toStdString());
     if(!dataFile.is_open()){
         QMessageBox::warning(this, "App", "File is don`t opened");
         return;
     }
     dataItem tempItem;
     while(dataFile >> tempItem){
         if(tempItem.isGood())
             ui->listWidget->addItem(tempItem.toString());
     }
}

void ListDialog::on_ExitButton_clicked()
{
    QApplication::exit();
}

void ListDialog::on_DeleteButton_clicked()
{

    foreach (QListWidgetItem *NAME, ui->listWidget->selectedItems()) {
       delete ui->listWidget->takeItem(ui->listWidget->row(NAME));
    }

}



void ListDialog::on_InsertButton_clicked()
{
    EditDialog edit(this);
    if(edit.exec() == QDialog::Accepted){
        dataItem item(edit.getData().toString());
        ui->listWidget->insertItem(ui->listWidget->currentRow() + 1, item.toString());
    }
}

void ListDialog::on_SaveButton_clicked()
{
    std::ofstream dataFile(fileName.toStdString());
    if(!dataFile.is_open()){
        QMessageBox::warning(this, "App", "Error of writing the File.");
    }

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        auto item = dataItem(ui->listWidget->item(i)->text());
        if(item.isGood())
            dataFile << item;
    }

    dataFile.flush();
}


void ListDialog::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    auto currentEditableItem = dataItem(item->text());
    EditDialog edit(this);
    edit.setData(currentEditableItem);
    if(edit.exec() == QDialog::Accepted)
        item->setText(edit.getData().toString());
}
