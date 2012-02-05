#include "make_rule.h"
#include "ui_make_rule.h"
#include <QTextEdit>
#include <QMessageBox>
#include "select_rule.h"
#include "mainwindow.h"

MainWindow *mw;
int FLAG_changeRule;

make_rule::make_rule(QWidget *parent,
                     int      numb_changeRule,
                     int      size_changeRule) :
    QDialog(parent),
    ui(new Ui::make_rule)
{
    ui->setupUi(this);
    FLAG_changeRule=-1;

    ui->lbl_port_->setVisible(false);
    ui->lbl_IP_->setVisible(false);
    ui->edt_Port_end->setVisible(false);
    ui->edt_IP_end->setVisible(false);
    ui->edt_Port_begin->setVisible(false);
    ui->edt_IP_begin->setVisible(false);

    set_table_headers();

    p_Filtr_lst =  new QList <void*>();
    p_Rule = new CRule();

    if (numb_changeRule>-1){
      FLAG_changeRule = numb_changeRule;
      numb_chRule     = numb_changeRule;
      size_chRule     = size_changeRule;

      set_current_Rule(numb_chRule);
    }

    ui->btn_Rule_OK->setEnabled(ui->tbl_Filters->rowCount()>0);
    ui->edt_Port_begin->setInputMask(MASK_PORT);
    ui->edt_Port_end->setInputMask(MASK_PORT);
    ui->edt_IP_begin->setInputMask(MASK_IP);
    ui->edt_IP_end->setInputMask(MASK_IP);

    ui->cbx_Process->setVisible(false);
    ui->edt_PID->setVisible(false);

}

make_rule::~make_rule()
{
    delete ui;
}

void make_rule::on_btn_Rule_Cancel_clicked()
{
    close();
}

void make_rule::on_cbx_port_currentIndexChanged(int index)
{
  if (index == 0){
    ui->lbl_port_->setVisible(false);
    ui->edt_Port_end->setVisible(false);
    ui->edt_Port_begin->setVisible(false);

  }
  if (index == 1){
    ui->lbl_port_->setVisible(false);
    ui->edt_Port_end->setVisible(false);
    ui->edt_Port_begin->setVisible(true);
  }
  if (index == 2){
    ui->lbl_port_->setVisible(true);
    ui->edt_Port_end->setVisible(true);
    ui->edt_Port_begin->setVisible(true);
  }

}

void make_rule::on_cbx_IP_currentIndexChanged(int index)
{
  if (index == 0){
    ui->lbl_IP_->setVisible(false);
    ui->edt_IP_begin->setVisible(false);
    ui->edt_IP_end->setVisible(false);

  }
  if (index == 1){
    ui->lbl_IP_->setVisible(false);
    ui->edt_IP_begin->setVisible(true);
    ui->edt_IP_end->setVisible(false);
  }
  if (index == 2){
    ui->lbl_IP_->setVisible(true);
    ui->edt_IP_begin->setVisible(true);
    ui->edt_IP_end->setVisible(true);
  }

}
int make_rule::add_item_table(){
  return(0);
}
int make_rule::set_table_headers(){
  ui->tbl_Filters->setRowCount(0);
  ui->tbl_Filters->setColumnCount(7);

  mw->set_table_header((char *)"head_col",
                       ui->tbl_Filters,
                       (char *)"Протокол",
                       0
                       );
  mw->set_table_header((char *)"head_col",
                       ui->tbl_Filters,
                       (char *)"Порт",
                       1
                       );
  mw->set_table_header((char *)"head_col",
                       ui->tbl_Filters,
                       (char *)"IP",
                       2
                       );
  mw->set_table_header((char *)"head_col",
                       ui->tbl_Filters,
                       (char *)"Пакеты",
                       3
                       );
  mw->set_table_header((char *)"head_col",
                       ui->tbl_Filters,
                       (char *)"Действие",
                       4
                       );
  mw->set_table_header((char *)"head_col",
                       ui->tbl_Filters,
                       (char *)"Процесс",
                       5
                       );
  mw->set_table_header((char *)"head_col",
                       ui->tbl_Filters,
                       (char *)"PID процесса",
                       6
                       );
  return(0);
}

void make_rule::on_btnAddFilter_clicked()
{
  ui->edt_name_rule->setEnabled(ui->tbl_Filters->rowCount()<1);
  ui->tbl_Filters->setRowCount(ui->tbl_Filters->rowCount()+1);

  set_table_items();

  CFiltr *p_Filtr = new CFiltr();
  set_filtr_items(p_Filtr);

  p_Filtr_lst->append(p_Filtr);

  ui->btn_Rule_OK->setEnabled(ui->tbl_Filters->rowCount()>0);
}

void make_rule::on_btn_Rule_OK_clicked()
{
  ui->tbl_Filters->setCurrentCell(-1,-1);
  //GetWindowThreadProcessId()

  if (FLAG_changeRule==-1){

    int pr_r = mw->check_uniq_rule(wall->get_rule_lst(),
                                   ui->edt_name_rule->toPlainText().toLocal8Bit().data());
    if (pr_r == -1){
      return;
    }
    filtr_lst = *(QList<void*>*)p_Filtr_lst;
    for (int i=0;i<filtr_lst.size();i++){
      CFiltr *p_filt = (CFiltr*)filtr_lst[i];
      chk_rez(((CRule*)p_Rule)->add_filtr(p_filt));
      }        
    CRule *rul = ((CRule*)p_Rule);

    rul->set_Name_of_Rule(rul->get_filtr_lst()[0].get_Name_of_Filtr());
    //rul->set_Numb_Rule(wall->get_Size_Wall());

    SIGN_add_rule(p_Rule);
  }
  else{
    filtr_lst = *(QList<void*>*)p_Filtr_lst;
    for (int i=0;i<size_chRule;i++){
      CFiltr *p_fil = new CFiltr();
      p_fil = (CFiltr*)filtr_lst[i];

      CFiltr *p_filt = new CFiltr();
      p_filt->set_Numb_Filtr(i);
      p_filt->set_Name_of_Filtr(ui->edt_name_rule->toPlainText().toLocal8Bit().data());
      chk_rez(p_filt->set_protocol_FromStr(ui->tbl_Filters->item(i,0)->text().toLocal8Bit().data()));
      chk_rez(p_filt->set_Port_FromStr(((QLineEdit*)ui->tbl_Filters->cellWidget(i,1))->text().toLocal8Bit().data(),
                                         1));
      chk_rez(p_filt->set_IP_FromStr(((QLineEdit*)ui->tbl_Filters->cellWidget(i,2))->text().toLocal8Bit().data()));
      chk_rez(p_filt->set_type_packet(((QComboBox*)ui->tbl_Filters->cellWidget(i,3))->currentIndex()));
      chk_rez(p_filt->set_type_action(((QComboBox*)ui->tbl_Filters->cellWidget(i,4))->currentIndex()));

      chk_rez(((CRule*)p_Rule)->change_filtr(p_filt));
    }
    for (int i=size_chRule;i<filtr_lst.count();i++){
      CFiltr *p_filt = new CFiltr();
      p_filt = (CFiltr*)filtr_lst[i];
      chk_rez(((CRule*)p_Rule)->add_filtr(p_filt));
    }

    CRule *rul = ((CRule*)p_Rule);    

    rul->set_Name_of_Rule(rul->get_filtr_lst()[0].get_Name_of_Filtr());
    //rul->set_Numb_Rule(numb_chRule);
    rul->set_Size_of_Rule(filtr_lst.count());

    SIGN_change_rule(p_Rule);
  }
  close();
}

void make_rule::on_edt_name_rule_textChanged(){
  if(ui->edt_name_rule->toPlainText().length()>63){
    ui->edt_name_rule->setText(ui->edt_name_rule->toPlainText().right(63));
  }
}
int make_rule::set_current_Rule(int numb_rule){
  setWindowTitle(QString::fromLocal8Bit((char*)"Изменение правила"));

  CRule* cur_rule = new CRule();


  cur_rule = &wall->get_rule_lst()[numb_rule];

  ui->edt_name_rule->setText(QString::fromLocal8Bit(cur_rule->get_Name_of_Rule()));


  char *buf_chr = (char*)malloc(1024);
  memset(buf_chr,0,1024);

  ui->tbl_Filters->setRowCount(cur_rule->get_Size_Rule());
  for(int i=0;i<cur_rule->get_Size_Rule();i++){
    CFiltr *p_Filtr = new CFiltr();
    QString *buf_str = new QString();
    CFiltr *cur_filtr = &cur_rule->get_filtr_lst()[i];

    //---------1---------------------------------------------------------------
    UPFire_DLL_coff *fake_dll = NULL;    
    PROTOCOL *prot = cur_filtr->get_Protocol();

    fake_dll->IntToStr_protocol(prot->NumberProtocol,
                                buf_chr);
    mw->set_item_value(ui->tbl_Filters,
                       buf_chr,
                       i,
                       0);

    PROTOCOL *pprot = new PROTOCOL();
    pprot->NumberProtocol = cur_filtr->get_Protocol()->NumberProtocol;
    p_Filtr->set_protocol(pprot);


  //---------2---------------------------------------------------------------    
    if(cur_filtr->get_Port()->TypePort==0){
      mw->set_item_value(ui->tbl_Filters,
                         (char*)"____",
                         i,
                         1,
                         MASK_PORT_RANGE);
      p_Filtr->get_Port()->TypePort = 0;

    }
    if(cur_filtr->get_Port()->TypePort==1){
      mw->set_item_value(ui->tbl_Filters,
                         QString("%1").arg(cur_filtr->get_Port()->DestPortBegin).toLocal8Bit().data(),
                         i,
                         1,
                         MASK_PORT);
      p_Filtr->get_Port()->TypePort = cur_filtr->get_Port()->TypePort;
      p_Filtr->get_Port()->DestPortBegin = cur_filtr->get_Port()->DestPortBegin;
      p_Filtr->get_Port()->DestPortEnd = cur_filtr->get_Port()->DestPortEnd;

    }
    if(cur_filtr->get_Port()->TypePort==2){
      buf_str->append(QString("%1").arg(cur_filtr->get_Port()->DestPortBegin) +
                      "-" +
                      QString("%1").arg(cur_filtr->get_Port()->DestPortEnd));
      mw->set_item_value(ui->tbl_Filters,
                         buf_str->toLocal8Bit().data(),
                         i,
                         1,
                         MASK_PORT_RANGE);

      p_Filtr->get_Port()->TypePort      = cur_filtr->get_Port()->TypePort;
      p_Filtr->get_Port()->DestPortBegin = cur_filtr->get_Port()->DestPortBegin;
      p_Filtr->get_Port()->DestPortEnd   = cur_filtr->get_Port()->DestPortEnd;
    }

    if(cur_filtr->get_Port()->TypePort==3){
      mw->set_item_value(ui->tbl_Filters,
                         QString("%1").arg(cur_filtr->get_Port()->SourcePortBegin).toLocal8Bit().data(),
                         i,
                         1,
                         MASK_PORT);
      p_Filtr->get_Port()->TypePort        = cur_filtr->get_Port()->TypePort;
      p_Filtr->get_Port()->SourcePortBegin = cur_filtr->get_Port()->SourcePortBegin;
      p_Filtr->get_Port()->SourcePortEnd   = cur_filtr->get_Port()->SourcePortEnd;

    }
    if(cur_filtr->get_Port()->TypePort==4){
      buf_str->append(QString("%1").arg(cur_filtr->get_Port()->SourcePortBegin) +
                      "-" +
                      QString("%1").arg(cur_filtr->get_Port()->SourcePortEnd));
      mw->set_item_value(ui->tbl_Filters,
                         buf_str->toLocal8Bit().data(),
                         i,
                         1,
                         MASK_PORT_RANGE);

      p_Filtr->get_Port()->TypePort        = cur_filtr->get_Port()->TypePort;
      p_Filtr->get_Port()->SourcePortBegin = cur_filtr->get_Port()->SourcePortBegin;
      p_Filtr->get_Port()->SourcePortEnd   = cur_filtr->get_Port()->SourcePortEnd;
    }

  //---------3---------------------------------------------------------------
    if(cur_filtr->get_IP()->TypeIP==0){
      mw->set_item_value(ui->tbl_Filters,
                         (char*)"___.___.___.___",
                         i,
                         2,
                         MASK_IP_RANGE);
      p_Filtr->get_IP()->TypeIP=0;
    }
    if(cur_filtr->get_IP()->TypeIP==1){
      memset(buf_chr, 0, 1024);
      cur_filtr->put_DestIP_ToStr(buf_chr);
      mw->set_item_value(ui->tbl_Filters,
                         buf_chr,
                         i,
                         2,
                         MASK_IP);
      p_Filtr->get_IP()->TypeIP=1;
      p_Filtr->put_DestIP(&p_Filtr->get_IP()->DestIP);
    }
    if(cur_filtr->get_IP()->TypeIP==2){
      memset(buf_chr, 0, 1024);
      cur_filtr->put_DestIP_ToStr(buf_chr);
      strcat(buf_chr, "-");
      cur_filtr->put_SourceIP_ToStr(buf_chr);
      mw->set_item_value(ui->tbl_Filters,
                         buf_chr,
                         i,
                         2,
                         MASK_IP_RANGE);
      p_Filtr->get_IP()->TypeIP=2;
      p_Filtr->put_DestIP(&p_Filtr->get_IP()->DestIP);
      p_Filtr->put_SourceIP(&p_Filtr->get_IP()->SourceIP);
    }    
    //---------4---------------------------------------------------------------
    cbx_mask = new QComboBox();
    cbx_mask->addItem(QString::fromLocal8Bit("по умолчанию"));
    cbx_mask->addItem(QString::fromLocal8Bit("входящие"));
    cbx_mask->addItem(QString::fromLocal8Bit("исходящие"));

    cbx_mask->setCurrentIndex(cur_filtr->get_type_packet());
    ui->tbl_Filters->setCellWidget(i, 3, cbx_mask);

    p_Filtr->set_type_packet(cur_filtr->get_type_packet());
    //---------5---------------------------------------------------------------
    cbx_mask = new QComboBox();
    cbx_mask->addItem(QString::fromLocal8Bit("пропускать"));
    cbx_mask->addItem(QString::fromLocal8Bit("блокировать"));
    cbx_mask->addItem(QString::fromLocal8Bit("перенаправлять"));    
    cbx_mask->setCurrentIndex(cur_filtr->get_type_action());
    ui->tbl_Filters->setCellWidget(i, 4, cbx_mask);

    p_Filtr->set_type_action(cur_filtr->get_type_action());
    //---------6---------------------------------------------------------------
    mw->set_item_value(ui->tbl_Filters,
                       cur_filtr->get_Name_of_Process(),
                       i,
                       5);
    //---------7---------------------------------------------------------------
    mw->set_item_value(ui->tbl_Filters,
                       QString("%1").arg(cur_filtr->get_PID_of_Process()).toLocal8Bit().data(),
                       i,
                       6);


    ui->tbl_Filters->resizeColumnsToContents();
    p_Filtr_lst->append(p_Filtr);
  }

  free(buf_chr);
  return 0;
}
int make_rule::set_table_items(){
  ////---------0---------------------------------------------------------------
  //  mw->set_item_value(ui->tbl_Filters,
  //                     ui->edt_name_rule->toPlainText().toLocal8Bit().data(),
  //                     ui->tbl_Filters->rowCount()-1,
  //                     0);
  //---------1---------------------------------------------------------------
    mw->set_item_value(ui->tbl_Filters,
                       ui->cbx_protocol->currentText().toLocal8Bit().data(),
                       ui->tbl_Filters->rowCount()-1,
                       0);

  //---------2---------------------------------------------------------------
    if(ui->cbx_kind_port->currentIndex()==0){
      mw->set_item_value(ui->tbl_Filters,
                         (char*)"____",//ui->cbx_port->currentText().toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         1,
                         MASK_PORT);
    }
    if(ui->cbx_kind_port->currentIndex()==1 || ui->cbx_kind_port->currentIndex()==3){
      mw->set_item_value(ui->tbl_Filters,
                         ui->edt_Port_begin->text().toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         1,
                         MASK_PORT);
    }
    if(ui->cbx_kind_port->currentIndex()==2 || ui->cbx_kind_port->currentIndex()==4){
      QString *buf_str = new QString();

      buf_str->append(ui->edt_Port_begin->text() + "-" + ui->edt_Port_end->text());
      mw->set_item_value(ui->tbl_Filters,
                         buf_str->toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         1,
                         MASK_PORT_RANGE);
    }
  //---------3---------------------------------------------------------------
    if(ui->cbx_IP->currentIndex()==0){
      mw->set_item_value(ui->tbl_Filters,
                         (char*)"___.___.___.___"/*ui->cbx_IP->currentText().toLocal8Bit().data()*/,
                         ui->tbl_Filters->rowCount()-1,
                         2,
                         MASK_IP);
    }
    if(ui->cbx_IP->currentIndex()==1){
      mw->set_item_value(ui->tbl_Filters,
                         ui->edt_IP_begin->text().toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         2,
                         MASK_IP);
    }
    if(ui->cbx_IP->currentIndex()==2){
      QString *buf_str = new QString();

      buf_str->append(ui->edt_IP_begin->text() + "-" + ui->edt_IP_end->text());
      mw->set_item_value(ui->tbl_Filters,
                         buf_str->toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         2,
                         MASK_IP_RANGE);
    }    
  //---------4---------------------------------------------------------------
    cbx_mask = new QComboBox();
    cbx_mask->addItem(QString::fromLocal8Bit("по умолчанию"));
    cbx_mask->addItem(QString::fromLocal8Bit("входящие"));
    cbx_mask->addItem(QString::fromLocal8Bit("исходящие"));

    cbx_mask->setCurrentIndex(ui->cbx_Packs_Type->currentIndex());
    ui->tbl_Filters->setCellWidget(ui->tbl_Filters->rowCount()-1, 3, cbx_mask);
    //---------5---------------------------------------------------------------
    cbx_mask = new QComboBox();
    cbx_mask->addItem(QString::fromLocal8Bit("пропускать"));
    cbx_mask->addItem(QString::fromLocal8Bit("блокировать"));
    cbx_mask->addItem(QString::fromLocal8Bit("перенаправлять"));
    cbx_mask->setCurrentIndex(ui->cbx_Packs_Action->currentIndex());
    ui->tbl_Filters->setCellWidget(ui->tbl_Filters->rowCount()-1, 4, cbx_mask);

    //---------6---------------------------------------------------------------
    if (ui->cbx_Process_kind->currentIndex()==1){
      mw->set_item_value(ui->tbl_Filters,
                         ui->cbx_Process->currentText().toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         5);
    }
    if (ui->cbx_Process_kind->currentIndex()==2){
      mw->set_item_value(ui->tbl_Filters,
                         ui->cbx_Process->currentText().toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         5);
      mw->set_item_value(ui->tbl_Filters,
                         ui->edt_PID->text().toLocal8Bit().data(),
                         ui->tbl_Filters->rowCount()-1,
                         6);
    }
    ui->tbl_Filters->resizeColumnsToContents();

    return 0;
}
int make_rule::set_filtr_items(void *pFiltr){
  CFiltr * fil = (CFiltr*)pFiltr;
  fil->set_Name_of_Filtr(ui->edt_name_rule->toPlainText().toLocal8Bit().data());

  fil->set_Numb_Filtr(ui->tbl_Filters->rowCount()-1);
  UPFire_DLL_coff *fake_dll = NULL;
  fil->get_Protocol()->NumberProtocol = fake_dll->StrToInt_protocol(ui->cbx_protocol->currentText().toLocal8Bit().data());

  fil->get_Port()->TypePort = ui->cbx_kind_port->currentIndex();
  if (ui->cbx_kind_port->currentIndex() == 0){
    fil->get_Port()->DestPortBegin = 0;
    fil->get_Port()->DestPortEnd = 65535;
  }
  if (ui->cbx_kind_port->currentIndex() == 1 || ui->cbx_kind_port->currentIndex() == 2){
    fil->get_Port()->SourcePortBegin = ui->edt_Port_begin->text().toInt();
    fil->get_Port()->SourcePortEnd = ui->edt_Port_end->text().toInt();
  }
  if (ui->cbx_kind_port->currentIndex() == 3 || ui->cbx_kind_port->currentIndex() == 4){
    fil->get_Port()->DestPortBegin = ui->edt_Port_begin->text().toInt();
    fil->get_Port()->DestPortEnd = ui->edt_Port_end->text().toInt();
  }


  fil->get_IP()->TypeIP = ui->cbx_IP->currentIndex();
  if(ui->cbx_IP->currentIndex()==0){
    fil->set_DestIP_FromStr((char*)"0.0.0.0");
    fil->set_SourceIP_FromStr((char*)"255.255.255.255");
  }
  if(ui->cbx_IP->currentIndex()==1){
    fil->set_DestIP_FromStr(ui->edt_IP_begin->text().toLocal8Bit().data());
  }
  if(ui->cbx_IP->currentIndex()==2){
    fil->set_DestIP_FromStr(ui->edt_IP_begin->text().toLocal8Bit().data());
    fil->set_SourceIP_FromStr(ui->edt_IP_end->text().toLocal8Bit().data());
  }

  fil->set_type_packet ( ui->cbx_Packs_Type->currentIndex());
  fil->set_type_action ( ui->cbx_Packs_Action->currentIndex());

  if (ui->cbx_Process_kind->currentIndex()==0){
    fil->set_Name_of_Process((char*)"");
  }
  if (ui->cbx_Process_kind->currentIndex()==1){
    fil->set_Name_of_Process(ui->cbx_Process->currentText().toLocal8Bit().data());
  }
  if (ui->cbx_Process_kind->currentIndex()==2){
    fil->set_Name_of_Process(ui->cbx_Process->currentText().toLocal8Bit().data());
    fil->set_PID_of_Process(ui->edt_PID->text().toInt());
  }
  return 0;
}

void make_rule::on_tbl_Filters_cellChanged(int row, int column)
{
  if(row==ui->tbl_Filters->currentRow() && column==ui->tbl_Filters->currentColumn()){

  }
}

void make_rule::on_cbx_Process_kind_currentIndexChanged(int index)
{
  int rez = 0;
  ui->cbx_Process->clear();
  QStringList NAME_lst;
  QStringList PID_lst;


  if (index == 0){
    ui->cbx_Process->setVisible(false);
    ui->edt_PID->setVisible(false);

  }
  if (index == 1){
    ui->cbx_Process->setVisible(true);
    ui->edt_PID->setVisible(false);

    rez = mw->Get_Proc_List(&NAME_lst, NAME_PROCESS);
    for (int i=0;i<NAME_lst.count();i++){
      ui->cbx_Process->addItem(NAME_lst[i]);
    }
  }
  if (index == 2){
    ui->cbx_Process->setVisible(true);
    ui->edt_PID->setVisible(true);

    int rez = mw->Get_Proc_List(&NAME_lst, NAME_PROCESS);
    rez = mw->Get_Proc_List(&PID_lst, PID_PROCESS);
    for (int i=0;i<NAME_lst.count();i++){
      ui->cbx_Process->addItem(NAME_lst[i]);
      ui->edt_PID->setText(PID_lst[i]);
    }
  }
}

void make_rule::on_cbx_Process_currentIndexChanged(int index)
{
  if (index >-1){
    QStringList PID_lst;
    int rez = mw->Get_Proc_List(&PID_lst, PID_PROCESS);
    QString buf = PID_lst[index];
    ui->edt_PID->setText(buf);
    rez = 0;
  }
}

void make_rule::on_cbx_kind_port_currentIndexChanged(int index)
{
  if (index == 0){
    ui->lbl_port_->setVisible(false);
    ui->edt_Port_end->setVisible(false);
    ui->edt_Port_begin->setVisible(false);

  }
  if (index == 1){
    ui->lbl_port_->setVisible(false);
    ui->edt_Port_end->setVisible(false);
    ui->edt_Port_begin->setVisible(true);
  }
  if (index == 2){
    ui->lbl_port_->setVisible(true);
    ui->edt_Port_end->setVisible(true);
    ui->edt_Port_begin->setVisible(true);
  }
  if (index == 3){
    ui->lbl_port_->setVisible(false);
    ui->edt_Port_end->setVisible(false);
    ui->edt_Port_begin->setVisible(true);
  }
  if (index == 4){
    ui->lbl_port_->setVisible(true);
    ui->edt_Port_end->setVisible(true);
    ui->edt_Port_begin->setVisible(true);
  }
}
