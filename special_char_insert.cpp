#include " special_char_insert.h"

special_char_insert::special_char_insert(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);
    plane1 = new QPlainTextEdit(this);
    speccharParser = new speccharParser;
    condition = new QLabel(this);
    condition->setWordWrap(true);
    condition->setText("Replaces the text, introduced: \n"
                  " #@CR = © — copyright protection mark,\n"
                  " #@PRO = ‰ — promile,\n"
                  " #@RS = ® - the mark of a registered trademark,\n "
                  " #@EUR = € —euro,\n"
                  " #@RUB = ₽ — ruble");

    mainGrid->addWidget(condition, 0 ,0);
    mainGrid->addWidget(plane1, 1, 0);

    this->setLayout(mainGrid);
    this->setWindowTitle("Transformation");

    connect(plane1, SIGNAL(textAssig()), this, SLOT(on_plainTextEdit_textAssig()));
}

void special_char_insert::on_plainTextEdit_textAssig(){
    if (speccharParser->removeQStr(plane1->toPlainText())){ 
        plane1->setPlainText(speccharParser->getQStr());
        QTextCursor cursor = plane1->textCursor();
        cursor.setPosition(int(speccharParser->getQStr().size()));
        plane1->setTextCursor(cursor);
    }
}
