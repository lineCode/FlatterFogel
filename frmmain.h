#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QOpenGLWidget>
#include <QStandardPaths>
#include <QDebug>
#include <QPainter>
#include <QTimer>
#include <QColor>
#include <QVector>
#include <QMessageBox>
#include <QThread>
#include <QMouseEvent>
#include <QPixmap>
#include <QFont>
#include <QFile>
#include <QTime>
#include <QFontDatabase>
#include <QFont>
#include "translation.h"
#include "blus.h"
#include "player.h"
#include "obstacle.h"
#include "shop.h"
#include "window.h"
#include "pxan.h"
#include "star.h"

namespace Ui {
class FrmMain;
}

class FrmMain : public QOpenGLWidget
{
    Q_OBJECT
private slots:
    void on_tdraw();
    void on_tmain();
    void on_tObst();
    void on_tEvent();
    void on_shopBack();
    void on_shopMsg(QString msg);
    void on_shopBuy(int amount);
    void on_trevive();
    void on_treviveL();
    void on_tboost();
    void on_tAn();
    void on_tTilt();
    void on_tChange();
    void on_tflag();
    void on_tstar();
public:
    explicit FrmMain(QOpenGLWidget *parent = 0);
    ~FrmMain();

private:
    Ui::FrmMain *ui;
    QTimer *t_draw;
    QTimer *t_main;
    QTimer *t_obst;
    QTimer *t_event;
    QTimer *t_revive;
    QTimer *t_boost;
    QTimer *t_an;
    QTimer *t_tilt;
    QTimer *t_tchange;
    QTimer *t_flag;
    QTimer *t_star;
    QTimer *t_reviveL;
    QFont font;
    double scaleX;
    double scaleY;
    Player *player;
    Shop *shop;
    int active;
    QPoint mousePos;
    QThread *workerThread;
    QVector <Obstacle*> obstacles;
    QVector <Blus*> blusse;
    QVector <PxAn*> pxans;
    QVector <Window*> windows;
    QVector <Star*> stars;
    int random(int min, int max);
    QPixmap end;
    QPixmap blus;
    QPixmap minus;
    QPixmap schmuserkadser;
    QPixmap enemyPixmap;
    QPixmap maas;
    QPixmap btnPx;
    QPixmap ground;
    QPixmap bg;
    QPixmap medal_bronze;
    QPixmap medal_silver;
    QPixmap medal_gold;
    QPixmap flag_de;
    QPixmap flag_en;
    QString enemy;
    QRectF enemyRect;
    Translation *transl;
    int enemytype;
    int enemydir;
    int enemylife;
    int score;
    int highscore;
    int schmuser;
    int maxX;
    int maxY;
    int medal;
    double flashOpacity;
    double g1x;
    double g2x;
    double boost;
    int revive;
    bool flag;
    QFile file;
    void loadData();
    void write();
    void reset(int type=0);
    void moveGround(double speed);
    void createWindows();
protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e) override;
    void closeEvent(QCloseEvent *event);
};

#endif // FRMMAIN_H