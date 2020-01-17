#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "client.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Client::ConnectToServer();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    char username[256], password[256], msg[256];
    memset(username, 0, 256);
    memset(password, 0, 256);
    memset(msg, 0, 256);

    strcpy(username, ui->leUser->text().toStdString().c_str());
    strcpy(password, ui->lePass->text().toStdString().c_str());
    sprintf(msg, "%s;%s", username, password);

    write(Client::sd, msg, 256);
    if (0 >= read(Client::sd, msg, 256))
    {
        printf("Read error!");
        fflush(stdout);
        return;
    }
    if (!strcmp(msg, CMD_LOGIN_YES))
    {
        TaskWindow* window = new TaskWindow();
        Client::username = ui->leUser->text();
        printf("#%s#", Client::username.toStdString().c_str());
        window->show();
        this->hide();
    }
    if (!strcmp(msg, CMD_LOGIN_NO))
    {
        this->setEnabled(false);
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setText("Credentials invalid!");
        msgBox->setStandardButtons(QMessageBox::Ok);
        msgBox->exec();
        this->setEnabled(true);
    }
}
