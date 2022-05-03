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
    QWidget *centralWgt {nullptr};
    QGridLayout *mainGrid {nullptr}; 
    QToolButton *but_Open {nullptr};
    QAction *openread_A {nullptr};
    QPushButton *but_Save {nullptr};
    QPushButton *but_Help {nullptr};
    QPushButton *but_Settings {nullptr};
    QPushButton *but_Print {nullptr};


   
    Settings *setting {nullptr};
    QMenuBar *M_bar {nullptr};
    QMenu *file_M {nullptr};
    QMenu *edit_M {nullptr};
    QMenu *help_M {nullptr};
    QAction *action_Create {nullptr};
    QAction *action_Open {nullptr};
    QAction *action_Save {nullptr};
    QAction *action_Print {nullptr};
    QAction *action_Exit {nullptr};
    QAction *action_Setings {nullptr};
    QAction *action_Help {nullptr};

    unsigned int modOpen , modSave, modClear, modExit;
    int open, save, clear, exit;

    QTabWidget *tab_A {nullptr};

    bool setOnlyReadText = false;

    void closeEvent(QCloseEvent * event) override;
    QMessageBox *m_Exit {nullptr};
    QPushButton *Y {nullptr};
    QPushButton *N {nullptr};
    QMessageBox *m_TabClose {nullptr};
    QPushButton *Y_Close {nullptr};
    QPushButton *N_Close {nullptr};

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

    void retranslateUI();
    void redrawUI(QString _qss, QPalette _palette);
    void swtHotKeyOpen(unsigned int _mod, int _key);
    void swtHotKeySave(unsigned int _mod, int _key);
    void swtHotKeyClear(unsigned int _mod, int _key);
    void swtHotKeyExit(unsigned int _mod, int _key);
    void on_actionFilePrint_clicked();
    void changeTab_A();
    void closeTab_A(int _tab);
    void planTexteChange();
   };

#endif // EDITORTEXTS_H
