#ifndef SELECT_RULE_H
#define SELECT_RULE_H
#include <QDialog>
#include <make_rule.h>


namespace Ui {
    class select_rule;
}

class select_rule : public QDialog
{
    Q_OBJECT

public:
    explicit select_rule(QWidget *parent = 0);
    ~select_rule();
    make_rule                   *mr;
    int show_rules();
signals:
    //void SIGN_choose_rule(QString *str);
    void SIGN_choose_rule(int Number_of_Rule);

public slots:
    void SLOT_add_rule   (void *p_Rule);
    void SLOT_change_rule(void *p_Rule);

private slots:
    void on_btn_Rule_Create_clicked();
    void on_btn_Rule_Cancel_clicked();
    void on_btn_Rule_OK_clicked();
    void on_btn_Rule_Change_clicked();

    void on_btn_Rule_Delete_clicked();

private:
    Ui::select_rule *ui;
};

#endif // SELECT_RULE_H
