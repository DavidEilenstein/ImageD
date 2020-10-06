/************************************
 *   created:   in stoneage maybe?  *
 *   author:    David Eilenstein    *
 *   contact:   D.Eilenstein@gsi.de *
 *   project:   ImageD              *
 *   facility:  my home, Ger        *
 ************************************/

#ifndef SCENEMOUSETRACK_H
#define SCENEMOUSETRACK_H

//================================================================== includes

//includes: own

//includes: general
#include <iostream>

//includes: Qt
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>
#include <QWheelEvent>
#include <QKeyEvent>

//namespaces
using namespace std;


//==================================================================

/*!
 * \brief The SceneMouseTrack class Scene to put in a <a href="https://doc.qt.io/qt-5/qgraphicsview.html">QGraphicsView</a> that emits additional signals.
 */
class SceneMouseTrack : public QGraphicsScene
{
    Q_OBJECT
public:
    //SceneMouseTrack();

signals:
    void mouseMoved                         (int x, int y);
    void mouseMoved_Ctrl                    (int x, int y);
    void MouseClickedAtPos                  (int x, int y);
    void MouseClickedAtPos_Ctrl             (int x, int y);
    void MouseClickedAtPos_Left             (int x, int y);
    void MouseClickedAtPos_Left_Ctrl        (int x, int y);
    void MouseClickedAtPos_Right            (int x, int y);
    void MouseClickedAtPos_Right_Ctrl       (int x, int y);
    void MouseClickedAtPos_Mid              (int x, int y);
    void MouseClickedAtPos_Mid_Ctrl         (int x, int y);
    void MouseScrolledAtPos                 (int x, int y, int delta);
    void MouseScrolledAtPos_Ctrl            (int x, int y, int delta);
    void KeyPressed_Plus                    ();
    void KeyPressed_Plus_Ctrl               ();
    void KeyPressed_Minus                   ();
    void KeyPressed_Minus_Ctrl              ();
    void MouseClicked_Left                  ();
    void MouseClicked_Left_Ctrl             ();
    void MouseClicked_Right                 ();
    void MouseClicked_Right_Ctrl            ();
    void MouseClicked_Mid                   ();
    void MouseClicked_Mid_Ctrl              ();
    void MouseDoubleClicked_Right           ();
    void MouseDoubleClicked_Right_Ctrl      ();
    void MouseDoubleClicked_Left            ();
    void MouseDoubleClicked_Left_Ctrl       ();

public slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENEMOUSETRACK_H
