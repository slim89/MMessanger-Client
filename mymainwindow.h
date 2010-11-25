#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <MApplicationWindow>

class HomePage;
class LoginPage;
class RegistrationPage;

class MyMainWindow : public MApplicationWindow
{
    Q_OBJECT
public:
    MyMainWindow();

private:
    HomePage *page1;
    LoginPage *page2;
    RegistrationPage *page3;
public slots:
    void StartSendThread(QString);
};

#endif // MAINWINDOW_H
