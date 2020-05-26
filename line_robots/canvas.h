#ifndef CANVAS_H
#define CANVAS_H

#include "pathline.h"
#include "commandadd.h"
#include <robot.h>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QInputDialog>
#include <QMenu>
#include <QMessageBox>
#include <QPoint>
#include <QUndoStack>

class Canvas : public QGraphicsScene
{
public:
    explicit Canvas(QMenu *itemMenu, QObject *parent = nullptr);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void errorMsg(int error);
    double setSpeedBox();
    QUndoStack *undoStack = nullptr;

private:
    const int LINE_SEARCH_RADIUS = 30;
    const int ROBOT_SEARCH_RADIUS = 30;
    pathLine *detectLine(int *x, int *y);
    bool detectRobot(int *x, int *y);
    QMenu *myItemMenu;
    bool inBounds(QPoint checkPixel, int buffer);
    double roboticSpeed;
    int tempSpeed;
};

#endif // CANVAS_H
