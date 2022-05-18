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
    QPalette getPalette();

private:
        QGridLayout *mainGrid {nullptr};
        QCheckBox *checkLanguage {nullptr};
        QLabel *labelLanguage {nullptr};
        QPalette palette;
        QString qss;

QTranslator *translator {nullptr};
QTranslator *translatorStandart {nullptr};

        QLabel *labelOpen {nullptr};
        QLineEdit *editOpen {nullptr};
        QLabel *labelSave {nullptr};
        QLineEdit *editSave {nullptr};
        QLabel *labelClear {nullptr};
        QLineEdit *editClear {nullptr};
        QLabel *labelExit {nullptr};
        QLineEdit *editExit {nullptr};

        int open, save, clear, exit, key;
        unsigned int mod, modOpen, modSave, modClear, modExit;
        bool changeOpen, changeSave, changeClear, changeExit;

        QString getNameKey(int _key);

protected:
        virtual void keyPressEvent(QKeyEvent *event) override;
signals:
        void retranslate();
        void redraw(QString, QPalette);
        void changeOpen(unsigned int,int);
        void changeSave(unsigned int,int);
        void changeClear(unsigned int,int);
        void changeExit(unsigned int,int);

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
