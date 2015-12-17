#include "someenginmainwindow.h"
#include "ui_someenginmainwindow.h"
#include "aboutdialog.h"

#include <QFileDialog>
#include <QDesktopServices>
#include <QFileInfo>
#include <QMessageBox>

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

void SomeEnginMainWindow::on_action_triggered()
{
    AboutDialog about;
    about.exec();
}

void SomeEnginMainWindow::on_help_triggered()
{
    QFileInfo file("help/help.html");
    if (file.exists() == false)
    {
        QMessageBox::warning(this, "engin-demo","Cannot find help file",
                                     QMessageBox::Ok);
        return;
    }
    QDesktopServices::openUrl(QUrl(file.absolutePath()+"/help.html"));
}
