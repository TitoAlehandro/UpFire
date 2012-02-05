#ifndef MAKE_RULE_H
#define MAKE_RULE_H

#include <QDialog>
#include <QComboBox>

#define MASK_PORT "!99999;"
#define MASK_IP "!999.999.999.999;"
#define MASK_PORT_RANGE "!99999-99999;"
#define MASK_IP_RANGE "!999.999.999.999-999.999.999.999;"


namespace Ui {
    class make_rule;
}
class make_rule : public QDialog
{
    Q_OBJECT

public:
  explicit make_rule(QWidget *parent = 0,
                     int numb_changeRule = -1,
                     int size_chageRule = 0);
  ~make_rule();
  int   add_item_table();
  int   set_table_headers();
  int   set_table_items();
  int   set_filtr_items(void *pFiltr);
  void *p_Rule;
  QList <void*> *p_Filtr_lst;
  QList<void*>   filtr_lst;
  // int numb_change_Rule; -1 - not change, >-1 change
  int   set_current_Rule(int numb_rule);
  int   numb_chRule;
  int   size_chRule;
  QComboBox *cbx_mask;  

signals:
  void SIGN_add_rule(void* pRule_lst);
  void SIGN_change_rule(void* pRule_lst);

private slots:
  void on_btn_Rule_Cancel_clicked();
  void on_cbx_port_currentIndexChanged(int index);
  void on_cbx_IP_currentIndexChanged(int index);
  void on_btnAddFilter_clicked();
  void on_btn_Rule_OK_clicked();
  void on_edt_name_rule_textChanged();
  void on_tbl_Filters_cellChanged(int row, int column);
  void on_cbx_Process_kind_currentIndexChanged(int index);

  void on_cbx_Process_currentIndexChanged(int index);

  void on_cbx_kind_port_currentIndexChanged(int index);

private:
    Ui::make_rule *ui;
};

#endif // MAKE_RULE_H
