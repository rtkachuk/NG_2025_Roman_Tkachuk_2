#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_aiWorker = new aiWorker();
    ui->te_aiAnswer->setReadOnly(true);

    connect (m_aiWorker, &aiWorker::answerReady, this, &MainWindow::aiAnswered);
    connect (ui->pb_ask, &QPushButton::clicked, this, &MainWindow::askAi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::askAi()
{
    m_aiWorker->askAI(ui->te_userMessage->toPlainText());
}

void MainWindow::aiAnswered(QString text)
{
    ui->te_aiAnswer->setPlainText(text);
}
