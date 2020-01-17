#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class TaskWindow;
}

class TaskWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TaskWindow(QWidget *parent = 0);
    ~TaskWindow();


private slots:
    void on_btnGetItems_clicked();
    void on_listItems_currentRowChanged(int currentRow);
    void on_btnCheckAnswer_clicked();
    void on_btnSend_clicked();
    void getChat();

private:
    std::list<MyTuple> allLessons, allQuizes;
    void getLessons();
    void getQuizes();

    std::list<MyTuple>::iterator getLessonIt(std::string s);
    std::list<MyTuple>::iterator getQuizIt(std::string);
    bool isQuiz;
    Ui::TaskWindow *ui;
    QString currRightAnswer;
    QString currTitle;
};

#endif // TASKWINDOW_H
