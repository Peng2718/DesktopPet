#include "mainwindow.h"
#include <QApplication>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    resize(200,200);
    QScreen* screen = QApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    move(screenRect.width()-width()-20,screenRect.height()-height()-20);

    setMouseTracking(true);
}

MainWindow::~MainWindow()
{

}
