#include "speccharparser.h"
#include <QMessageBox>

speccharParser::speccharParser()
{
    str = "";
}

bool speccharParser::removeQStr(QString m_str){
    str = m_str;
    isAssig = false;
    for (int i = 0; i < SPEC_CHARSES; i++) {
        pos = int(str.indexOf(arString[i], 0));
        if(pos != -1){
            str.replace(pos,arString[i].size(),arSymbol[i]);
            isAssig = true;
}
    }
    return isAssig;
}

QString speccharParser::getQStr(){
    return str;
}
