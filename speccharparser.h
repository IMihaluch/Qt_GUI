#ifndef SPECCHARPARSER_H
#define SPECCHARPARSER_H

#include <QString>

class  speccharParser
{
public:
    speccharParser();
    bool removeQStr(QString m_str); 
    QString getQStr();
private:
    QString str;
    bool isAssig;
    int pos;
    static const int SPEC_CHARSES = 5;
    QString arString[SPEC_CHARSES] = {"#@CR", "#@PRO", "#@RS", "#@EUR", "#@RUB"};
    QString arSymbol[SPEC_CHARSES] = {"©", "‰", "®", "€", "₽"};
};

#endif // SPECCHARPARSER_H
