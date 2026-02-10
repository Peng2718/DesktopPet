#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    //窗口配置
    setWindowFlags(Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint|Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    resize(200,200);
    QScreen* screen = QApplication::primaryScreen();
    QRect screenRect = screen->availableGeometry();
    move(screenRect.width()-width()-20,screenRect.height()-height()-20);

    setMouseTracking(true);
    animations.resize(2);
    State = Action::STAY;
    //动画
    for(int i=1;i<=151;i++){
        //保证格式
        QString path = QString("F:/Pet制作记录/动画图片1/pet%1.png").arg(i,4,10,QChar('0'));
        if(!QPixmap(path)){
            qDebug()<<"error";
            exit(-1);
        }
        animations[0].append(QPixmap(path).scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    for(int i=1;i<=151;i++){
        //保证格式
        QString path = QString("F:/Pet制作记录/动画图片2/pet_walk%1.png").arg(i,4,10,QChar('0'));
        if(!QPixmap(path)){
            qDebug()<<"error";
            exit(-1);
        }
        animations[1].append(QPixmap(path).scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    currentAnimation = 0;
    //定时器(每100ms切换一帧)
    animationTimer = new QTimer(this);
    connect(animationTimer,&QTimer::timeout,this,[=](){
        currentAnimation = (currentAnimation+1)%animations[0].size();
        update();//触发重绘
    });
    animationTimer->start(30);

    randTimer = new QTimer(this);
    connect(randTimer,&QTimer::timeout,this,[=](){
        int randState = rand()%2;
        if(randState==0){
            State=Action::STAY;
        }
        if(randState==1){
            State=Action::JUMP;
        }
        update();
    });
    randTimer->start(5000);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent* event){
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform); // 抗锯齿
    // 绘制当前帧（居中显示）
    switch (State) {
    // case WALK:
    //     painter.drawPixmap(rect().center() - animations[0][currentAnimation].rect().center(),
    //                        animations[0][currentAnimation]);
    //     break;
    case JUMP:
        painter.drawPixmap(rect().center() - animations[1][currentAnimation].rect().center(),
                           animations[1][currentAnimation]);
        break;
    case STAY:
        painter.drawPixmap(rect().center() - animations[0][currentAnimation].rect().center(),
                           animations[0][currentAnimation]);
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event){
    if(event->button()==Qt::LeftButton){
        lastMosuePoint = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event){
    if(event->buttons()==Qt::LeftButton){
        move(event->globalPos()-lastMosuePoint);
        event->accept();
    }
}
