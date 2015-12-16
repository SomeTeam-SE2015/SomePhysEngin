#include "someenginmainwindow.h"
#include "ui_someenginmainwindow.h"

SomeEnginMainWindow::SomeEnginMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SomeEnginMainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    m_timer->setInterval(1);
    connect(m_timer, SIGNAL(timeout()), ui->enginViewer, SLOT(update()));
    m_timer->start();
}

SomeEnginMainWindow::~SomeEnginMainWindow()
{
    delete ui;
}
