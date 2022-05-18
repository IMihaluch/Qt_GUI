#include "editortexts.h"
#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // Устанавливаем/выбираем стиль всего окна
    //a.setStyle(QStyleFactory::create("windows"));
    a.setStyle(QStyleFactory::create("fusion"));
    //a.setStyle(QStyleFactory::create("macintosh"));
    //a.setStyle(QStyleFactory::create("windowsvista"));
    //a.setStyle(QStyleFactory::create("plastique"));
    a.setWindowIcon(QIcon(":/Icons/main.png"));

    EditorTexts w;
    w.setMinimumHeight(200);
    w.setMinimumWidth(300);
    w.show();

    return a.exec();
}
