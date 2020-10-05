/************************************
 *   created:   in stoneage maybe?  *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  my home, Ger        *
 ************************************/

#include "scenemousetrack.h"
#include <QGraphicsSceneMouseEvent>

void SceneMouseTrack::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //ctrl pressed?
    bool ctrl = event->modifiers().testFlag(Qt::ControlModifier);

    //positions
    int x = event->scenePos().x();
    int y = event->scenePos().y();

    if(ctrl)
        emit mouseMoved_Ctrl(x, y);
    else
        emit mouseMoved(x, y);
}

void SceneMouseTrack::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //ctrl pressed?
    bool ctrl = event->modifiers().testFlag(Qt::ControlModifier);

    //positions
    int x = event->scenePos().x();
    int y = event->scenePos().y();

    //click
    if(ctrl)
        emit MouseClickedAtPos_Ctrl(x, y);
    else
        emit MouseClickedAtPos(x, y);

    //mouse button
    if(event->button() == Qt::LeftButton)
    {
        if(ctrl)
        {
            emit MouseClickedAtPos_Left_Ctrl(x, y);
            emit MouseClicked_Left_Ctrl();
        }
        else
        {
            emit MouseClickedAtPos_Left(x, y);
            emit MouseClicked_Left();
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        if(ctrl)
        {
            emit MouseClickedAtPos_Right_Ctrl(x, y);
            emit MouseClicked_Right_Ctrl();
        }
        else
        {
            emit MouseClickedAtPos_Right(x, y);
            emit MouseClicked_Right();
        }
    }
    else if(event->button() == Qt::MiddleButton)
    {
        if(ctrl)
        {
            emit MouseClickedAtPos_Mid_Ctrl(x, y);
            emit MouseClicked_Mid_Ctrl();
        }
        else
        {
            emit MouseClickedAtPos_Mid(x, y);
            emit MouseClicked_Mid();
        }
    }
}

void SceneMouseTrack::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        emit MouseDoubleClicked_Left();
    else if(event->button() == Qt::RightButton)
        emit MouseDoubleClicked_Right();
}

void SceneMouseTrack::wheelEvent(QWheelEvent *event)
{
    int x       = event->x();
    int y       = event->y();
    int d       = event->delta();

    event->accept();

    if(event->modifiers().testFlag(Qt::ControlModifier))
        emit MouseScrolledAtPos_Ctrl(x, y, d);
    else
        emit MouseScrolledAtPos(x, y, d);
}

void SceneMouseTrack::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers().testFlag(Qt::ControlModifier))
        switch (event->key()) {
        case Qt::Key_Plus:      emit KeyPressed_Plus_Ctrl();        break;
        case Qt::Key_Minus:     emit KeyPressed_Minus_Ctrl();       break;
        default:                                                    break;}
    else
        switch (event->key()) {
        case Qt::Key_Plus:      emit KeyPressed_Plus();             break;
        case Qt::Key_Minus:     emit KeyPressed_Minus();            break;
        default:                                                    break;}
}
