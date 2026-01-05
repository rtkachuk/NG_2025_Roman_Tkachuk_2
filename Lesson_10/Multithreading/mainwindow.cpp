#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);

    m_manager = new Manager(this);

    ui->sb_number->setRange(0, 10000);


    connect (m_timer, &QTimer::timeout, this, &MainWindow::increaseSecond);
    connect (ui->b_timerStart, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect (ui->b_startThreads, &QPushButton::clicked, this, &MainWindow::startManager);
}

MainWindow::~MainWindow()
{
    m_timer->stop();
    delete m_timer;
    delete ui;
}

void MainWindow::increaseSecond()
{
    ui->lcdNumber->display(ui->lcdNumber->value() + 1);
}

void MainWindow::startTimer()
{
    m_timer->start();
}

void MainWindow::startManager()
{
    m_manager->setAmountOfThreads(ui->sb_threadsAmount->value());
    m_manager->startJob(ui->sb_number->value());
}
