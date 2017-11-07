#include "obstacle.h"

Obstacle::Obstacle()
{

}

Obstacle::Obstacle(QRect top, QRect bottom, QPixmap px, int type, bool box, int boxType)
{
    this->type = type;
    this->top = QRectF(top);
    this->bottom = QRectF(bottom);
    train = QRectF(top.x()-150,1780,200,80);
    train2 = QRectF(top.x()+50,1780,200,80);
    this->px = px;
    this->hasBox = box;
    if(hasBox) {
        this->box = QRectF(top.x()+120,1789,60,50);
        this->boxType = boxType;
        this->opacity = 1.1;
    }
    approved = false;
}

QRectF Obstacle::getTop()
{
    return top;
}

QRectF Obstacle::getBottom()
{
    return bottom;
}

void Obstacle::moveBy(double x, double y)
{
    top.moveTo(top.x()+x,top.y()+y);
    bottom.moveTo(bottom.x()+x,bottom.y()+y);
    train.moveTo(train.x()+x,train.y()+y);
    train2.moveTo(train2.x()+x,train2.y()+y);
    if(hasBox) {
        if(opacity>0) {
            box.moveTo(box.x()+x,box.y()+y);
            if(opacity<1.1) {
                box.moveTo(box.x(),box.y()-0.25);
                opacity-=0.0125;
            }
        }
    }
}
