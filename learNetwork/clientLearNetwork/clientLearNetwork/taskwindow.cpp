#include "taskwindow.h"
#include "ui_taskwindow.h"
#include <QMessageBox>
#include <QTimer>
#define TIMEOUT_REFRESH_CHAT 2000
TaskWindow::TaskWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TaskWindow)
{
    ui->setupUi(this);
    ui->labelLoggedUsername->setText(Client::username);
    this->update();
    ui->listItems->setSelectionMode(QListWidget::SingleSelection);
    ui->btnCheckAnswer->setEnabled(false);

    getLessons();
    getQuizes();

    QTimer* timer = new QTimer();
    timer->start();
    timer->setInterval(TIMEOUT_REFRESH_CHAT);
    connect(timer, SIGNAL(timeout()), this, SLOT(getChat()));
}

TaskWindow::~TaskWindow()
{
    delete ui;
}
void TaskWindow::on_btnGetItems_clicked()
{
    ui->listItems->clear();
    printf("No lessons: %d; No quizes : %d", (int) allLessons.size(), (int) allQuizes.size());
    fflush(stdout);
    if (ui->cbLessons->isChecked())
        for (auto it = allLessons.begin(); it != allLessons.end(); ++it)
            ui->listItems->addItem(QString(it->first.c_str()));
    if (ui->cbQuizes->isChecked())
        for (auto it = allQuizes.begin(); it != allQuizes.end(); ++it)
        {
            ui->listItems->addItem(QString(it->first.c_str()));
            printf("---->%s<---\n", it->first.c_str());
            fflush(stdout);
        }
    //ui->listItems->setCurrentRow(0);
}
void TaskWindow::getLessons()
{
    write(Client::sd, CMD_GET_LESSONS, 256);
    char msg[1024];
    memset(msg, 0, 1024);
    for (read(Client::sd, msg, 1024); strcmp(msg, CMD_FINISH); read(Client::sd, msg, 1024))
    {
        allLessons.push_back(MyTuple(msg));
    }
}
void TaskWindow::getQuizes()
{
    write(Client::sd, CMD_GET_QUIZES, 256);
    char msg[1024];
    memset(msg, 0, 1024);
    for (read(Client::sd, msg, 1024); strcmp(msg, CMD_FINISH); read(Client::sd, msg, 1024))
    {
        allQuizes.push_back(MyTuple(msg));
    }
}
void TaskWindow::on_listItems_currentRowChanged(int currentRow)
{
    std::list<MyTuple>::iterator it;
    QString selected = ui->listItems->currentItem()->text();
    ui->labelTopic->setText(QString("Discussion about ").append(selected));
    if (selected.contains("Lesson"))
    {
        it = getLessonIt(selected.toStdString());
        ui->labelTitle->setText(QString::fromStdString(it->first));
        this->currTitle = QString::fromStdString(it->first);

        ui->inputTitle->setReadOnly(false);
        ui->inputTitle->setText(QString::fromStdString(it->second));
        ui->inputTitle->setReadOnly(true);

        ui->labelContent->setText(QString("Content"));
        ui->inputContent->setText(QString::fromStdString(it->third));
        ui->btnCheckAnswer->setEnabled(false);
    }
    else if (selected.contains("Quiz"))
    {
        it = getQuizIt(selected.toStdString());
        ui->labelTitle->setText(QString::fromStdString(it->first));
        this->currTitle = QString::fromStdString(it->first);

        ui->inputTitle->setReadOnly(false);
        ui->inputTitle->setText(QString::fromStdString(it->second));
        ui->inputTitle->setReadOnly(true);

        ui->inputContent->setText("");
        ui->labelContent->setText("Write your answer here");
        this->currRightAnswer = QString::fromStdString(it->third);
        ui->btnCheckAnswer->setEnabled(true);
    }
    this->getChat();
}
std::list<MyTuple>::iterator TaskWindow::getLessonIt(std::string s)
{
    std::list<MyTuple>::iterator it;
    for (it = allLessons.begin(); it != allLessons.end(); ++it)
        if (it->first == s)
            break;
    return it;
}
std::list<MyTuple>::iterator TaskWindow::getQuizIt(std::string s)
{
    std::list<MyTuple>::iterator it;
    for (it = allQuizes.begin(); it != allQuizes.end(); ++it)
        if (it->first == s)
            break;
    return it;
}
void TaskWindow::on_btnCheckAnswer_clicked()
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setText(currRightAnswer == ui->inputContent->toPlainText() ? "Correct answer!": "Your answer is incorrect!");
    msgBox->exec();
}
void TaskWindow::getChat()
{
    char msg[256];
    memset(msg, 0, 256);
    write(Client::sd, CMD_GET_CHAT, 256);
    strcpy(msg, currTitle.toStdString().c_str());
    write(Client::sd, msg,256);
    write(Client::sd, Client::username.toStdString().c_str(), 256);

    QString s("");
    for (read(Client::sd, msg, 256); strcmp(msg, CMD_FINISH); read(Client::sd, msg, 256))
    {
        s.append(QString(msg));
    }
    ui->inputChat->setText(s);
}
void TaskWindow::on_btnSend_clicked()
{
    if (0 == ui->listItems->selectedItems().count())
        return;
    write(Client::sd, CMD_SEND_MSG, 256);
    write(Client::sd, this->currTitle.toStdString().c_str(), 256);
    write(Client::sd, Client::username.toStdString().c_str(), 256);
    write(Client::sd, ui->inputMessage->text().toStdString().c_str(), 256);
    ui->inputMessage->setText("");
}
