#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QScreen>
#include <QMouseEvent>
#include <QTimer>
#include <QList>
#include <QPixmap>
#include <QString>
#include <QPainter>
#include <QVector>
#include <QPushButton>
#include <QContextMenuEvent>
#include <QMenu>
#include <stdlib.h>

enum Action{STAY,JUMP};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    //鼠标移动
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    //绘制
    void paintEvent(QPaintEvent* event) override;

    void contextMenuEvent(QContextMenuEvent *event);

private:
    bool showCloseButton;
    //鼠标移动
    QPoint lastMosuePoint;

    //动作类型
    Action State;

    //动画
    QVector<QList<QPixmap>> animations;
    int currentAnimation;
    QTimer* animationTimer;
    QTimer* randTimer;
};
#endif // MAINWINDOW_H
