#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

extern bool adminAccessGranted;

namespace Ui {
class loginWindow;
}

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void on_loginButton_clicked();

    void on_closeWindow_clicked();

private:
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H
