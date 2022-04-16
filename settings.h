#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = nullptr);
    QString getQss();
    QVector<unsigned int> getHotkey();

private:
        QGridLayout *mainGrid;
        QCheckBox *checkLanguage;
        QLabel *labelLanguage;
        QPalette palette;
        QString qss;

QTranslator *translator;

        QLabel *labelOpen;
        QLineEdit *editOpen;
        QLabel *labelSave;
        QLineEdit *editSave;
        QLabel *labelClear;
        QLineEdit *editClear;
        QLabel *labelExit;
        QLineEdit *editExit;

        int open, save, clear, exit, key;
        unsigned int mod, modOpen, modSave, modClear, modExit;
        bool changeOpen, changeSave, changeClear, changeExit;

        QString getNameKey(int _key);

protected:
        virtual void keyPressEvent(QKeyEvent *event) override;
signals:
        void retranslate();
        void redraw(QString, QPalette);
        void com_changeOpen(unsigned int,int);
        void com_changeSave(unsigned int,int);
        void com_changeClear(unsigned int,int);
        void com_changeExit(unsigned int,int);

public slots:
        void on_checkLanguage_clicked();
        void retranslateUI();
        void redrawUI(QString _qss, QPalette _palette);
        void editOpen_onTextEdit();
        void editSave_onTextEdit();
        void editClear_onTextEdit();
        void editExit_onTextEdit();
};

#endif // SETTINGS_H
