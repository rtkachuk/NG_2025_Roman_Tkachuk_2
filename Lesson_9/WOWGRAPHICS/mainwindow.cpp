#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    m_timer->setInterval(50);
    //m_timer->start();

    m_scene = new QGraphicsScene(this);
    m_scene->setBackgroundBrush(Qt::white);
    ui->mainGraphs->setScene(m_scene);

    connect (ui->pushButton, &QPushButton::clicked, this, &MainWindow::initMap);
    connect (m_timer, &QTimer::timeout, this, &MainWindow::addSquare);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_W: playerPosY-=1; break;
    case Qt::Key_S: playerPosY+=1; break;
    case Qt::Key_A: playerPosX-=1; break;
    case Qt::Key_D: playerPosX+=1; break;
    }

    initMap();
}

void MainWindow::addSquare()
{

    m_scene->addRect(m_squarePos, 50, 50, 50, QPen(QColor(m_red, m_green, m_blue)));
    m_squarePos++;
    if (m_red < 256) {
        //m_red++;
        m_blue++;
        m_green++;
    } else {
        m_red = 0;
        m_blue = 0;
        m_green = 0;
    }
}

void MainWindow::initMap()
{
    QByteArray level = getMap();

    int row = 0;
    int column = 0;

    m_scene->clear();
    m_scene->setSceneRect(0, 0, map_X, map_Y);

    for (int index = 0; index < level.size(); index++) {
        if (level[index] != '\n') {
            QString item = "";
            switch (level[index]) {
            case '*': item = "space4.png"; break;
            case '#': item = "wall.png"; break;
            case '.': item = "floor.png"; break;
            }
            QGraphicsPixmapItem *cell = m_scene->addPixmap(QPixmap(":/images/" + item));
            cell->setPos(column, row);
            column += cell_size;
        } else {
            column = 0;
            row += cell_size;
        }
    }
    QGraphicsPixmapItem *cell = m_scene->addPixmap(QPixmap(":/images/player1.png"));
    cell->setPos(playerPosX * cell_size, playerPosY * cell_size);

}

QByteArray MainWindow::getMap()
{
    QByteArray level;
    QFile file(":/configs/map.txt");
    if (file.open(QIODevice::ReadOnly)) {
        level = file.readAll();
        file.close();
    }
    return level;
}
