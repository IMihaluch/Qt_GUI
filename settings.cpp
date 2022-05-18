#include "settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent)
{
    mainGrid = new QGridLayout(this);

    checkLanguage = new QCheckBox(this);
    labelLanguage = new QLabel(this);

    labelOpen = new QLabel(this);
    editOpen = new QLineEdit(this);
    labelSave = new QLabel(this);
    editSave = new QLineEdit(this);
    labelClear = new QLabel(this);
    editClear = new QLineEdit(this);
    labelExit = new QLabel(this);
    editExit = new QLineEdit(this);

qss = "QWidget{""background-color: hsl(0,0%,50%);""}"
                  "QPlainTextEdit{""background-color: hsl(0,0%,100%);""border-color: hsl(240,100%,50%);""border: 5px solid hsl(240,100%,50%);""}"
                  "QPushButton{""border-radius: 00px;""background-color: hsl(0,0%,50%);""qproperty-iconSize: 30px 30px;""}"
                  "QPushButton:pressed{"" border-radius: 10px;""background-color: hsl(240,100%,50%);""}";

palette = style()->standardPalette();

    editOpen->setText("Ctrl+O");
    editOpen->setReadOnly(true);
    editSave->setText("Ctrl+S");
    editSave->setReadOnly(true);
    editClear->setText("Ctrl+X");
    editClear->setReadOnly(true);
    editExit->setText("Ctrl+N");
    editExit->setReadOnly(true);

    connect(labelLanguage, SIGNAL(clicked()), this, SLOT(on_labelLanguage_clicked()));
    connect(editOpen,SIGNAL(selectionChanged()),this,SLOT(editOpen_onTextEdit()));
    connect(editSave,SIGNAL(selectionChanged()),this,SLOT(editSave_onTextEdit()));
    connect(editClear,SIGNAL(selectionChanged()),this,SLOT(editClear_onTextEdit()));
    connect(editExit,SIGNAL(selectionChanged()),this,SLOT(editExit_onTextEdit()));

    mainGrid->addWidget(checklLanguage, 1, 1);
    mainGrid->addWidget(labelLanguage, 1, 0);
    mainGrid->addWidget(labelOpen, 2, 0);
    mainGrid->addWidget(editOpen, 2, 1);
    mainGrid->addWidget(labelSave, 3, 0);
    mainGrid->addWidget(editSave, 3, 1);
    mainGrid->addWidget(labelClear, 4, 0);
    mainGrid->addWidget(editClear, 4, 1);
    mainGrid->addWidget(labelExit, 5, 0);
    mainGrid->addWidget(editExit, 5, 1);

    qApp->setPalette(palette);
    this->setStyleSheet(getQss());

    this->setLayout(mainGrid);

    open = Qt::Key_O;
    modOpen = Qt::ControlModifier;
    save = Qt::Key_S;
    modSave = Qt::ControlModifier;
    clear = Qt::Key_X;
    modClear = Qt::ControlModifier;
    exit = Qt::Key_N;
    modExit = Qt::ControlModifier;

    retranslateUI();
    redrawUI(qss, palette);
}

QVector<unsigned int> Settings::getHotkey()
{
    QVector<unsigned int> hotkeys;
    hotkeys.append(modOpen);
    hotkeys.append(static_cast<unsigned int>(open));
    hotkeys.append(modSave);
    hotkeys.append(static_cast<unsigned int>(save));
    hotkeys.append(modClear);
    hotkeys.append(static_cast<unsigned int>(clear));
    hotkeys.append(modExit);
    hotkeys.append(static_cast<unsigned int>(exit));
    return hotkeys;
}

QString Settings::getNameKey(int _key)
{
  switch (_key)
 {
    case Qt::ControlModifier: return "Ctrl";
    case Qt::Key_A: return "A";
    case Qt::Key_B: return "B";
    case Qt::Key_C: return "C";
    case Qt::Key_D: return "D";
    case Qt::Key_E: return "E";
    case Qt::Key_F: return "F";
    case Qt::Key_G: return "G";
    case Qt::Key_H: return "H";
    case Qt::Key_I: return "I";
    case Qt::Key_J: return "J";
    case Qt::Key_K: return "K";
    case Qt::Key_L: return "L";
    case Qt::Key_M: return "M";
    case Qt::Key_N: return "N";
    case Qt::Key_O: return "O";
    case Qt::Key_P: return "P";
    case Qt::Key_Q: return "Q";
    case Qt::Key_R: return "R";
    case Qt::Key_S: return "S";
    case Qt::Key_T: return "T";
    case Qt::Key_U: return "U";
    case Qt::Key_V: return "V";
    case Qt::Key_W: return "W";
    case Qt::Key_X: return "X";
    case Qt::Key_Y: return "Y";
    case Qt::Key_Z: return "Z";
    case Qt::Key_1: return "1";
    case Qt::Key_2: return "2";
    case Qt::Key_3: return "3";
    case Qt::Key_4: return "4";
    case Qt::Key_5: return "5";
    case Qt::Key_6: return "6";
    case Qt::Key_7: return "7";
    case Qt::Key_8: return "8";
    case Qt::Key_9: return "9";
    case Qt::Key_0: return "0";
    case Qt::Key_F1: return "F1";
    case Qt::Key_F2: return "F2";
    case Qt::Key_F3: return "F3";
    case Qt::Key_F4: return "F4";
    case Qt::Key_F5: return "F5";
    case Qt::Key_F6: return "F6";
    case Qt::Key_F7: return "F7";
    case Qt::Key_F8: return "F8";
    case Qt::Key_F9: return "F9";
    case Qt::Key_F10: return "F10";
    case Qt::Key_F11: return "F11";
    case Qt::Key_F12: return "F12";
    default: return "";
    }
}

void Settings::keyPressEvent(QKeyEvent *event)
{
    mod = event->modifiers();
    key = event->key();
    if(changeOpen){ 
        if(mod!= 0 && modOpen == 0) {
            editOpen->setText(getNameKey(static_cast<int>(mod))+ "+");
            modOpen = mod;
        }
        else {
            open = key;
            changeOpen = false;
            editOpen->setStyleSheet("");
            qDebug();
            emit com_changeOpen(modOpen,open);
            editOpen->setText((modOpen!= 0)?(editOpen->text() + getNameKey(key)):(getNameKey(key)));
        }    
    }


    else if(changeSave){
        if(mod!= 0 && modSave == 0) {
            modSave = mod;
            editSave->setText(getNameKey(static_cast<int>(modSave))+ "+");
        }
        else {
            save = key;
            changeSave = false;
            editSave->setStyleSheet("");
            qDebug();
            emit com_changeSave(modSave,save);
            editSave->setText((modSave!= 0)?(editSave->text() + getNameKey(key)):(getNameKey(key)));
        }
    }


    else if(changeClear){
        if(mod!= 0 && modClear == 0) {
            modClear = mod;
            leClear->setText(getNameKey(static_cast<int>(modClear))+ "+");
        }
        else {
             clear = key;
            changeClear = false;
            editClear->setStyleSheet("");
            qDebug();
            emit com_changeClear(modClear,clear);
            editClear->setText((modClear!= 0)?(editClear->text() + getNameKey(key)):(getNameKey(key)));
        }
    }


    else if(changeExit){
        if(mod!= 0 && modExit == 0) {
            modExit = modify;
            editExit->setText(getNameKey(static_cast<int>(modExit))+ "+");
        }
        else {
            exit = key;
            changeExit = false;
            editExit->setStyleSheet("");
            qDebug();
            emit com_changeExit(modExit,exit);
            editExit->setText((modExit!= 0)?(editExit->text() + getNameKey(key)):(getNameKey(key)));
        }
    }
}

void Settings::on_checkLanguage_clicked() {
    if (checkLanguage->isChecked())
{
        translator = new QTranslator(this);
        static_cast<void>(translator->load(":/translator/RU_in.qm"));
        qApp->installTranslator(translator);
        emit retranslate();
    }
    else{
        delete translator;
        emit retranslate();
    }
}

void Settings::retranslateUI()
 {
    labelLanguage->setText(tr("Set Russian Language"));
    this->setWindowTitle(tr("Settings"));

    labelOpen->setText(tr("Hot Key \"Open\""));
    labelSave->setText(tr("Hot Key \"Save\""));
    labelClear->setText(tr("Hot Key \"Clear Text Editor\""));
    labelExit->setText(tr("Hot Key \"Exit\""));
}

void Settings::redrawUI(QString _qss, QPalette _palette) {
    this->setStyleSheet(_qss);
    this->setPalette(_palette);
}

void Settings::editOpen_onTextEdit()
{
    qDebug() << "Открыть";
    modOpen = open = 0;
    changeOpen = true;
    changeClear = changeSave = changeExit = false;
    editOpen->setStyleSheet("background-color: hsl(240,100%,50%)");
    editSave->setStyleSheet("");
    editClear->setStyleSheet("");
    editExit->setStyleSheet("");
}

void Settings::editSave_onTextEdit()
{
    qDebug() << "Cохранить";
    modSave = save = 0;
    changeSave = true;
    changeExit =  false;
    changeOpen =  false;
    modClear =  false;
    editSave->setStyleSheet("background-color: hsl(240,100%,50%)");
    editOpen->setStyleSheet("");
    editClear->setStyleSheet("");
    editExit->setStyleSheet("");
}

void Settings::editClear_onTextEdit()
{
    qDebug() << "Очистить";
    modClear = clear = 0;
    changeClear = true;
    changeOpen = changeSave = changeExit = false;
    editClear->setStyleSheet("background-color: hsl(240,100%,50%)");
    editOpen->setStyleSheet("");
    editSave->setStyleSheet("");
    editExit->setStyleSheet("");
}

void Settings::editExit_onTextEdit()
{
    qDebug() << "Выход";
    modExit = exit = 0;
    changeExit = true;
    changeOpen = changeSave = changeClear = false;
    editExit->setStyleSheet("background-color: hsl(240,100%,50%)");
    editOpen->setStyleSheet("");
    editSave->setStyleSheet("");
    editClear->setStyleSheet("");
}

