<<<<<<< HEAD
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

private:
    //鼠标移动
    QPoint lastMosuePoint;

    //动画
    QList<QPixmap> animations;
    int currentAnimation;
    QTimer* animationTimer;
};
#endif // MAINWINDOW_H
=======
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

private:
    //鼠标移动
    QPoint lastMosuePoint;

    //动画
    QList<QPixmap> animations;
    int currentAnimation;
    QTimer* animationTimer;
};
#endif // MAINWINDOW_H
>>>>>>> 9e0f3cb6b8cb0397afd00cf45b3417da3856af0c
