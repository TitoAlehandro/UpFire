/********************************************************************************
** Form generated from reading UI file 'make_rule.ui'
**
** Created: Sat 4. Feb 10:46:23 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKE_RULE_H
#define UI_MAKE_RULE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_make_rule
{
public:
    QFrame *frame;
    QTextEdit *edt_name_rule;
    QLabel *lbl_Name_Rule;
    QFrame *frame_2;
    QComboBox *cbx_protocol;
    QLabel *lbl_protocol;
    QFrame *frame_3;
    QLabel *lbl_Filters;
    QTableWidget *tbl_Filters;
    QPushButton *btnAddFilter;
    QFrame *frame_8;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_Rule_OK;
    QToolButton *btn_Rule_Cancel;
    QFrame *frame_4;
    QLabel *lbl_port_;
    QLabel *lbl_port;
    QLineEdit *edt_Port_end;
    QLineEdit *edt_Port_begin;
    QComboBox *cbx_kind_port;
    QFrame *frame_6;
    QComboBox *cbx_Packs_Action;
    QLabel *lbl_Packs;
    QComboBox *cbx_Packs_Type;
    QFrame *frame_5;
    QLineEdit *edt_IP_end;
    QLabel *lbl_IP;
    QLineEdit *edt_IP_begin;
    QComboBox *cbx_IP;
    QLabel *lbl_IP_;
    QComboBox *cbx_kind_IP;
    QFrame *frame_7;
    QLabel *lbl_Process;
    QComboBox *cbx_Process_kind;
    QComboBox *cbx_Process;
    QLineEdit *edt_PID;

    void setupUi(QDialog *make_rule)
    {
        if (make_rule->objectName().isEmpty())
            make_rule->setObjectName(QString::fromUtf8("make_rule"));
        make_rule->resize(1100, 650);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(make_rule->sizePolicy().hasHeightForWidth());
        make_rule->setSizePolicy(sizePolicy);
        make_rule->setMinimumSize(QSize(1100, 650));
        make_rule->setMaximumSize(QSize(1100, 650));
        make_rule->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(make_rule);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(30, 10, 741, 51));
        frame->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     background:  rgb(225, 225, 225);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QTextEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                "
                        "                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        edt_name_rule = new QTextEdit(frame);
        edt_name_rule->setObjectName(QString::fromUtf8("edt_name_rule"));
        edt_name_rule->setGeometry(QRect(120, 10, 591, 31));
        QFont font;
        font.setPointSize(10);
        edt_name_rule->setFont(font);
        edt_name_rule->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lbl_Name_Rule = new QLabel(frame);
        lbl_Name_Rule->setObjectName(QString::fromUtf8("lbl_Name_Rule"));
        lbl_Name_Rule->setGeometry(QRect(10, 20, 101, 21));
        lbl_Name_Rule->setFont(font);
        frame_2 = new QFrame(make_rule);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(780, 10, 251, 51));
        frame_2->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     background:  rgb(225, 225, 225);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        cbx_protocol = new QComboBox(frame_2);
        cbx_protocol->setObjectName(QString::fromUtf8("cbx_protocol"));
        cbx_protocol->setGeometry(QRect(110, 10, 131, 31));
        cbx_protocol->setFont(font);
        lbl_protocol = new QLabel(frame_2);
        lbl_protocol->setObjectName(QString::fromUtf8("lbl_protocol"));
        lbl_protocol->setGeometry(QRect(20, 20, 81, 21));
        lbl_protocol->setFont(font);
        frame_3 = new QFrame(make_rule);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(30, 220, 1001, 411));
        frame_3->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     background:  rgb(225, 225, 225);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"\n"
""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        lbl_Filters = new QLabel(frame_3);
        lbl_Filters->setObjectName(QString::fromUtf8("lbl_Filters"));
        lbl_Filters->setGeometry(QRect(370, 50, 351, 21));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lbl_Filters->setFont(font1);
        tbl_Filters = new QTableWidget(frame_3);
        tbl_Filters->setObjectName(QString::fromUtf8("tbl_Filters"));
        tbl_Filters->setGeometry(QRect(15, 80, 931, 241));
        tbl_Filters->setFont(font);
        tbl_Filters->setStyleSheet(QString::fromUtf8("QTableView QTableCornerButton::section {\n"
"background-color: rgb(108, 108, 108);\n"
"}\n"
"\n"
"QHeaderView:section{\n"
"	 background-color: rgb(108, 108, 108);\n"
"    \n"
"	 color: white;\n"
"     margin:2px;\n"
"	 border-radius : 25px;\n"
" } \n"
"QHeaderView{\n"
"	 background-color: rgb(108, 108, 108);\n"
"	 color: white;\n"
"	 border: 1px solid #6c6c6c;\n"
"	 border-radius : 25px;\n"
" }\n"
"QTableWidget{\n"
"	border: 2px solid   rgb(108, 108, 108);\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"      \n"
"    background-color: rgb(255, 255, 255);\n"
"}\n"
""));
        tbl_Filters->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tbl_Filters->verticalHeader()->setCascadingSectionResizes(false);
        btnAddFilter = new QPushButton(frame_3);
        btnAddFilter->setObjectName(QString::fromUtf8("btnAddFilter"));
        btnAddFilter->setGeometry(QRect(958, 80, 30, 30));
        btnAddFilter->setFont(font);
        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setGeometry(QRect(351, 331, 321, 61));
        frame_8->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"    \n"
"	 background: rgb(207, 207, 207);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_8);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(-40, 0, 405, 58));
        layoutWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_Rule_OK = new QToolButton(layoutWidget);
        btn_Rule_OK->setObjectName(QString::fromUtf8("btn_Rule_OK"));
        btn_Rule_OK->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Rule_OK->setIcon(icon);
        btn_Rule_OK->setIconSize(QSize(25, 25));
        btn_Rule_OK->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_Rule_OK);

        btn_Rule_Cancel = new QToolButton(layoutWidget);
        btn_Rule_Cancel->setObjectName(QString::fromUtf8("btn_Rule_Cancel"));
        btn_Rule_Cancel->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_Rule_Cancel->setIcon(icon1);
        btn_Rule_Cancel->setIconSize(QSize(25, 25));
        btn_Rule_Cancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_Rule_Cancel);

        frame_4 = new QFrame(make_rule);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(570, 70, 461, 51));
        frame_4->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     background:  rgb(225, 225, 225);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        lbl_port_ = new QLabel(frame_4);
        lbl_port_->setObjectName(QString::fromUtf8("lbl_port_"));
        lbl_port_->setGeometry(QRect(320, 15, 32, 20));
        lbl_port_->setFont(font);
        lbl_port = new QLabel(frame_4);
        lbl_port->setObjectName(QString::fromUtf8("lbl_port"));
        lbl_port->setGeometry(QRect(20, 20, 81, 21));
        lbl_port->setFont(font);
        edt_Port_end = new QLineEdit(frame_4);
        edt_Port_end->setObjectName(QString::fromUtf8("edt_Port_end"));
        edt_Port_end->setGeometry(QRect(343, 10, 51, 31));
        edt_Port_end->setFont(font);
        edt_Port_begin = new QLineEdit(frame_4);
        edt_Port_begin->setObjectName(QString::fromUtf8("edt_Port_begin"));
        edt_Port_begin->setGeometry(QRect(263, 10, 51, 31));
        edt_Port_begin->setFont(font);
        cbx_kind_port = new QComboBox(frame_4);
        cbx_kind_port->setObjectName(QString::fromUtf8("cbx_kind_port"));
        cbx_kind_port->setGeometry(QRect(80, 10, 161, 31));
        cbx_kind_port->setMinimumSize(QSize(161, 0));
        cbx_kind_port->setFont(font);
        frame_6 = new QFrame(make_rule);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(570, 130, 461, 51));
        frame_6->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     background:  rgb(225, 225, 225);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        cbx_Packs_Action = new QComboBox(frame_6);
        cbx_Packs_Action->setObjectName(QString::fromUtf8("cbx_Packs_Action"));
        cbx_Packs_Action->setGeometry(QRect(250, 10, 151, 30));
        cbx_Packs_Action->setFont(font);
        lbl_Packs = new QLabel(frame_6);
        lbl_Packs->setObjectName(QString::fromUtf8("lbl_Packs"));
        lbl_Packs->setGeometry(QRect(10, 20, 81, 21));
        lbl_Packs->setFont(font);
        cbx_Packs_Type = new QComboBox(frame_6);
        cbx_Packs_Type->setObjectName(QString::fromUtf8("cbx_Packs_Type"));
        cbx_Packs_Type->setGeometry(QRect(100, 10, 131, 31));
        cbx_Packs_Type->setFont(font);
        frame_5 = new QFrame(make_rule);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(30, 70, 531, 51));
        frame_5->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     background:  rgb(225, 225, 225);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        edt_IP_end = new QLineEdit(frame_5);
        edt_IP_end->setObjectName(QString::fromUtf8("edt_IP_end"));
        edt_IP_end->setGeometry(QRect(431, 10, 81, 31));
        edt_IP_end->setFont(font);
        lbl_IP = new QLabel(frame_5);
        lbl_IP->setObjectName(QString::fromUtf8("lbl_IP"));
        lbl_IP->setGeometry(QRect(20, 20, 81, 21));
        lbl_IP->setFont(font);
        edt_IP_begin = new QLineEdit(frame_5);
        edt_IP_begin->setObjectName(QString::fromUtf8("edt_IP_begin"));
        edt_IP_begin->setGeometry(QRect(298, 10, 91, 31));
        edt_IP_begin->setFont(font);
        cbx_IP = new QComboBox(frame_5);
        cbx_IP->setObjectName(QString::fromUtf8("cbx_IP"));
        cbx_IP->setGeometry(QRect(168, 10, 111, 31));
        cbx_IP->setFont(font);
        lbl_IP_ = new QLabel(frame_5);
        lbl_IP_->setObjectName(QString::fromUtf8("lbl_IP_"));
        lbl_IP_->setGeometry(QRect(398, 20, 32, 20));
        lbl_IP_->setFont(font);
        cbx_kind_IP = new QComboBox(frame_5);
        cbx_kind_IP->setObjectName(QString::fromUtf8("cbx_kind_IP"));
        cbx_kind_IP->setGeometry(QRect(60, 10, 91, 31));
        cbx_kind_IP->setFont(font);
        frame_7 = new QFrame(make_rule);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setGeometry(QRect(30, 130, 531, 51));
        frame_7->setStyleSheet(QString::fromUtf8(" QFrame {\n"
"     background:  rgb(225, 225, 225);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"QLabel {\n"
" border-color: rgb(225, 225, 225);\n"
"}\n"
"QLineEdit {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;     \n"
"     background-color: rgb(255, 255, 255);\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        lbl_Process = new QLabel(frame_7);
        lbl_Process->setObjectName(QString::fromUtf8("lbl_Process"));
        lbl_Process->setGeometry(QRect(20, 20, 81, 21));
        lbl_Process->setFont(font);
        cbx_Process_kind = new QComboBox(frame_7);
        cbx_Process_kind->setObjectName(QString::fromUtf8("cbx_Process_kind"));
        cbx_Process_kind->setGeometry(QRect(110, 10, 131, 31));
        cbx_Process_kind->setFont(font);
        cbx_Process = new QComboBox(frame_7);
        cbx_Process->setObjectName(QString::fromUtf8("cbx_Process"));
        cbx_Process->setGeometry(QRect(260, 10, 181, 31));
        cbx_Process->setFont(font);
        edt_PID = new QLineEdit(frame_7);
        edt_PID->setObjectName(QString::fromUtf8("edt_PID"));
        edt_PID->setGeometry(QRect(458, 10, 51, 31));
        edt_PID->setFont(font);

        retranslateUi(make_rule);

        QMetaObject::connectSlotsByName(make_rule);
    } // setupUi

    void retranslateUi(QDialog *make_rule)
    {
        make_rule->setWindowTitle(QApplication::translate("make_rule", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\321\200\320\260\320\262\320\270\320\273\320\260", 0, QApplication::UnicodeUTF8));
        lbl_Name_Rule->setText(QApplication::translate("make_rule", "\320\230\320\274\321\217 \320\277\321\200\320\260\320\262\320\270\320\273\320\260", 0, QApplication::UnicodeUTF8));
        cbx_protocol->clear();
        cbx_protocol->insertItems(0, QStringList()
         << QApplication::translate("make_rule", "TCP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "UDP", 0, QApplication::UnicodeUTF8)
        );
        lbl_protocol->setText(QApplication::translate("make_rule", "\320\237\321\200\320\276\321\202\320\276\320\272\320\276\320\273", 0, QApplication::UnicodeUTF8));
        lbl_Filters->setText(QApplication::translate("make_rule", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262, \320\276\320\261\321\200\320\260\320\267\321\203\321\216\321\211\320\270\321\205 \320\237\321\200\320\260\320\262\320\270\320\273\320\276", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnAddFilter->setToolTip(QApplication::translate("make_rule", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200 \320\262 \320\277\321\200\320\260\320\262\320\270\320\273\320\276", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnAddFilter->setText(QApplication::translate("make_rule", "+", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_Rule_OK->setToolTip(QApplication::translate("make_rule", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_Rule_OK->setText(QApplication::translate("make_rule", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 ", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_Rule_Cancel->setToolTip(QApplication::translate("make_rule", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_Rule_Cancel->setText(QApplication::translate("make_rule", "\320\236\321\202\320\274\320\265\320\275\320\260  ", 0, QApplication::UnicodeUTF8));
        lbl_port_->setText(QApplication::translate("make_rule", "-", 0, QApplication::UnicodeUTF8));
        lbl_port->setText(QApplication::translate("make_rule", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        edt_Port_begin->setText(QString());
        cbx_kind_port->clear();
        cbx_kind_port->insertItems(0, QStringList()
         << QApplication::translate("make_rule", "\320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260(\320\275\320\276\320\274\320\265\321\200)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260(\320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217(\320\275\320\276\320\274\320\265\321\200)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217(\320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275)", 0, QApplication::UnicodeUTF8)
        );
        cbx_Packs_Action->clear();
        cbx_Packs_Action->insertItems(0, QStringList()
         << QApplication::translate("make_rule", "\320\277\321\200\320\276\320\277\321\203\321\201\320\272\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\277\320\265\321\200\320\265\320\275\320\260\320\277\321\200\320\260\320\262\320\273\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8)
        );
        lbl_Packs->setText(QApplication::translate("make_rule", "\320\237\320\260\320\272\320\265\321\202\321\213", 0, QApplication::UnicodeUTF8));
        cbx_Packs_Type->clear();
        cbx_Packs_Type->insertItems(0, QStringList()
         << QApplication::translate("make_rule", "\320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\262\321\205\320\276\320\264\321\217\321\211\320\270\320\265", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\270\321\201\321\205\320\276\320\264\321\217\321\211\320\270\320\265", 0, QApplication::UnicodeUTF8)
        );
        lbl_IP->setText(QApplication::translate("make_rule", "IP", 0, QApplication::UnicodeUTF8));
        cbx_IP->clear();
        cbx_IP->insertItems(0, QStringList()
         << QApplication::translate("make_rule", "\320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275", 0, QApplication::UnicodeUTF8)
        );
        lbl_IP_->setText(QApplication::translate("make_rule", "-", 0, QApplication::UnicodeUTF8));
        cbx_kind_IP->clear();
        cbx_kind_IP->insertItems(0, QStringList()
         << QApplication::translate("make_rule", "\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8)
        );
        lbl_Process->setText(QApplication::translate("make_rule", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201", 0, QApplication::UnicodeUTF8));
        cbx_Process_kind->clear();
        cbx_Process_kind->insertItems(0, QStringList()
         << QApplication::translate("make_rule", "\320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("make_rule", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 [PID]", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class make_rule: public Ui_make_rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKE_RULE_H
