#ifndef LIFEGAMEWIDGET_H
#define LIFEGAMEWIDGET_H

#include <QTimer>
#include <QWidget>
#include "LifeGame.h"

class LifeGameWidget : public QWidget
{
    Q_OBJECT

public:
    LifeGameWidget(QWidget *parent = 0);
    ~LifeGameWidget();
public slots:
    void start();
    void stop();
    void clear();
    void tick();

private:
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

    LifeGame _game;
    QTimer _timer;
};

#endif // LIFEGAMEWIDGET_H
