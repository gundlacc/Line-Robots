#ifndef ROBOT_H
#define ROBOT_H

#include "pathline.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class Robot : public QGraphicsItem
{
public:
    explicit Robot(int, int, pathLine *, QString);
    QRectF boundingRect() const;
    QPolygonF boundingDiamond() const;
    QPolygonF boundingTriangle() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setSpeed(double);
    void setColor(QColor);
    bool avoidLineCollision(QGraphicsItem *curItem, int clearAhead);
    int getBufferSpace();
    int getSpeed();

protected:
    void advance(int phase);
    void saveSpeed();
    void restoreSpeed();

private:
    int const RADAR_SEARCH_AHEAD = 60;
    int const RADAR_SEARCH_INTER = 15;
    int const EAST_BORDER = 524;
    int const WEST_BORDER = 30;
    int const NORTH_BORDER = 30;
    int const SOUTH_BORDER = 436;

    int speed;
    int tempSpeed;
    int maxSpeed; //save the robot's original speed as a ceiling
    int x;
    int y;
    QString type;
    pathLine *line;
    QColor color;
};

#endif // MYITEM_H
