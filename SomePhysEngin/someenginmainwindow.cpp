#include "someenginmainwindow.h"
#include "ui_someenginmainwindow.h"

#include <QFileDialog>

SomeEnginMainWindow::SomeEnginMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SomeEnginMainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    m_timer->setInterval(1);
    connect(m_timer, SIGNAL(timeout()), ui->enginViewer, SLOT(update()));
    m_timer->start();
    for (int i = 0; i < 7; i++)
        MaterialChoice[i] = 0;
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

void SomeEnginMainWindow::on_pushButton_clicked()
{
    EssentialParaEdit dialog;
    double parameters[27]{0};
    if (dialog.exec() == QDialog::Accepted)
    {
        dialog.setEssentialPara();
        double *para = dialog.getEssentialPara();
        for (int i = 0; i < 27; i++)
            parameters[i] = para[i];
    }
    this->essentialPara.setEssentialPara(parameters);
}

void SomeEnginMainWindow::on_pushButton_2_clicked()
{
    MaterialParaEdit dialog;
    if (dialog.exec() == QDialog::Accepted)
    {
        bool *MC = dialog.getMaterialPara();
        for (int i = 0; i < 7; i++)
            MaterialChoice[i] = MC[i];
    }
}
