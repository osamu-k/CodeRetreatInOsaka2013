#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QWidget>
#include "LifeGame.h"
#include "lifegamewidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void start();
    void stop();
private:
    LifeGameWidget *_lifeGameWidget;
    QPushButton *_startButton;
    QPushButton *_stopButton;
    QPushButton *_clearButton;
    QPushButton *_closeButton;
};

#endif // MAINWINDOW_H
