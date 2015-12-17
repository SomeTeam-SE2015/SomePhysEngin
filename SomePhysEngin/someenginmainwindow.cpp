#include "someenginmainwindow.h"
#include "ui_someenginmainwindow.h"

#include "QFileDialog"

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

void SomeEnginMainWindow::on_load_scene_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Load file"),"../reference/PhysicalEngine/p5out/scenes","Scene(* scene)");
    ui->enginViewer->setPlaceholderText(fileName);
}
