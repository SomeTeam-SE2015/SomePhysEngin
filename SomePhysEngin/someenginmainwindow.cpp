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
    connect(this, SIGNAL(sendMaterialList(QStringList)), &vertexParaEdit, SLOT(showMaterialList(QStringList)));
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
    double parameters[27]{0};
    if (essentialParaEdit.exec() == QDialog::Accepted)
    {
        essentialParaEdit.setEssentialPara();
        double *para = essentialParaEdit.getEssentialPara();
        for (int i = 0; i < 27; i++)
            parameters[i] = para[i];
    }
    this->essentialPara.setEssentialPara(parameters);
}

void SomeEnginMainWindow::on_pushButton_2_clicked()
{
    if (materialParaEdit.exec() == QDialog::Accepted)
    {
        bool *MC = materialParaEdit.getMaterialPara();
        for (int i = 0; i < 7; i++)
            MaterialChoice[i] = MC[i];
    }
}

void SomeEnginMainWindow::on_pushButton_3_clicked()
{
    QStringList materialList = getMaterialList();
    emit sendMaterialList(materialList);
    if (vertexParaEdit.exec() == QDialog::Accepted)
    {
        vertexParaEdit.setVertexPara();
        double *para = vertexParaEdit.getVertexPara();
        Vertex v;
        QString material = materialList[para[8]];
        v.setVertexPara(para, material);
        vertexList.append(v);
    }
}

QStringList SomeEnginMainWindow::getMaterialList()
{
    QStringList materialList;
    if (MaterialChoice[0])
        materialList<<"red";
    if (MaterialChoice[1])
        materialList<<"sred";
    if (MaterialChoice[2])
        materialList<<"green";
    if (MaterialChoice[3])
        materialList<<"sgreen";
    if (MaterialChoice[4])
        materialList<<"blue";
    if (MaterialChoice[5])
        materialList<<"sblue";
    if (MaterialChoice[6])
        materialList<<"mirror";
    return materialList;
}
