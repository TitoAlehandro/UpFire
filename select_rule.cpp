#include "select_rule.h"
#include "ui_select_rule.h"
#include <QMessageBox>
#include "mainwindow.h"

select_rule::select_rule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::select_rule)
{        
    ui->setupUi(this);
    show_rules();

}

select_rule::~select_rule()
{  
  delete ui;
}

void select_rule::on_btn_Rule_Create_clicked()
{  
  mr = new make_rule();
  QObject::connect(mr, SIGNAL(SIGN_add_rule(void*)),
                   this,SLOT(SLOT_add_rule(void*)));

  if(mr->exec()){
    QMessageBox::about(this,
                       "Error",
                       "Error of make classform...");

  }
  delete mr;
}

void select_rule::on_btn_Rule_Cancel_clicked()
{
  close();
}

void select_rule::SLOT_add_rule(void *p_Rule){

  //-------------add Rule in the Wall
  int pr_rez = wall->add_rule((CRule*)p_Rule);
  if(pr_rez){
    QMessageBox::about(this,
                      "Error",
                      "Error of add filtr...");
  }
  //-------------show adding Rule in the gui table
  ui->tbl_Rule_lst->setRowCount(ui->tbl_Rule_lst->rowCount()+1);

  MainWindow *fake_mw = (MainWindow*)parent();
  fake_mw->set_item_value(ui->tbl_Rule_lst,
                        ((CRule*)p_Rule)->get_Name_of_Rule(),
                          ui->tbl_Rule_lst->rowCount()-1,
                          0);

  ui->tbl_Rule_lst->setCurrentCell(ui->tbl_Rule_lst->rowCount()-1, 0);
  ui->btn_Rule_OK->setEnabled(ui->tbl_Rule_lst->rowCount()>0);
  ui->btn_Rule_Change->setEnabled(ui->tbl_Rule_lst->rowCount()>0);
  ui->tbl_Rule_lst->resizeColumnsToContents();
}

void select_rule::on_btn_Rule_OK_clicked()
{
//  MainWindow *mw = (MainWindow*)parent();
//  for(int i=0;i<ui->tbl_Rule_lst->rowCount();i++){
//    if (ui->tbl_Rule_lst->rowCount()>0 &&
//        strcmp(ui->tbl_Rule_lst->currentItem()->text().toLocal8Bit().data(),
//               ui->tbl_Rule_lst->item(i,1)->text().toLocal8Bit().data())){
//      QMessageBox::about(this,
//                         QString::fromLocal8Bit((char*)"Ошибка"),
//                         QString::fromLocal8Bit((char*)"Правило с таким именем уже добавлено!\n Выберите другое правило."));
//      return;
//    }
//  }

  SIGN_choose_rule(ui->tbl_Rule_lst->currentRow());
  close();
}


void select_rule::SLOT_change_rule(void *p_Rule){
  //-------------add Rule in the Wall
  int pr_rez = wall->change_rule((CRule*)p_Rule);
  if(pr_rez){
    QMessageBox::about(this,
                      "Error",
                      "Error of add filtr...");
  }
  //-------------show changing Rule in the gui table
  show_rules();

}

void select_rule::on_btn_Rule_Change_clicked()
{
  mr = new make_rule(0,
                     ui->tbl_Rule_lst->currentRow(),
                     wall->get_rule_lst()[ui->tbl_Rule_lst->currentRow()].get_Size_Rule());
  QObject::connect(mr,SIGNAL(SIGN_change_rule(void*)),
                   this,SLOT(SLOT_change_rule(void*)));

  if(mr->exec()){
    QMessageBox::about(this,
                       "Error",
                       "Error of make classform...");
  }
  delete mr;  

}
int select_rule::show_rules(){
  MainWindow *fake_mw = NULL;

  ui->tbl_Rule_lst->clear();
  ui->tbl_Rule_lst->setColumnCount(1);

  fake_mw->set_table_header((char*)"head_col",
                            ui->tbl_Rule_lst,
                            (char*)"Наименование",
                            0);

  ui->tbl_Rule_lst->setRowCount(wall->get_Size_Wall());
  for(int i=0;i<wall->get_Size_Wall();i++){


    fake_mw->set_item_value( ui->tbl_Rule_lst,
                             wall->get_rule_lst()[i].get_Name_of_Rule(),
                             i,
                             0);
  }
  ui->btn_Rule_OK->setEnabled(ui->tbl_Rule_lst->rowCount()>0);
  ui->btn_Rule_Change->setEnabled(ui->tbl_Rule_lst->rowCount()>0);
  ui->tbl_Rule_lst->resizeColumnsToContents();
  ui->btn_Rule_Delete->setEnabled(ui->tbl_Rule_lst->rowCount()>0);

  return 0;
}

void select_rule::on_btn_Rule_Delete_clicked()
{
  long numb = wall->get_NumbRule_from_Name(ui->tbl_Rule_lst->currentItem()->text().toLocal8Bit().data());
  wall->del_rule(&wall->get_rule_lst()[numb]);
  show_rules();  
  ui->btn_Rule_Delete->setEnabled(ui->tbl_Rule_lst->rowCount()>0);
  ui->tbl_Rule_lst->setCurrentItem(
        ui->tbl_Rule_lst->item(ui->tbl_Rule_lst->rowCount()-1, 0));

}
