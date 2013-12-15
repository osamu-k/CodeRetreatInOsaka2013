#include <QMouseEvent>
#include <QPainter>
#include "lifegamewidget.h"

const int ROW_COUNT = 50;
const int COL_COUNT = 50;

LifeGameWidget::LifeGameWidget(QWidget *parent)
    : QWidget(parent)
    , _game(ROW_COUNT,COL_COUNT)
{
    connect( &_timer, SIGNAL(timeout()), this, SLOT(tick()) );
}

LifeGameWidget::~LifeGameWidget()
{
}

void LifeGameWidget::start()
{
    _timer.start( 1000 );
}

void LifeGameWidget::stop()
{
    _timer.stop();
}

void LifeGameWidget::clear()
{
    for( int row = 0; row < ROW_COUNT; row++ ){
        for( int col = 0; col < COL_COUNT; col++ ){
            _game.setAlive( row, col, 0 );
        }
    }
    update();
}

void LifeGameWidget::tick()
{
    _game.next();
    update();
}

void LifeGameWidget::mouseReleaseEvent(QMouseEvent *event)
{
    int row = event->pos().y() * ROW_COUNT / height();
    int col = event->pos().x() * COL_COUNT / width();
    _game.setAlive( row, col, (_game.isAlive( row, col ) + 1) % 2 );
    update();
}

void LifeGameWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::red);

    for( int row = 0; row < ROW_COUNT; row++ ){
        for( int col = 0; col < COL_COUNT; col++ ){
            QColor color = Qt::red;
            if( _game.isAlive(row,col)){
                color = Qt::green;
            }
            painter.fillRect( col * width() / COL_COUNT,
                              row * height() / ROW_COUNT,
                              width() / COL_COUNT,
                              height() / ROW_COUNT,
                              color
                            );
        }
    }
    for( int row = 0; row <= ROW_COUNT; row++ ){
        int y = height() * row / ROW_COUNT;
        painter.drawLine( 0, y, width(), y );
    }
    for( int col = 0; col <= COL_COUNT; col++ ){
        int x = width() * col / COL_COUNT;
        painter.drawLine( x, 0, x, height() );
    }
}
