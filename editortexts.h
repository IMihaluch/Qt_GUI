#ifndef EDITORTEXTS_H
#define EDITORTEXTS_H
#include <QtWidgets>
#include <QtGui>
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QMdiArea>
#include "settings.h"

class EditorTexts : public QMainWindow
{
    Q_OBJECT
public:
    explicit EditorTexts(QWidget *parent = nullptr);

private:

void closeEvent(QCloseEvent * event) override;
void inline createButton();
void inline createMenu();

    QWidget *centralWgt {nullptr};
    QGridLayout *mainGrid {nullptr}; 
    QToolButton *but_Open {nullptr};
    QAction *openread_A {nullptr};
    QPushButton *but_Save {nullptr};
    QPushButton *but_Help {nullptr};
    QPushButton *but_Settings {nullptr};
    QPushButton *but_Print {nullptr};

    QPushButton *action_TextSelect {nullptr};
    QPushButton *action_TextFormat {nullptr};
    QPushButton *action_TextLeft {nullptr};
    QPushButton *action_TextCentre {nullptr};
    QPushButton *action_TextRight {nullptr};




    Settings *setting {nullptr};
    QMenuBar *menu_bar {nullptr};
    QMenu *file_menu {nullptr};
    QMenu *edit_menu {nullptr};
    QMenu *help_menu {nullptr};

    QToolBar *file_ToolBar {nullptr};
    QToolBar *format_TextToolBar {nullptr};
    QToolBar *about_ToolBar {nullptr};


    QAction *action_Create {nullptr};
    QAction *action_Open {nullptr};
    QAction *action_Save {nullptr};
    QAction *action_Print {nullptr};
    QAction *action_Exit {nullptr};
    QAction *action_Setings {nullptr};
    QAction *action_add_DateTime {nullptr};
    QAction *action_Help {nullptr};

    unsigned int modOpen , modSave, modClear, modExit;
    int open, save, clear, exit;

    QTabWidget *tab_A {nullptr};

    bool setOnlyReadText = false;


    QMessageBox *m_Exit {nullptr};
    QPushButton *Ok {nullptr};
    QPushButton *Cancel {nullptr};
    QMessageBox *m_TabClose {nullptr};
    QPushButton *Ok_Close {nullptr};
    QPushButton *Cancel_Close {nullptr};

    QFont m_font;
    QTextCharFormat m_fmt;
    bool isCopyTextFormat = false;
    bool processSelected = false;

    protected:

 virtual void keyPressEvent(QKeyEvent *event) override;

signals:

public slots:
    void on_but_Open_clicked();
    void on_but_Save_clicked();
    void on_but_Help_clicked();
    void on_but_Settings_clicked();
    void on_but_OpenOnlyRead_clicked();
    void on_but_CreateNew_clicked();
    void on_but_Insert_DateTime_clicked(); 

    void retranslateUI();
    void redrawUI(QString _qss, QPalette _palette);

    void switch_HKeyOpen(unsigned int _mod, int _key);
    void switch_HKeySave(unsigned int _mod, int _key);
    void switch_HKeyClear(unsigned int _mod, int _key);
    void switch_HKeyExit(unsigned int _mod, int _key);
    void on_action_Print_clicked();
    void changeTab_A();
    void closeTab_A(int _tab);

    void plan_TexteChange();
    void plan_SelectChange(bool select);
    void plan_MoveCursor();

    void on_action_TextSelect_clicked();
    void on_action_TextFormat_clicked();
    void on_action_TextLeft_clicked();
    void on_action_TextCentre_clicked();
    void on_action_TextRight_clicked();
   };

#endif // EDITORTEXTS_H
