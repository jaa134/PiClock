#ifndef DRAGLISTWIDGET_H
#define DRAGLISTWIDGET_H

#include "QListWidget"
#include "QMouseEvent"
#include "QScrollBar"

class DragListWidget : public QListWidget
{
    Q_OBJECT

public:
    typedef QListWidget super;
    explicit DragListWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *) Q_DECL_OVERRIDE;

private:
    enum DragState {
        DragStopped,
        DragStarted,
        Dragged
    };
    quint8 m_dragState;
    int m_dragStartPos;

};

#endif // DRAGLISTWIDGET_H
