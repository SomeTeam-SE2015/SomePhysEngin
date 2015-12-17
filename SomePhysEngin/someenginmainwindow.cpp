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
    connect(this, SIGNAL(sendMaterialList(QStringList)), &sphereParaEdit, SLOT(showMaterialList(QStringList)));
    connect(this, SIGNAL(sendMaterialList(QStringList)), &triParaEdit, SLOT(showMaterialList(QStringList)));
    connect(this, SIGNAL(sendVertexNum(int)), &triParaEdit, SLOT(getVertexNum(int)));
    connect(this,SIGNAL(sendIdNum(int)), &springParaEdit, SLOT(getIdNum(int)));
}

SomeEnginMainWindow::~SomeEnginMainWindow()
{
    delete ui;
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
        QString name = tr("p")+QString("%1").arg(vertexList.size()+1);
        v.setVertexPara(para, name, material);
        vertexList.append(v);
    }
}


void SomeEnginMainWindow::on_pushButton_4_clicked()
{
    QStringList materialList = getMaterialList();
    emit sendMaterialList(materialList);
    if (sphereParaEdit.exec() == QDialog::Accepted)
    {
        sphereParaEdit.setSpherePara();
        double *para = sphereParaEdit.getSpherePara();
        Sphere s;
        QString material = materialList[para[8]];
        int id = sphereList.size()+1;
        s.setSpherePara(para, material, id);
        sphereList.append(s);
    }
}

void SomeEnginMainWindow::on_pushButton_5_clicked()
{
    QStringList materialList = getMaterialList();
    emit sendMaterialList(materialList);
    emit sendVertexNum(vertexList.size());
    if (triParaEdit.exec() == QDialog::Accepted)
    {
        triParaEdit.setTriPara();
        double *para = triParaEdit.getTriPara();
        Triangle t;
        QString material = materialList[para[3]];
        int id = sphereList.size() + triList.size() + 1;
        QString p1 = vertexList.at(para[4]).name;
        QString p2 = vertexList.at(para[5]).name;
        QString p3 = vertexList.at(para[6]).name;
        t.setTriPara(para, p1, p2, p3, material, id);
        triList.append(t);
    }
}

void SomeEnginMainWindow::on_pushButton_6_clicked()
{
    double parameters[6]{0};
    if (planeParaEdit.exec() == QDialog::Accepted)
    {
        planeParaEdit.setPlanePara();
        double *para = planeParaEdit.getPlanePara();
        Plane p;
        int id = sphereList.size() + triList.size() + planeList.size() + 1;
        p.setPlanePara(para, id);
        planeList.append(p);
    }
}

void SomeEnginMainWindow::on_pushButton_7_clicked()
{
    double parameters[8]{0};
    emit sendIdNum(sphereList.size() + triList.size() + planeList.size());
    if (springParaEdit.exec() == QDialog::Accepted)
    {
        springParaEdit.setSpringPara();
        double *para = springParaEdit.getSpringPara();
        para[7] = para[7]+1;
        para[8] = para[8]+1;
        Spring s;
        s.setSpringPara(para);
        springList.append(s);
    }
}
