/********************************************************************************
** Form generated from reading UI file 'taskwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWINDOW_H
#define UI_TASKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnGetItems;
    QListWidget *listItems;
    QCheckBox *cbQuizes;
    QCheckBox *cbLessons;
    QLabel *labelItemList;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTopic;
    QTextEdit *inputChat;
    QLineEdit *inputMessage;
    QPushButton *btnSend;
    QLabel *labelLoggedUsername;
    QGroupBox *groupBox;
    QPushButton *btnCheckAnswer;
    QLabel *labelTitle;
    QTextEdit *inputTitle;
    QLabel *labelContent;
    QTextEdit *inputContent;
    QLabel *labelLearnet;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TaskWindow)
    {
        if (TaskWindow->objectName().isEmpty())
            TaskWindow->setObjectName(QStringLiteral("TaskWindow"));
        TaskWindow->resize(1297, 741);
        centralwidget = new QWidget(TaskWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btnGetItems = new QPushButton(centralwidget);
        btnGetItems->setObjectName(QStringLiteral("btnGetItems"));
        btnGetItems->setGeometry(QRect(150, 610, 171, 61));
        QFont font;
        font.setPointSize(20);
        btnGetItems->setFont(font);
        listItems = new QListWidget(centralwidget);
        listItems->setObjectName(QStringLiteral("listItems"));
        listItems->setGeometry(QRect(20, 210, 301, 381));
        cbQuizes = new QCheckBox(centralwidget);
        cbQuizes->setObjectName(QStringLiteral("cbQuizes"));
        cbQuizes->setGeometry(QRect(20, 640, 131, 31));
        cbQuizes->setFont(font);
        cbQuizes->setChecked(true);
        cbLessons = new QCheckBox(centralwidget);
        cbLessons->setObjectName(QStringLiteral("cbLessons"));
        cbLessons->setGeometry(QRect(20, 610, 131, 21));
        cbLessons->setFont(font);
        cbLessons->setChecked(true);
        labelItemList = new QLabel(centralwidget);
        labelItemList->setObjectName(QStringLiteral("labelItemList"));
        labelItemList->setGeometry(QRect(20, 160, 211, 41));
        labelItemList->setFont(font);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(839, 129, 431, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelTopic = new QLabel(verticalLayoutWidget);
        labelTopic->setObjectName(QStringLiteral("labelTopic"));
        labelTopic->setFont(font);

        verticalLayout->addWidget(labelTopic);

        inputChat = new QTextEdit(verticalLayoutWidget);
        inputChat->setObjectName(QStringLiteral("inputChat"));

        verticalLayout->addWidget(inputChat);

        inputMessage = new QLineEdit(verticalLayoutWidget);
        inputMessage->setObjectName(QStringLiteral("inputMessage"));

        verticalLayout->addWidget(inputMessage);

        btnSend = new QPushButton(verticalLayoutWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setFont(font);

        verticalLayout->addWidget(btnSend);

        labelLoggedUsername = new QLabel(centralwidget);
        labelLoggedUsername->setObjectName(QStringLiteral("labelLoggedUsername"));
        labelLoggedUsername->setGeometry(QRect(20, 110, 631, 41));
        labelLoggedUsername->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(330, 150, 501, 521));
        btnCheckAnswer = new QPushButton(groupBox);
        btnCheckAnswer->setObjectName(QStringLiteral("btnCheckAnswer"));
        btnCheckAnswer->setGeometry(QRect(300, 410, 191, 61));
        btnCheckAnswer->setFont(font);
        labelTitle = new QLabel(groupBox);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(10, 40, 471, 41));
        labelTitle->setFont(font);
        inputTitle = new QTextEdit(groupBox);
        inputTitle->setObjectName(QStringLiteral("inputTitle"));
        inputTitle->setGeometry(QRect(10, 90, 481, 81));
        labelContent = new QLabel(groupBox);
        labelContent->setObjectName(QStringLiteral("labelContent"));
        labelContent->setGeometry(QRect(10, 190, 471, 41));
        labelContent->setFont(font);
        inputContent = new QTextEdit(groupBox);
        inputContent->setObjectName(QStringLiteral("inputContent"));
        inputContent->setGeometry(QRect(10, 250, 481, 131));
        labelLearnet = new QLabel(centralwidget);
        labelLearnet->setObjectName(QStringLiteral("labelLearnet"));
        labelLearnet->setGeometry(QRect(20, 10, 241, 51));
        QFont font1;
        font1.setPointSize(30);
        labelLearnet->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 721, 41));
        QFont font2;
        font2.setPointSize(20);
        font2.setItalic(true);
        label_2->setFont(font2);
        TaskWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TaskWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1297, 22));
        TaskWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TaskWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TaskWindow->setStatusBar(statusbar);

        retranslateUi(TaskWindow);

        QMetaObject::connectSlotsByName(TaskWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TaskWindow)
    {
        TaskWindow->setWindowTitle(QApplication::translate("TaskWindow", "Learning window", Q_NULLPTR));
        btnGetItems->setText(QApplication::translate("TaskWindow", "Get items", Q_NULLPTR));
        cbQuizes->setText(QApplication::translate("TaskWindow", "Quizes", Q_NULLPTR));
        cbLessons->setText(QApplication::translate("TaskWindow", "Lessons", Q_NULLPTR));
        labelItemList->setText(QApplication::translate("TaskWindow", "List of items", Q_NULLPTR));
        labelTopic->setText(QApplication::translate("TaskWindow", "Discussion about ", Q_NULLPTR));
        btnSend->setText(QApplication::translate("TaskWindow", "Send", Q_NULLPTR));
        labelLoggedUsername->setText(QApplication::translate("TaskWindow", "Currently logged as : ", Q_NULLPTR));
        groupBox->setTitle(QString());
        btnCheckAnswer->setText(QApplication::translate("TaskWindow", "Check answer", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("TaskWindow", "Title/Question", Q_NULLPTR));
        labelContent->setText(QApplication::translate("TaskWindow", "Lesson/Answer", Q_NULLPTR));
        labelLearnet->setText(QApplication::translate("TaskWindow", "Learnet", Q_NULLPTR));
        label_2->setText(QApplication::translate("TaskWindow", "The network that helps you learn about computer networks", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TaskWindow: public Ui_TaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWINDOW_H
