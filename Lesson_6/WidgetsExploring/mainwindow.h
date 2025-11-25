#pragma once

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void clearScreen();
    void UpdateLcdInfo();

private:
    Ui::MainWindow *ui;

    int calculateSymbols();
};
