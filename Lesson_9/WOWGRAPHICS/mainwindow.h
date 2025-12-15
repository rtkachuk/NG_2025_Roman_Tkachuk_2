#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>

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

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void addSquare();
    void initMap();

private:
    QByteArray getMap();

    int m_squarePos = 0;
    int m_red = 0;
    int m_green = 0;
    int m_blue = 0;
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    QTimer *m_timer;

    const int map_Y = 600;
    const int map_X = 800;
    const int cell_size = 40;

    int playerPosX = 6;
    int playerPosY = 5;

};
#endif // MAINWINDOW_H
