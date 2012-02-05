#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "windows.h"
#include "stdlib.h"
#include <QThread>
#include <QLibrary>
#include <QListWidget>
#include <upfire_dll_coff.h>
#include <select_rule.h>
#include <QSettings>

#define PID_PROCESS 1
#define NAME_PROCESS 2
#define NAME_PID 3


// Packet filter definitions from DDK
#define NDIS_PACKET_TYPE_DIRECTED         0x00000001
#define NDIS_PACKET_TYPE_MULTICAST				0x00000002
#define NDIS_PACKET_TYPE_ALL_MULTICAST    0x00000004
#define NDIS_PACKET_TYPE_BROADCAST				0x00000008
#define NDIS_PACKET_TYPE_SOURCE_ROUTING   0x00000010
#define NDIS_PACKET_TYPE_PROMISCUOUS      0x00000020
#define NDIS_PACKET_TYPE_SMT              0x00000040
#define NDIS_PACKET_TYPE_ALL_LOCAL				0x00000080
#define NDIS_PACKET_TYPE_GROUP            0x00001000
#define NDIS_PACKET_TYPE_ALL_FUNCTIONAL   0x00002000
#define NDIS_PACKET_TYPE_FUNCTIONAL				0x00004000
#define NDIS_PACKET_TYPE_MAC_FRAME				0x00008000
#define _WIN32_WINNT 0x0501

#include <QMainWindow>
#include <QTableWidgetItem>
typedef long (__stdcall *prot_set_filter)(void*);

// эта функция вызывается для каждого процесса в перечислении
typedef BOOL (CALLBACK * PFNENUMPROC)(
  IN DWORD dwProcessId,	    // идентификатор процесса
  IN LPCTSTR pszProcessName,  // имя процесса; NULL, если недоступно
  IN LPARAM lParam	    // пользовательский параметр
  );

namespace Ui {
    class MainWindow;
}

extern CWall                      *wall;
int                                chk_rez (int err);
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    
    long                        set_item_value(QTableWidget *p_table,
                                               char *item_value,
                                               int row,
                                               int col);
    long                        set_item_value(QTableWidget *p_table,
                                               char *item_value,
                                               int row,
                                               int col,
                                               QString mask);
    long                        set_table_header(char *row_col,
                                                 QTableWidget *p_table,
                                                 char *header_name,
                                                 int number);

    QMenu                      *menMain;    

    int                         add_item_menu(QListWidget *name_Menu,
                                              char *name_icon,
                                              char *text_item);
    select_rule                *sr;
    QList< QList<CFiltr> >      rule_lst;
    long                        set_rule(int       *Numb_Rule,
                                         QString   *Name_Rule,
                                         int       *Size_Rule,
                                         byte      *enabled,
                                         QSettings *Settings
                                         );
    long                        show_enable_rules(
                                         int Size_Of_Wall);
    long                        check_uniq_rule (CRule *rules_lst,
                                                 char *name_of_rule);
    int                         Get_Proc_List(QStringList * slProc,
                                                  int return_param);// 1 - PID, 2 - Name
    int                         get_opens_port(QStringList * strlst, char * Name);

private:
    Ui::MainWindow *ui;

public slots:
    void load_settings();
    void save_settings();
    void SLOT_choose_rule(int Number_of_Rule);

private slots:    
    void on_lst_Menu_clicked(const QModelIndex &index);
    void on_btnNotDefend_clicked();
    void on_btnEnableDfnd_clicked();
    void on_btnAll_Defend_clicked();
    void on_btn_AddRule_clicked();
    void on_btn_DeleteRule_clicked();   
};
#endif // MAINWINDOW_H
