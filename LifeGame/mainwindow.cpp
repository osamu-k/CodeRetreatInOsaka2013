#include <QApplication>
#include <QHBoxLayout>
#include <QPainter>
#include <QVBoxLayout>
#include "mainwindow.h"

const int ROW_COUNT = 10;
const int COL_COUNT = 10;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , _lifeGameWidget(0)
    , _startButton(0)
    , _stopButton(0)
    , _clearButton(0)
    , _closeButton(0)
{
    _lifeGameWidget = new LifeGameWidget;
    _startButton = new QPushButton( "start" );
    _stopButton = new QPushButton( "stop" );
    _clearButton = new QPushButton( "clear" );
    _closeButton = new QPushButton( "close" );
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget( _startButton );
    buttonLayout->addWidget( _stopButton );
    buttonLayout->addWidget( _clearButton );
    buttonLayout->addStretch();
    buttonLayout->addWidget( _closeButton );
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget( _lifeGameWidget );
    mainLayout->addLayout( buttonLayout );
    setLayout( mainLayout );

    _lifeGameWidget->setMinimumSize( 400, 400 );
    _stopButton->setEnabled( false );

    connect( _startButton, SIGNAL(clicked()), this, SLOT(start()) );
    connect( _stopButton, SIGNAL(clicked()), this, SLOT(stop()) );
    connect( _clearButton, SIGNAL(clicked()), _lifeGameWidget, SLOT(clear()) );
    connect( _closeButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()) );
}

MainWindow::~MainWindow()
{
}

void MainWindow::start()
{
    _lifeGameWidget->start();
    _startButton->setEnabled( false );
    _stopButton->setEnabled( true );
    _clearButton->setEnabled( false );
}

void MainWindow::stop()
{
    _lifeGameWidget->stop();
    _startButton->setEnabled( true );
    _stopButton->setEnabled( false );
    _clearButton->setEnabled( true );
}
