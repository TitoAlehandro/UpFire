/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 4. Feb 10:46:23 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpenRules;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QListWidget *lst_Menu;
    QStackedWidget *stc_WorkSpace;
    QWidget *page;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QToolButton *btnNotDefend;
    QToolButton *btnEnableDfnd;
    QToolButton *btnAll_Defend;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *lbl_enable_inf;
    QLabel *lbl_desable_def;
    QLabel *lbl_All_Def;
    QWidget *page_2;
    QGridLayout *gridLayout_5;
    QTabWidget *tab_settings;
    QWidget *tab_rules;
    QGridLayout *gridLayout_10;
    QTableWidget *tbl_Rules;
    QHBoxLayout *horizontalLayout;
    QToolButton *btn_AddRule;
    QToolButton *btn_DeleteRule;
    QWidget *tab_opt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(837, 550);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(837, 0));
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/k3b.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setIconSize(QSize(50, 50));
        actOpenRules = new QAction(MainWindow);
        actOpenRules->setObjectName(QString::fromUtf8("actOpenRules"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lst_Menu = new QListWidget(centralWidget);
        lst_Menu->setObjectName(QString::fromUtf8("lst_Menu"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lst_Menu->sizePolicy().hasHeightForWidth());
        lst_Menu->setSizePolicy(sizePolicy1);
        lst_Menu->setMinimumSize(QSize(32, 469));
        lst_Menu->setMaximumSize(QSize(115, 16777215));
        QFont font1;
        font1.setPointSize(10);
        lst_Menu->setFont(font1);
        lst_Menu->setStyleSheet(QString::fromUtf8(" QListWidget {    \n"
"     border: 2px solid #C4C4C3;\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        lst_Menu->setFrameShape(QFrame::StyledPanel);
        lst_Menu->setFrameShadow(QFrame::Sunken);
        lst_Menu->setLineWidth(1);
        lst_Menu->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lst_Menu->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lst_Menu->setTabKeyNavigation(false);
        lst_Menu->setTextElideMode(Qt::ElideLeft);
        lst_Menu->setMovement(QListView::Static);
        lst_Menu->setFlow(QListView::LeftToRight);
        lst_Menu->setLayoutMode(QListView::Batched);
        lst_Menu->setViewMode(QListView::IconMode);
        lst_Menu->setWordWrap(true);

        gridLayout_3->addWidget(lst_Menu, 0, 0, 1, 1);

        stc_WorkSpace = new QStackedWidget(centralWidget);
        stc_WorkSpace->setObjectName(QString::fromUtf8("stc_WorkSpace"));
        stc_WorkSpace->setMinimumSize(QSize(32, 0));
        stc_WorkSpace->setFont(font);
        stc_WorkSpace->setStyleSheet(QString::fromUtf8(" QStackedWidget {    \n"
"     border: 2px solid #C4C4C3;\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        stc_WorkSpace->setFrameShape(QFrame::StyledPanel);
        stc_WorkSpace->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(88, 56, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        frame_2 = new QFrame(page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(460, 50));
        frame_2->setLayoutDirection(Qt::LeftToRight);
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	 background: #C2C7CB;/*rgb(255, 222, 210)\n"
"/* border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border: 2px solid #C4C4C3;\n"
"     border-radius: 4px;  \n"
"     padding: 2px;\n"
"}"));
        frame_2->setInputMethodHints(Qt::ImhNone);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_9 = new QGridLayout(frame_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        btnNotDefend = new QToolButton(frame_2);
        btnNotDefend->setObjectName(QString::fromUtf8("btnNotDefend"));
        btnNotDefend->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/unlockred.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnNotDefend->setIcon(icon1);
        btnNotDefend->setIconSize(QSize(25, 25));
        btnNotDefend->setCheckable(true);
        btnNotDefend->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_8->addWidget(btnNotDefend, 0, 0, 1, 1);

        btnEnableDfnd = new QToolButton(frame_2);
        btnEnableDfnd->setObjectName(QString::fromUtf8("btnEnableDfnd"));
        btnEnableDfnd->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/lockgreen.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEnableDfnd->setIcon(icon2);
        btnEnableDfnd->setIconSize(QSize(25, 25));
        btnEnableDfnd->setCheckable(true);
        btnEnableDfnd->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_8->addWidget(btnEnableDfnd, 0, 1, 1, 1);

        btnAll_Defend = new QToolButton(frame_2);
        btnAll_Defend->setObjectName(QString::fromUtf8("btnAll_Defend"));
        btnAll_Defend->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/orange-folder-locked.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAll_Defend->setIcon(icon3);
        btnAll_Defend->setIconSize(QSize(25, 25));
        btnAll_Defend->setCheckable(true);
        btnAll_Defend->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_8->addWidget(btnAll_Defend, 0, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(87, 56, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        frame = new QFrame(page);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMinimumSize(QSize(662, 301));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"/*	 background: #C2C7CB;/*rgb(255, 222, 210)*/\n"
"     background: rgb(255, 247, 207);\n"
"/* border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border: 2px solid #C4C4C3;\n"
"     border-radius: 4px;  \n"
"     padding: 2px;\n"
"}\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lbl_enable_inf = new QLabel(frame);
        lbl_enable_inf->setObjectName(QString::fromUtf8("lbl_enable_inf"));

        gridLayout_2->addWidget(lbl_enable_inf, 2, 0, 1, 1);

        lbl_desable_def = new QLabel(frame);
        lbl_desable_def->setObjectName(QString::fromUtf8("lbl_desable_def"));

        gridLayout_2->addWidget(lbl_desable_def, 1, 0, 1, 1);

        lbl_All_Def = new QLabel(frame);
        lbl_All_Def->setObjectName(QString::fromUtf8("lbl_All_Def"));

        gridLayout_2->addWidget(lbl_All_Def, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 3);

        stc_WorkSpace->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_5 = new QGridLayout(page_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tab_settings = new QTabWidget(page_2);
        tab_settings->setObjectName(QString::fromUtf8("tab_settings"));
        tab_settings->setFont(font1);
        tab_settings->setStyleSheet(QString::fromUtf8("\n"
"\n"
" QTabWidget::tab-bar {\n"
"     left: 2px; /* \321\201\320\264\320\262\320\270\320\263\320\260\320\265\320\274 \320\262\320\277\321\200\320\260\320\262\320\276 \320\275\320\260 5px */\n"
" }\n"
"\n"
" /* \320\237\321\200\320\270\320\274\320\265\320\275\321\217\320\265\320\274 \321\201\321\202\320\270\320\273\321\214 \320\272\320\276 \320\262\320\272\320\273\320\260\320\264\320\272\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\321\217 \321\201\321\203\320\261\321\215\320\273\320\265\320\274\320\265\320\275\321\202 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 tab. \320\236\320\261\321\200\320\260\321\202\320\270\321\202\320\265 \320\262\320\275\320\270\320\274\320\260\320\275\320\270\320\265 \320\275\320\260 \321\202\320\276, \321\207\321\202\320\276\n"
"     \320\276\320\275\320\276 \321\207\320\270\321\202\320\260\320\265\321\202\321\201\321\217 \320\272\320\260\320\272 QTabBar, \320\260 _\320\275\320\265_ QTabWidget */\n"
" QTabBar::tab "
                        "{\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271 \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"\n"
" QTabBar::tab:selected, QTabBar::tab:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                 stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     border-color: #9B9B9B;\n"
"    border-bottom-color: #C2C7CB; /* \321\202\320\260\320\272\320\276\320\271"
                        " \320\266\320\265 \321\206\320\262\320\265\321\202 \320\272\320\260\320\272 \321\203 \320\277\320\260\320\275\320\265\320\273\320\270 */\n"
" }\n"
"\n"
" QTabBar::tab:!selected {\n"
"     margin-top: 2px; /* \320\264\320\265\320\273\320\260\320\265\320\274 \320\275\320\265\320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\262\320\272\320\273\320\260\320\264\320\272\320\270 \320\274\320\265\320\275\321\214\321\210\320\265 */\n"
" }"));
        tab_rules = new QWidget();
        tab_rules->setObjectName(QString::fromUtf8("tab_rules"));
        gridLayout_10 = new QGridLayout(tab_rules);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        tbl_Rules = new QTableWidget(tab_rules);
        tbl_Rules->setObjectName(QString::fromUtf8("tbl_Rules"));
        tbl_Rules->setFont(font1);
        tbl_Rules->setStyleSheet(QString::fromUtf8(" QTableWidget {    \n"
"     border: 2px solid #C4C4C3;\n"
"     border-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }"));
        tbl_Rules->setGridStyle(Qt::SolidLine);

        gridLayout_10->addWidget(tbl_Rules, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_AddRule = new QToolButton(tab_rules);
        btn_AddRule->setObjectName(QString::fromUtf8("btn_AddRule"));
        btn_AddRule->setFont(font1);
        btn_AddRule->setLayoutDirection(Qt::LeftToRight);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_AddRule->setIcon(icon4);
        btn_AddRule->setIconSize(QSize(25, 25));
        btn_AddRule->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btn_AddRule->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(btn_AddRule);

        btn_DeleteRule = new QToolButton(tab_rules);
        btn_DeleteRule->setObjectName(QString::fromUtf8("btn_DeleteRule"));
        btn_DeleteRule->setFont(font1);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/edit_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_DeleteRule->setIcon(icon5);
        btn_DeleteRule->setIconSize(QSize(25, 25));
        btn_DeleteRule->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btn_DeleteRule);


        gridLayout_10->addLayout(horizontalLayout, 1, 0, 1, 1);

        tab_settings->addTab(tab_rules, QString());
        tab_opt = new QWidget();
        tab_opt->setObjectName(QString::fromUtf8("tab_opt"));
        tab_settings->addTab(tab_opt, QString());

        gridLayout_5->addWidget(tab_settings, 0, 0, 1, 1);

        stc_WorkSpace->addWidget(page_2);

        gridLayout_3->addWidget(stc_WorkSpace, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 837, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stc_WorkSpace->setCurrentIndex(0);
        tab_settings->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UPFire - \320\244\320\260\320\265\321\200\320\262\320\276\320\273", 0, QApplication::UnicodeUTF8));
        actOpenRules->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnNotDefend->setToolTip(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\216 \320\277\320\260\320\272\320\265\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnNotDefend->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnEnableDfnd->setToolTip(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\216 \320\277\320\260\320\272\320\265\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnEnableDfnd->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", 0, QApplication::UnicodeUTF8));
        btnEnableDfnd->setShortcut(QString());
#ifndef QT_NO_TOOLTIP
        btnAll_Defend->setToolTip(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\277\320\276\320\273\320\275\321\203\321\216 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\321\216 \320\277\320\260\320\272\320\265\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnAll_Defend->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\260\321\217 \320\267\320\260\321\211\320\270\321\202\320\260", 0, QApplication::UnicodeUTF8));
        lbl_enable_inf->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#ff5500;\">\320\227\320\260\321\211\320\270\321\202\320\260 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\260.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; color:#ff5500;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-siz"
                        "e:10pt; color:#000000;\">\320\235\320\260 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\265 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\260 \320\267\320\260\321\211\320\270\321\202\320\260.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\241\320\265\321\202\320\265\320\262\320\276\320\271 \321\202\321\200\320\260\321\204\320\270\320\272 \321\204\320\270\320\273\321\214\321\202\321\200\321\203\320\265\321\202\321\201\321\217 \320\262 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\270 \321\201 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\274\320\270 \320\277"
                        "\321\200\320\260\320\262\320\270\320\273\320\260\320\274\320\270. </span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#000000;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\237\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 \320\277\321\200\320\276\320\270\321\201\321\205\320\276\320\264\320\270\321\202 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270 \320\262\321\201\320\265\321\205 \320\277\320\260\320\272\320\265\321\202\320\276\320\262.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        lbl_desable_def->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#ff5500;\">\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\260!!!</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; color:#ff5500;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\""
                        " font-size:10pt; color:#000000;\">\320\235\320\260 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\265 \320\276\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\260 \320\267\320\260\321\211\320\270\321\202\320\260!!!</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\241\320\265\321\202\320\265\320\262\320\276\320\271 \321\202\321\200\320\260\321\204\320\270\320\272 \320\270\320\263\320\275\320\276\321\200\320\270\321\200\321\203\320\265\321\202\321\201\321\217. \320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270 \320\277\320\260\320\272\320\265\321\202\320\276\320\262 \320\275\320\265 \320\277\321"
                        "\200\320\276\320\270\321\201\321\205\320\276\320\264\320\270\321\202.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#000000;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\225\321\201\320\273\320\270 \320\222\320\260\320\274 \320\275\320\265 \320\275\321\203\320\266\320\275\320\276 \320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\201\320\265\321\202\320\265\320\262\321\213\320\265 \320\277\320\260\320\272\320\265\321\202\321\213,</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\321\200\320\265\320\272\320\276\320"
                        "\274\320\265\320\275\320\264\321\203\320\265\321\202\321\201\321\217 \320\262\320\272\320\273\321\216\321\207\320\260\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203 \321\201 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\275\321\213\320\274 \320\277\321\200\320\260\320\262\320\270\320\273\320\276\320\274 &quot;\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\277\320\260\320\272\320\265\321\202\320\276\320\262&quot;. </span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\222 \320\274\320\276\320\274\320\265\320\275\321\202, \320\272\320\276\320\263\320\264\320\260 \320\272\320\276"
                        "\320\274\320\277\321\214\321\216\321\202\320\265\321\200 \320\277\320\276\320\264\320\262\320\265\321\200\320\263\320\275\320\265\321\202\321\201\321\217 \320\276\320\277\320\260\321\201\320\275\320\276\321\201\321\202\320\270,</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\222\321\213 \321\201\320\274\320\276\320\266\320\265\321\202\320\265 \320\270\320\264\320\265\320\275\321\202\320\270\321\204\320\270\321\206\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\203\320\263\321\200\320\276\320\267\321\213 \320\270\320\267 \320\266\321\203\321\200\320\275\320\260\320\273\320\260 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\320\270.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; "
                        "-qt-block-indent:0; text-indent:0px; font-size:10pt; color:#000000;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#000000;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        lbl_All_Def->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; color:#ff5500;\">\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\260 \320\277\320\276\320\273\320\275\320\260\321\217 \320\267\320\260\321\211\320\270\321\202\320\260.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:14pt; color:#ff5500;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-ind"
                        "ent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\235\320\260 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\265 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\260 \320\277\320\276\320\273\320\275\320\260\321\217 \320\267\320\260\321\211\320\270\321\202\320\260.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\241\320\265\321\202\320\265\320\262\320\276\320\271 \321\202\321\200\320\260\321\204\320\270\320\272 \320\261\320\273\320\276\320\272\320\270\321\200\321\203\320\265\321\202\321\201\321\217 \320\270 \321\204\320\270\320\273\321\214\321\202\321\200\321\203\320\265\321\202\321\201\321\217.</span"
                        "></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt; color:#000000;\"></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\242\320\260\320\272\320\276\320\271 \321\200\320\265\320\266\320\270\320\274 \320\267\320\260\321\211\320\270\321\202\321\213 \321\200\320\265\320\272\320\276\320\274\320\265\320\275\320\264\321\203\320\265\321\202\321\201\321\217 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214, </span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#000000;\">\320\272\320\276\320\263\320\264\320\260 \320\276\321\202\321\201\321\203\321\202\321\201"
                        "\321\202\320\262\321\203\320\265\321\202 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276\321\201\321\202\321\214 \320\262\321\213\321\205\320\276\320\264\320\260 \320\262 \320\270\320\275\321\202\320\265\321\200\320\275\320\265\321\202 \320\270\320\273\320\270 \320\272\320\260\320\272\320\276\320\271-\320\273\320\270\320\261\320\276 \320\264\321\200\321\203\320\263\320\276\320\271 \321\201\320\265\321\202\320\265\320\262\320\276\320\271 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\320\270.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_AddRule->setToolTip(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_AddRule->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btn_DeleteRule->setToolTip(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276 \321\204\320\270\320\273\321\214\321\202\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btn_DeleteRule->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\276", 0, QApplication::UnicodeUTF8));
        tab_settings->setTabText(tab_settings->indexOf(tab_rules), QApplication::translate("MainWindow", "\320\235\320\260\320\261\320\276\321\200 \320\277\321\200\320\260\320\262\320\270\320\273", 0, QApplication::UnicodeUTF8));
        tab_settings->setTabText(tab_settings->indexOf(tab_opt), QApplication::translate("MainWindow", "\320\230\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
