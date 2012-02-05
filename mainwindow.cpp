#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_select_rule.h"
#include <conio.h>
#include <winsock2.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <QTextEdit>

#include <stdio.h>
#include <stdlib.h>

#include <tchar.h>
#include <Common.h>

#include <QHeaderView>
#include <QSettings>
#include <QWidget>

#include <QMainWindow>
#include <QStyleOption>
#include <QPainter>
#include <QLineEdit>
#include <iphlpapi.h>


#include <QList>
#include <tlhelp32.h>


#define MAX_PACKET_SIZE    0x10000
#define SIO_RCVALL         0x98000001


CWall                      *wall;

typedef struct _IPHeader
{
  unsigned char  verlen;   // версия и длина заголовка
  unsigned char  tos;      // тип сервиса
  unsigned short length;   // длина всего пакета
  unsigned short id;       // Id
  unsigned short offset;   // флаги и смещения
  unsigned char  ttl;      // время жизни
  unsigned char  protocol; // протокол
  unsigned short xsum;     // контрольная сумма
  unsigned long  src;      // IP-адрес отправителя
  unsigned long  dest;     // IP-адрес назначения
}IPHeader;

typedef struct _TMibTCPExRow
{
  DWORD dwState;
  DWORD dwLocalAddr;
  DWORD dwLocalPort;
  DWORD dwRemoteAddr;
  DWORD dwRemotePort;
  DWORD dwProcessID;
}TMibTCPExRow;

typedef struct _PTMibTCPExTable
{
  DWORD dwNumEntries;
  TMibTCPExRow Table[];
}TMibTCPExTable;

//TCP_AdapterList         AdList;
//DWORD                   iIndex;
//CNdisApi                api;
//BOOL                    bSetPromisc = FALSE;
//DWORD                   dwFilter = 0;
//HANDLE                  hEvent;
//ETH_REQUEST             Request;
//PSTATIC_FILTER_TABLE    pFilters = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  //GetExtendedTcpTable();

//  // Allocate table filters for 10 filters
//  DWORD dwTableSize = sizeof(STATIC_FILTER_TABLE) + sizeof(STATIC_FILTER)*9;
//  pFilters = (PSTATIC_FILTER_TABLE)malloc(dwTableSize);
//  memset (pFilters, 0, dwTableSize);

  menMain = menuBar()->addMenu(QString::fromLocal8Bit("Файл"));
  menMain->addAction(QString::fromLocal8Bit("&Открыть правила"),
                     this,
                     SLOT(load_settings()),
                     QKeySequence("CTRL+O")
                     );

  add_item_menu(ui->lst_Menu, (char *)":/icons/lock.png", (char *)"Состояние защиты");
  add_item_menu(ui->lst_Menu, (char *)":/icons/settings.png", (char *)"Настройки");
  add_item_menu(ui->lst_Menu, (char *)":/icons/exit.png", (char *)"Выход");


  ui->lst_Menu->setIconSize(QSize(100,100));

  ui->lst_Menu->setCurrentRow(0);
  ui->stc_WorkSpace->setCurrentIndex(0);

  wall = new CWall();

  MainWindow::on_btnNotDefend_clicked();

  load_settings();
}

MainWindow::~MainWindow()
{
  save_settings();
//  if (pUpfireDLL){
//    delete pUpfireDLL;
//  }
  delete ui;
}
//загрузка настроек приложения
void MainWindow::load_settings()
{

  QSettings settings("sett.ini",QSettings::IniFormat);
  restoreGeometry(settings.value("geom").toByteArray());
  restoreState(settings.value("state").toByteArray());
  resize(settings.value("size").toSize());  


  QString buf;
  QStringList name_rule_lst, size_rule_lst, enable_rule_lst;

  name_rule_lst = settings.value("name_rule_lst").toStringList();
  size_rule_lst = settings.value("size_rule_lst").toStringList();
  enable_rule_lst = settings.value("enable_rule_lst").toStringList();

  ui->btn_DeleteRule->setEnabled(ui->tbl_Rules->rowCount()>0);

  if (name_rule_lst.count() <1 || size_rule_lst.count() <1){
    return;
  }
  for(int i=0;i<settings.value("Size_of_Wall").toInt();i++){
    buf = size_rule_lst[i];
    int     size_of_rule = buf.toInt();

    QString name_of_rule = name_rule_lst[i];
    byte enabled = ((QString)enable_rule_lst[i]).toInt();
    set_rule(&i,
             &name_of_rule,
             &size_of_rule,
             &enabled,
             &settings);

    CRule *rul_list = wall->get_rule_lst();

    rul_list[i].set_Name_of_Rule(name_of_rule.toLocal8Bit().data());
  }
  show_enable_rules(settings.value("Size_of_Wall").toInt());
  wall->set_Size_Wall(settings.value("Size_of_Wall").toInt());  
}

long MainWindow:: set_rule(int       *Numb_Rule,
                           QString   *Name_Rule,
                           int       *Size_Rule,
                           byte      *enabled,
                           QSettings *Settings
              ){
    if (Numb_Rule == NULL || Name_Rule == NULL || Size_Rule == NULL || Settings == NULL){
      return -1;
    }

    for(int j=0;j<*Size_Rule;j++){
      char *buf_chr = (char*)malloc(1024);
      memset(buf_chr,0,1024);
      strcpy(buf_chr, Name_Rule->toLocal8Bit().data());
      QString key = QString("%1").arg(*Numb_Rule)   + "---" +
                    buf_chr                         + "---" +
                    QString("%1").arg(j)            + "---";      

      CFiltr *fltr_lst = wall->get_rule_lst()[*Numb_Rule].get_filtr_lst();

      IP ip_;
      ip_.TypeIP       = Settings->value(key+"IP.TypeIP").toInt();
      ip_.DestIP.ip1   = Settings->value(key+"IP.DestIP.ip1").toInt();
      ip_.DestIP.ip2   = Settings->value(key+"IP.DestIP.ip2").toInt();
      ip_.DestIP.ip3   = Settings->value(key+"IP.DestIP.ip3").toInt();
      ip_.DestIP.ip4   = Settings->value(key+"IP.DestIP.ip4").toInt();
      ip_.SourceIP.ip1 = Settings->value(key+"IP.SourceIP.ip1").toInt();
      ip_.SourceIP.ip2 = Settings->value(key+"IP.SourceIP.ip2").toInt();
      ip_.SourceIP.ip3 = Settings->value(key+"IP.SourceIP.ip3").toInt();
      ip_.SourceIP.ip4 = Settings->value(key+"IP.SourceIP.ip4").toInt();

      PORT port_;
      port_.TypePort      = Settings->value(key+"PORT.TypePort").toInt();
      port_.DestPortBegin = Settings->value(key+"PORT.DestPortBegin").toInt();
      port_.SourcePortEnd = Settings->value(key+"PORT.SourcePortEnd").toInt();

      PROTOCOL protocol_;
      protocol_.NumberProtocol = Settings->value(key+"PROTOCOL.NumberProtocol").toInt();

      fltr_lst[j].set_IP(&ip_);
      fltr_lst[j].set_Port(&port_);
      fltr_lst[j].set_protocol(&protocol_);
      fltr_lst[j].set_type_packet(Settings->value(key+"type_packet").toInt());
      fltr_lst[j].set_type_action(Settings->value(key+"type_action").toInt());
      fltr_lst[j].set_FiltrType  (Settings->value(key+"FiltrType").toInt());
      fltr_lst[j].set_Numb_Filtr (Settings->value(key+"Numb_Filtr").toInt());
      fltr_lst[j].set_Name_of_Process(Settings->value(key+"Name_of_Process").toString().toLocal8Bit().data());
      fltr_lst[j].set_PID_of_Process(Settings->value(key+"PID_of_Process").toInt());
    }    
    wall->get_rule_lst()[*Numb_Rule].set_Size_of_Rule(*Size_Rule);
    //wall->get_rule_lst()[*Numb_Rule].set_Numb_Rule(*Numb_Rule);
    wall->get_rule_lst()[*Numb_Rule].set_enable(*enabled);

    return (0);
}
long MainWindow::show_enable_rules(int Size_Of_Wall){
  if (Size_Of_Wall<0){
    return -1;
  }
  ui->tbl_Rules->clear();
  ui->tbl_Rules->setColumnCount(1);
  ui->tbl_Rules->setRowCount(0);
  for(int i=0;i<Size_Of_Wall;i++){
    if (wall->get_rule_lst()[i].get_enabled() == true){
      ui->tbl_Rules->setRowCount(ui->tbl_Rules->rowCount()+1);
      this->set_item_value(ui->tbl_Rules,
                           wall->get_rule_lst()[i].get_Name_of_Rule(),
                           ui->tbl_Rules->rowCount()-1,
                           0);
    }
  }
  ui->btn_DeleteRule->setEnabled(ui->tbl_Rules->rowCount()>0);
  ui->tbl_Rules->resizeColumnsToContents();
  return 0;
}

void MainWindow::save_settings()
{
  int       buf = -99;
  QString   key, value;
  QSettings settings("sett.ini",QSettings::IniFormat);

  settings.clear();
  settings.sync();

  QStringList name_rule_lst, size_rule_lst, enable_rule_lst;

  settings.setValue("geom",this->saveGeometry());
  settings.setValue("state",this->saveState());
  settings.setValue("size",this->size());

  buf = wall->get_Size_Wall();
  settings.setValue("Size_of_Wall", buf);

  for(int i=0;i<wall->get_Size_Wall();i++){
    CRule* rules = wall->get_rule_lst();
    QString str_name = QString::fromLocal8Bit((char*)rules[i].get_Name_of_Rule());
    name_rule_lst.append(str_name);
    size_rule_lst.append(QString("%1").arg(rules[i].get_Size_Rule()));
    enable_rule_lst.append(QString("%1").arg(rules[i].get_enabled()));

    for(int j=0;j<rules[i].get_Size_Rule();j++){
      key = QString("%1").arg(i)             + "---" +
            rules[i].get_Name_of_Rule()      + "---" +
            QString("%1").arg(j);
//            QString("%1").arg(rules[i].fltr_lst[j].Numb_Filtr);

      //--------------------ip
      CFiltr *fltr_lst = rules[i].get_filtr_lst();

      IP ip_;
      ip_ = *fltr_lst[j].get_IP();

      value = QString("%1").arg(fltr_lst[j].get_Type_IP());
      settings.setValue(key+"---IP.TypeIP", value);

      value = QString("%1").arg(ip_.DestIP.ip1);
      settings.setValue(key+"---IP.DestIP.ip1", value);

      value = QString("%1").arg(ip_.DestIP.ip2);
      settings.setValue(key+"---IP.DestIP.ip2", value);

      value = QString("%1").arg(ip_.DestIP.ip3);
      settings.setValue(key+"---IP.DestIP.ip3", value);

      value = QString("%1").arg(ip_.DestIP.ip4);
      settings.setValue(key+"---IP.DestIP.ip4", value);


      value = QString("%1").arg(ip_.SourceIP.ip1);
      settings.setValue(key+"---IP.SourceIP.ip1", value);

      value = QString("%1").arg(ip_.SourceIP.ip2);
      settings.setValue(key+"---IP.SourceIP.ip2", value);

      value = QString("%1").arg(ip_.SourceIP.ip3);
      settings.setValue(key+"---IP.SourceIP.ip3", value);

      value = QString("%1").arg(ip_.SourceIP.ip4);
      settings.setValue(key+"---IP.SourceIP.ip4", value);


      //--------------------port      
      PORT port_;
      port_ = *fltr_lst[j].get_Port();
      value = QString("%1").arg(port_.TypePort);
      settings.setValue(key+"---PORT.TypePort", value);

      value = QString("%1").arg(port_.DestPortBegin);
      settings.setValue(key+"---PORT.DestPortBegin", value);

      value = QString("%1").arg(port_.DestPortEnd);
      settings.setValue(key+"---PORT.DestPortEnd", value);

      value = QString("%1").arg(port_.SourcePortBegin);
      settings.setValue(key+"---PORT.SourcePortBegin", value);

      value = QString("%1").arg(port_.SourcePortEnd);
      settings.setValue(key+"---PORT.SourcePortEnd", value);

      //--------------------protocol

      PROTOCOL prot_;
      prot_ = *fltr_lst[j].get_Protocol();
      value = QString("%1").arg(prot_.NumberProtocol);
      settings.setValue(key+"---PROTOCOL.NumberProtocol", value);


      //--------------------type_packet
      value = QString("%1").arg(fltr_lst[j].get_type_packet());
      settings.setValue(key+"---type_packet", value);

      //--------------------FiltrType
      value = QString("%1").arg(fltr_lst[j].get_FiltrType());
      settings.setValue(key+"---FiltrType", value);

      //--------------------type_action
      value = QString("%1").arg(fltr_lst[j].get_type_action());
      settings.setValue(key+"---type_action", value);

      //--------------------Numb_Filtr
      value = QString("%1").arg(fltr_lst[j].get_Numb_Filtr());
      settings.setValue(key+"---Numb_Filtr", value);

      //--------------------Name_of_Process
      value = QString("%1").arg(fltr_lst[j].get_Name_of_Process());
      settings.setValue(key+"---Name_of_Process", value);

      //--------------------PID_of_Process
      value = QString("%1").arg(fltr_lst[j].get_PID_of_Process());
      settings.setValue(key+"---PID_of_Process", value);


    }
  }  

  settings.setValue("name_rule_lst", name_rule_lst);
  settings.setValue("size_rule_lst", size_rule_lst);  
  settings.setValue("enable_rule_lst", enable_rule_lst);
}


//Устанавливает значение ячейки таблицы--------------------------------------
long MainWindow::set_item_value(QTableWidget *p_table,
                                char *item_value,
                                int row,
                                int col){
  if (p_table == NULL || item_value == NULL){
    return -1;
  }


  QString buf = QString::fromLocal8Bit(item_value);

  QTableWidgetItem *item = new QTableWidgetItem();
  item->setText(QString::fromLocal8Bit((char *)item_value));
  item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled|Qt::ItemIsEditable);
  p_table->setItem(row, col, item);

  return 0;
}

long MainWindow::set_item_value(QTableWidget *p_table,
                                char *item_value,
                                int row,
                                int col,
                                QString mask){
  if (p_table == NULL || item_value == NULL || mask == NULL){
    return -1;
  }  

  QLineEdit *item = new QLineEdit();
  item->setText(QString::fromLocal8Bit((char *)item_value));
  item->setInputMask(mask);
  p_table->setCellWidget(row, col, item);

  this->set_item_value(p_table, mask.toLocal8Bit().data(), row, col);//for alignment in the table, when autosize
  return 0;
}

long MainWindow::set_table_header(char *row_col,QTableWidget *p_table, char *header_name, int number){
  QTableWidgetItem *headerItem;

  headerItem = new QTableWidgetItem();
  headerItem->setText(QString::fromLocal8Bit((char *)header_name));
  headerItem->setTextAlignment(Qt::AlignCenter);

  if (strcmp(row_col, (char *)"head_row") == 0){
    p_table->setVerticalHeaderItem(number, headerItem);
  }
  if (strcmp(row_col, (char *)"head_col") == 0){
    p_table->setHorizontalHeaderItem(number, headerItem);
  }

  return (0);
}

void MainWindow::on_lst_Menu_clicked(const QModelIndex &index)
{
  if (index.row()==2){
    close();
  }
  else{
    ui->stc_WorkSpace->setCurrentIndex(index.row());
  }

}
void MainWindow::on_btnNotDefend_clicked()
{

  ui->btnEnableDfnd->setChecked(false);
  ui->btnAll_Defend->setChecked(false);
  ui->btnNotDefend->setChecked(true);

  ui->lbl_desable_def->setVisible(true);
  ui->lbl_enable_inf->setVisible(false);
  ui->lbl_All_Def->setVisible(false);
}

void MainWindow::on_btnEnableDfnd_clicked()
{
  ui->btnEnableDfnd->setChecked(true);
  ui->btnAll_Defend->setChecked(false);
  ui->btnNotDefend->setChecked(false);

  ui->lbl_desable_def->setVisible(false);
  ui->lbl_enable_inf->setVisible(true);
  ui->lbl_All_Def->setVisible(false);



  int ad_cnt = wall->get_adapt_count();
  for (int i=0;i<ad_cnt;i++){
    wall->set_rules(i);
  }
}
int MainWindow::Get_Proc_List(QStringList *slProcesses,
                                  int return_param)
{
  if (slProcesses==NULL){
    return -1;
  }
  //HANDLE hSnap;
  //PROCESSENTRY32 pe32;

  HANDLE hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
  if ( hProcessSnap != INVALID_HANDLE_VALUE )
  {
    PROCESSENTRY32 pe32 = {0};
    pe32.dwSize = sizeof( PROCESSENTRY32 );
    if ( Process32First( hProcessSnap, &pe32 ) )
    {
      do {
//        slProcesses->append(QString("%1").arg(i) +
//                            " - PID:"  + QString("%1").arg(pe32.th32ProcessID) +
//                            " EXE NAME:" + pe32.szExeFile +
//                            " Количество потоков: " + QString("%1").arg(pe32.cntThreads) +
//                            " Базовый приоритет: " + QString("%1").arg(pe32.pcPriClassBase));
        if (return_param == PID_PROCESS){
          slProcesses->append(QString("%1").arg(pe32.th32ProcessID));

        }
        if (return_param == NAME_PROCESS){
          slProcesses->append(pe32.szExeFile);
        }
        if (return_param == NAME_PID){
          QString buf;
          buf.append(pe32.szExeFile);
          buf.append("-");
          buf.append(QString("%1").arg(pe32.th32ProcessID));

          slProcesses->append(buf.toLocal8Bit().data());
        }

      }
      while ( Process32Next( hProcessSnap, &pe32 ) );
    }
    CloseHandle( hProcessSnap );
  }
  return 0;
}
char* ProcessPIDToName(HANDLE hProcessSnap,DWORD ProcessId)
{
  PROCESSENTRY32 processEntry;
  // Подготовительные действия  
  memset(&processEntry, 0, sizeof(PROCESSENTRY32));
  processEntry.dwSize = sizeof(PROCESSENTRY32);
  // Прыгаем на первый процесс в списке  
  int rez = Process32First(hProcessSnap, &processEntry);
  if (not rez) return (char*)"";
  while (rez){
    // Сравнение
    if (processEntry.th32ProcessID == ProcessId)
    {
      // Если нашли нужный процесс - выводим результат и выходим
      return (char*)&processEntry.szExeFile;
    }
    // ищем пока не кончатся процессы
    rez = Process32Next(hProcessSnap, &processEntry);
  }
  return  (char*)"";
 }
char* PortStateToStr(DWORD State)
{
  //char Result[]={};
  switch (State)
  {

    case MIB_TCP_STATE_CLOSED: return (char*)"CLOSED";
    case MIB_TCP_STATE_LISTEN: return (char*)"LISTEN";
    case MIB_TCP_STATE_SYN_SENT: return (char*)"SYN SENT";
    case MIB_TCP_STATE_SYN_RCVD: return (char*)"SYN RECEIVED";
    case MIB_TCP_STATE_ESTAB: return (char*)"ESTABLISHED";
    case MIB_TCP_STATE_FIN_WAIT1: return (char*)"FIN WAIT 1";
    case MIB_TCP_STATE_FIN_WAIT2: return (char*)"FIN WAIT 2";
    case MIB_TCP_STATE_CLOSE_WAIT: return (char*)"CLOSE WAIT";
    case MIB_TCP_STATE_CLOSING: return (char*)"CLOSING";
    case MIB_TCP_STATE_LAST_ACK: return (char*)"LAST ACK";
    case MIB_TCP_STATE_TIME_WAIT: return (char*)"TIME WAIT";
    case MIB_TCP_STATE_DELETE_TCB: return (char*)"DELETE TCB";
    default : return (char*)"UNKNOWN";
  }

}

void MainWindow::on_btnAll_Defend_clicked()
{
  ui->btnEnableDfnd->setChecked(false);
  ui->btnAll_Defend->setChecked(true);
  ui->btnNotDefend->setChecked(false);

  ui->lbl_desable_def->setVisible(false);
  ui->lbl_enable_inf->setVisible(false);
  ui->lbl_All_Def->setVisible(true);

  QStringList *str_list = new QStringList();
  str_list->append("3333333333333333333");
  //int rez = get_opens_port(str_list, "Skype.exe");
  //rez = 0;

}
int MainWindow::add_item_menu(QListWidget *name_Menu, char *name_icon, char *text_item){

  if(name_Menu==NULL || name_icon==NULL || text_item==NULL){
    QMessageBox::warning(this,
                       "Warring",
                       "Menu options are not set!!!");
    return (-1);
  }
  QListWidgetItem * itm_level = new QListWidgetItem();
  QIcon *icon_view = new QIcon();

  icon_view->addFile(QString::fromUtf8(name_icon), QSize(), QIcon::Normal, QIcon::Off);

  itm_level->setIcon(*icon_view);
  itm_level->setText(QString::fromLocal8Bit((char *)text_item));
  itm_level->setTextAlignment(Qt::AlignCenter);

  name_Menu->addItem(itm_level);

  return(0);
}

void MainWindow::on_btn_AddRule_clicked()
{
  sr = new select_rule();

//  QObject::connect(sr, SIGNAL(SIGN_choose_rule(QString*)),
//                   this,SLOT(SLOT_choose_rule(QString*)));
  QObject::connect(sr, SIGNAL(SIGN_choose_rule(int)),
                     this,SLOT(SLOT_choose_rule(int)));
  if(sr->exec()){
    QMessageBox::about(this,
                       "Error",
                       "Error of choose Rule...");
  }
  delete sr;
  ui->tbl_Rules->resizeColumnsToContents();
}

void MainWindow::on_btn_DeleteRule_clicked()
{
  long NumbRul = -1;
  NumbRul = wall->get_NumbRule_from_Name(ui->tbl_Rules->currentItem()->text().toLocal8Bit().data());
  chk_rez(wall->set_enable(NumbRul, 0));
  chk_rez(show_enable_rules(wall->get_Size_Wall()));
  ui->btn_DeleteRule->setEnabled(ui->tbl_Rules->rowCount()>0);
  ui->tbl_Rules->setCurrentItem(
        ui->tbl_Rules->item(ui->tbl_Rules->rowCount()-1, 0));
}
void MainWindow::SLOT_choose_rule(int Number_of_Rule){  
  ui->tbl_Rules->setRowCount(ui->tbl_Rules->rowCount()+1);
  if (ui->tbl_Rules->columnCount()==0){
    ui->tbl_Rules->setColumnCount(1);
  }
  set_item_value(ui->tbl_Rules,
                 wall->get_rule_lst()[Number_of_Rule].get_Name_of_Rule(),
                 ui->tbl_Rules->rowCount()-1,
                 0);
  wall->get_rule_lst()[Number_of_Rule].set_enable(true);  
  ui->btn_DeleteRule->setEnabled(ui->tbl_Rules->rowCount()>0);
}
int chk_rez(int err){
  switch (err)
  {
  case 1:

    {
      QMessageBox::about(0,
                         "Error",
                         "Error...");
    }
  case 31:
    {
      QMessageBox::about(0,
                         "Error",
                         "Error of change filtr...");
    }
  }
  return 0;
}
long MainWindow::check_uniq_rule (CRule *rules_lst,
                                  char  *name_of_rule){
  if (name_of_rule==NULL){
    return -1;
  }
  for(int i=0;i<wall->get_Size_Wall();i++){
    if (strcmp(name_of_rule,
               rules_lst[i].get_Name_of_Rule())==0){
      QMessageBox::about(this,
                         QString::fromLocal8Bit((char*)"Ошибка"),
                         QString::fromLocal8Bit((char*)"Правило с таким именем уже существует!\nВведите другое имя."));
      return -1;
    }
  }
  return 0;
}
