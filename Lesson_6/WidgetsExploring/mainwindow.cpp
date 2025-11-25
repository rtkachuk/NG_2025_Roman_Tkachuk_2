#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->b_clear, &QPushButton::clicked, this, &MainWindow::clearScreen);
    connect (ui->t_userText, &QTextEdit::textChanged, this, &MainWindow::UpdateLcdInfo);
    connect (ui->dial, &QDial::valueChanged, ui->progressBar, &QProgressBar::setValue);
    connect (ui->dial, &QDial::valueChanged, ui->sl_hor, &QSlider::setValue);
    connect (ui->dial, &QDial::valueChanged, ui->sl_vert, &QSlider::setValue);
    connect (ui->dial, &QDial::valueChanged, ui->sb_number, &QSpinBox::setValue);

    ui->lw_homeDir->addItems(getHomeFolderContents());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearScreen()
{
    ui->t_userText->clear();
}

void MainWindow::UpdateLcdInfo()
{
    ui->lcd_wordCounter->display(calculateSymbols());
}

int MainWindow::calculateSymbols()
{
    QString text = ui->t_userText->toPlainText();
    qDebug() << "Amount of symbols: " << text.size();
    ui->statusbar->showMessage("Amount of symbols: " + QString::number(text.size()));
    return text.size();
}

QStringList MainWindow::getHomeFolderContents()
{
    return QDir::home().entryList();
}
