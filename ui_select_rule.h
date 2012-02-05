/********************************************************************************
** Form generated from reading UI file 'select_rule.ui'
**
** Created: Sat 4. Feb 10:46:23 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_RULE_H
#define UI_SELECT_RULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_select_rule
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tbl_Rule_lst;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_Rule_OK;
    QToolButton *btn_Rule_Change;
    QToolButton *btn_Rule_Create;
    QPushButton *btn_Rule_Delete;
    QToolButton *btn_Rule_Cancel;

    void setupUi(QDialog *select_rule)
    {
        if (select_rule->objectName().isEmpty())
            select_rule->setObjectName(QString::fromUtf8("select_rule"));
        select_rule->resize(700, 302);
        QFont font;
        font.setPointSize(10);
        select_rule->setFont(font);
        gridLayout = new QGridLayout(select_rule);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tbl_Rule_lst = new QTableWidget(select_rule);
        tbl_Rule_lst->setObjectName(QString::fromUtf8("tbl_Rule_lst"));
        tbl_Rule_lst->setFont(font);

        gridLayout->addWidget(tbl_Rule_lst, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_Rule_OK = new QToolButton(select_rule);
        btn_Rule_OK->setObjectName(QString::fromUtf8("btn_Rule_OK"));
        btn_Rule_OK->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Rule_OK->setIcon(icon);
        btn_Rule_OK->setIconSize(QSize(25, 25));
        btn_Rule_OK->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_Rule_OK);

        btn_Rule_Change = new QToolButton(select_rule);
        btn_Rule_Change->setObjectName(QString::fromUtf8("btn_Rule_Change"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/editalt.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Rule_Change->setIcon(icon1);
        btn_Rule_Change->setIconSize(QSize(25, 25));
        btn_Rule_Change->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_Rule_Change);

        btn_Rule_Create = new QToolButton(select_rule);
        btn_Rule_Create->setObjectName(QString::fromUtf8("btn_Rule_Create"));
        btn_Rule_Create->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/tab_new_raised.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Rule_Create->setIcon(icon2);
        btn_Rule_Create->setIconSize(QSize(25, 25));
        btn_Rule_Create->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_Rule_Create);

        btn_Rule_Delete = new QPushButton(select_rule);
        btn_Rule_Delete->setObjectName(QString::fromUtf8("btn_Rule_Delete"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_Rule_Delete->sizePolicy().hasHeightForWidth());
        btn_Rule_Delete->setSizePolicy(sizePolicy);
        btn_Rule_Delete->setMinimumSize(QSize(0, 0));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Rule_Delete->setIcon(icon3);
        btn_Rule_Delete->setIconSize(QSize(25, 25));

        horizontalLayout->addWidget(btn_Rule_Delete);

        btn_Rule_Cancel = new QToolButton(select_rule);
        btn_Rule_Cancel->setObjectName(QString::fromUtf8("btn_Rule_Cancel"));
        btn_Rule_Cancel->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Rule_Cancel->setIcon(icon4);
        btn_Rule_Cancel->setIconSize(QSize(25, 25));
        btn_Rule_Cancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_Rule_Cancel);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(select_rule);

        QMetaObject::connectSlotsByName(select_rule);
    } // setupUi

    void retranslateUi(QDialog *select_rule)
    {
        select_rule->setWindowTitle(QApplication::translate("select_rule", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276 \320\264\320\273\321\217 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_Rule_OK->setToolTip(QApplication::translate("select_rule", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_Rule_OK->setText(QApplication::translate("select_rule", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_Rule_Change->setToolTip(QApplication::translate("select_rule", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_Rule_Change->setText(QApplication::translate("select_rule", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_Rule_Create->setToolTip(QApplication::translate("select_rule", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_Rule_Create->setText(QApplication::translate("select_rule", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_Rule_Delete->setToolTip(QApplication::translate("select_rule", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_Rule_Delete->setText(QApplication::translate("select_rule", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_Rule_Cancel->setToolTip(QApplication::translate("select_rule", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\262\321\213\320\261\320\276\321\200 \320\277\321\200\320\260\320\262\320\270\320\273\320\260 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_Rule_Cancel->setText(QApplication::translate("select_rule", "\320\236\321\202\320\274\320\265\320\275\320\260  ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class select_rule: public Ui_select_rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_RULE_H
