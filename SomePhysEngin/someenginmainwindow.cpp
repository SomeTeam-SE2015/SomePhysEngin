#include "someenginmainwindow.h"
#include "ui_someenginmainwindow.h"

SomeEnginMainWindow::SomeEnginMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SomeEnginMainWindow)
{
    ui->setupUi(this);
}

SomeEnginMainWindow::~SomeEnginMainWindow()
{
    delete ui;
}
