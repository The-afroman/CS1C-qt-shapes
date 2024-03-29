#include "canvas.h"
#include "shapeParser.h"
#include "savefile.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QWidget widget;

    inputShape(shapeVect);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

void RenderArea::updatePoints(int x, int y,
                              int x2, int y2,
                              int x3, int y3,
                              int x4, int y4,
                              int x5, int y5,
                              int x6, int y6,
                              int x7, int y7,
                              int x8, int y8)
{
    changeX = x;
    changeY = y;
    changeX2 = x2;
    changeY2 = y2;
    changeX3 = x3;
    changeY3 = y3;
    changeX4 = x4;
    changeY4 = y4;
    changeX5 = x5;
    changeY5 = y5;
    changeX6 = x6;
    changeY6 = y6;
    changeX7 = x7;
    changeY7 = y7;
    changeX8 = x8;
    changeY8 = y8;
    update();
}

void RenderArea::saveShapes(int ofsetAr[][2] , const int AR_SIZE = 8)
{
    int i = 0;
    ofsetAr[i][0] = changeX;
    ofsetAr[i][1] = changeY;
    ofsetAr[++i][0] = changeX2;
    ofsetAr[i][1] = changeY2;
    ofsetAr[++i][0] = changeX3;
    ofsetAr[i][1] = changeY3;
    ofsetAr[++i][0] = changeX4;
    ofsetAr[i][1] = changeY4;
    ofsetAr[++i][0] = changeX5;
    ofsetAr[i][1] = changeY5;
    ofsetAr[++i][0] = changeX6;
    ofsetAr[i][1] = changeY6;
    ofsetAr[++i][0] = changeX7;
    ofsetAr[i][1] = changeY7;
    ofsetAr[++i][0] = changeX8;
    ofsetAr[AR_SIZE-1][1] = changeY8;

    outFile(shapeVect, ofsetAr);
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    /* use of overloaded [] operator */
    myVector<Shape*> newVect(shapeVect);
    newVect[0]->draw(this, changeX, changeY);

    newVect[1]->draw(this, changeX2, changeY2);

    newVect[2]->draw(this, changeX3, changeY3);

    newVect[3]->draw(this, changeX4, changeY4);

    newVect[4]->draw(this, changeX5, changeY5);

    newVect[5]->draw(this, changeX6, changeY6);

    newVect[6]->draw(this, changeX7, changeY7);

    newVect[7]->draw(this, changeX8, changeY8);
}
