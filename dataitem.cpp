#include "dataitem.h"


dataItem::dataItem(QString stringItemtem)
{
    std::stringstream ss;
    ss << stringItemtem.toStdString();

    std::string sName;
    ss >> sName;
    name = QString::fromStdString(sName);

    std::string sSurName;
    ss >> sSurName;
    surName = QString::fromStdString(sSurName);

    std::string sDate;
    ss >> sDate;
    birthDay = QDate::fromString(QString::fromStdString(sDate), "yyyy/MM/dd");

    std::string sEmail;
    ss >> sEmail;
    email = QString::fromStdString(sEmail);

}

bool dataItem::isGood(){
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);
    bool regMat = mailREX.exactMatch(email);

    bool isValidDate = !birthDay.isNull();
    return regMat && isValidDate;
}

QString dataItem::toString(){
    std::stringstream ss;
    ss << name.toStdString() << " " << surName.toStdString() << " "
              << birthDay.toString("yyyy/MM/dd").toStdString() << " " << email.toStdString() << std::endl;
    return QString::fromStdString(ss.str());
}



std::istream& operator>>(std::istream& inStream, dataItem& item){
    std::string sName;
    inStream >> sName;
    item.name = QString::fromStdString(sName);

    std::string sSurName;
    inStream >> sSurName;
    item.surName = QString::fromStdString(sSurName);

    std::string date;
    inStream >> date;
    item.birthDay = QDate::fromString(QString::fromStdString(date), "yyyy/MM/dd");

    std::string sEmail;
    inStream >> sEmail;
    item.email = QString::fromStdString(sEmail);


    return inStream;
}

std::ostream& operator<<(std::ostream& outStream, const dataItem& item){

    outStream << item.name.toStdString() << " " << item.surName.toStdString() << " "
              << item.birthDay.toString("yyyy/MM/dd").toStdString() << " " << item.email.toStdString() << std::endl;
    return outStream;
}

