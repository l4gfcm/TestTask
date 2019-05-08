#ifndef DATAITEM_H
#define DATAITEM_H
#include <QString>
#include <QDate>
#include <iostream>
#include <sstream>



class dataItem
{
public:
    dataItem() = default;
    explicit dataItem(QString stringItemtem);
    bool isGood();
    QString toString();
    friend std::ostream& operator<<(std::ostream& outStream, const dataItem& item);
    friend std::istream& operator>>(std::istream& inStream, dataItem& item);

    QString name;
    QString surName;
    QDate birthDay;
    QString email;
};

#endif // DATAITEM_H
