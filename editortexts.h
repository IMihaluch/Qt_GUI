#ifndef EDITORTEXTS_H
#define EDITORTEXTS_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include "settings.h"

class EditorTexts : public QWidget
{
    Q_OBJECT
public:
    explicit EditorTexts(QWidget *parent = nullptr);

private:
    QGridLayout *mainGrid; 
    QToolButton *but_Open;
    QAction *open_A;
    QAction *openread_A;
    QPushButton *but_Save;
    QPushButton *but_Help;
    QPushButton *but_Settings;


    QPlainTextEdit *Ed;
    Settings *setting;

    unsigned int modOpen , modSave, modClear, modExit;
    int open, save, clear, exit;

    protected:
    
 virtual void keyPressEvent(QKeyEvent *event) override;

signals:

public slots:
    void on_but_Open_clicked();
    void on_but_Save_clicked();
    void on_but_Help_clicked();
    void on_but_Settings_clicked();
    void on_but_OpenOnlyRead_clicked();
    void retranslateUI();
    void redrawUI(QString _qss, QPalette _palette);
    void switch_HKeyOpen(unsigned int _mod, int _key);
    void switch_HKeySave(unsigned int _mod, int _key);
    void switch_HKeyClear(unsigned int _mod, int _key);
    void switch_HKeyExit(unsigned int _mod, int _key);
   };

#endif // EDITORTEXTS_H
