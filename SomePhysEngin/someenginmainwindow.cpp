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
    connect(this, SIGNAL(sendMaterialList(QStringList)), &vertexParaEdit, SLOT(showMaterialList(QStringList)));
    connect(this, SIGNAL(sendMaterialList(QStringList)), &sphereParaEdit, SLOT(showMaterialList(QStringList)));
    connect(this, SIGNAL(sendMaterialList(QStringList)), &triParaEdit, SLOT(showMaterialList(QStringList)));
    connect(this, SIGNAL(sendVertexNum(int)), &triParaEdit, SLOT(getVertexNum(int)));
    connect(this,SIGNAL(sendIdNum(int)), &springParaEdit, SLOT(getIdNum(int)));
    connect(this,SIGNAL(sendFileName(QString)), ui->enginViewer, SLOT(reset_scene(const QString&)));
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
    QString fileName = QFileDialog::getOpenFileName(this,tr("Load file"),
                "../reference/PhysicalEngine/p5out/scenes","Scene(* scene)");
    emit sendFileName(fileName);
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

void SomeEnginMainWindow::on_save_scene_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save",
          "../reference/PhysicalEngine/p5out/scenes","Scene(*scene)");
    saveToScene(fileName);
}

void SomeEnginMainWindow::on_pushButton_8_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save",
          "../reference/PhysicalEngine/p5out/scenes","Scene(*scene)");
    saveToScene(fileName);
    emit sendFileName(fileName);
}

void SomeEnginMainWindow::saveToScene(QString fileName)
{
    QDomDocument doc;
    QDomElement root = doc.createElement(QString("scene"));
    doc.appendChild(root);

    QDomElement node1 = doc.createElement(QString("camera"));
    QDomElement node1_1 = doc.createElement(QString("fov"));
    QDomAttr node1_1a = doc.createAttribute(QString("v"));
    node1_1a.setValue(QString("%1").arg(essentialPara.camera.fov));
    node1_1.setAttributeNode(node1_1a);
    node1.appendChild(node1_1);
    node1_1 = doc.createElement("near_clip");
    node1_1a = doc.createAttribute("v");
    node1_1a.setValue(QString("%1").arg(essentialPara.camera.near_clip));
    node1_1.setAttributeNode(node1_1a);
    node1.appendChild(node1_1);
    node1_1 = doc.createElement("far_clip");
    node1_1a = doc.createAttribute("v");
    node1_1a.setValue(QString("%1").arg(essentialPara.camera.far_clip));
    node1_1.setAttributeNode(node1_1a);
    node1.appendChild(node1_1);
    node1_1 = doc.createElement("position");
    node1_1 = savePositionToNode(doc, node1_1, essentialPara.camera.position);
    node1.appendChild(node1_1);
    node1_1 = doc.createElement("orientation");
    node1_1a = doc.createAttribute("a");
    node1_1a.setValue(QString("%1").arg(essentialPara.camera.orientation.a));
    node1_1.setAttributeNode(node1_1a);
    node1_1a = doc.createAttribute("x");
    node1_1a.setValue(QString("%1").arg(essentialPara.camera.orientation.x));
    node1_1.setAttributeNode(node1_1a);
    node1_1a = doc.createAttribute("y");
    node1_1a.setValue(QString("%1").arg(essentialPara.camera.orientation.y));
    node1_1.setAttributeNode(node1_1a);
    node1_1a = doc.createAttribute("z");
    node1_1a.setValue(QString("%1").arg(essentialPara.camera.orientation.z));
    node1_1.setAttributeNode(node1_1a);
    node1.appendChild(node1_1);
    root.appendChild(node1);

    node1 = doc.createElement("background_color");
    node1 = saveColorToNode(doc, node1, essentialPara.backgroundColor);
    root.appendChild(node1);

    node1 = doc.createElement("refractive_index");
    QDomAttr node1a = doc.createAttribute("v");
    node1a.setValue(QString("%1").arg(essentialPara.refractiveIndex));
    node1.setAttributeNode(node1a);
    root.appendChild(node1);

    node1 = doc.createElement("ambient_color");
    node1 = saveColorToNode(doc, node1, essentialPara.ambientLight);
    root.appendChild(node1);

    node1 = doc.createElement("point_light");
    node1_1 = doc.createElement("position");
    node1_1 = savePositionToNode(doc, node1_1, essentialPara.pointLight.position);
    node1.appendChild(node1_1);
    node1_1 = doc.createElement("color");
    node1_1 = saveColorToNode(doc, node1_1, essentialPara.pointLight.color);
    node1.appendChild(node1_1);
    root.appendChild(node1);

    node1 = doc.createElement("gravity");
    node1 = savePositionToNode(doc, node1, essentialPara.gravity);
    root.appendChild(node1);

    if (MaterialChoice[0])
    {
        Material material(Color(1,0,0), Color(1,0,0), Color(0,0,0), 0, QString("red"));
        node1 = doc.createElement("material");
        node1 = saveMaterialToNode(doc, node1, material);
        root.appendChild(node1);
    }

    if (MaterialChoice[1])
    {
		Material material(Color(1,0,0), Color(1,0,0), Color(1,1,1), 0, QString("sred"));
        node1 = doc.createElement("material");
        node1 = saveMaterialToNode(doc, node1, material);
        root.appendChild(node1);
    }

    if (MaterialChoice[2])
    {
        Material material(Color(0,1,0), Color(0,1,0), Color(0,0,0), 0, QString("green"));
        node1 = doc.createElement("material");
        node1 = saveMaterialToNode(doc, node1, material);
        root.appendChild(node1);
    }

    if (MaterialChoice[3])
    {
        Material material(Color(0,1,0), Color(0,1,0), Color(1,1,1), 0, QString("sgreen"));
        node1 = doc.createElement("material");
        node1 = saveMaterialToNode(doc, node1, material);
        root.appendChild(node1);
    }

    if (MaterialChoice[4])
    {
        Material material(Color(0,0,1), Color(0,0,1), Color(0,0,0), 0, QString("blue"));
        node1 = doc.createElement("material");
        node1 = saveMaterialToNode(doc, node1, material);
        root.appendChild(node1);
    }

    if (MaterialChoice[5])
    {
        Material material(Color(0,0,1), Color(0,0,1), Color(0,1,1), 0, QString("sblue"));
        node1 = doc.createElement("material");
        node1 = saveMaterialToNode(doc, node1, material);
        root.appendChild(node1);
    }

    if (MaterialChoice[6])
    {
        Material material(Color(0,0,0), Color(0,0,0), Color(1,1,1), 0, QString("mirror"));
        node1 = doc.createElement("material");
        node1 = saveMaterialToNode(doc, node1, material);
        root.appendChild(node1);
    }

    for (int i = 0; i < sphereList.size(); i++)
    {
        node1 = doc.createElement("sphere");
        node1 = saveSphereToNode(doc, node1, sphereList.at(i));
        root.appendChild(node1);
    }

    for (int i = 0; i < vertexList.size(); i++)
    {
        node1 = doc.createElement("vertex");
        node1 = saveVertexToNode(doc, node1, vertexList.at(i));
        root.appendChild(node1);
    }

    for (int i = 0; i < triList.size(); i++)
    {
        node1 = doc.createElement("triangle");
        node1 = saveTriToNode(doc, node1, triList.at(i));
        root.appendChild(node1);
    }

    for (int i = 0; i < planeList.size(); i++)
    {
        node1 = doc.createElement("plane_body");
        node1 = savePlaneToNode(doc, node1, planeList.at(i));
        root.appendChild(node1);
    }

    for (int i = 0; i < springList.size(); i++)
    {
        node1 = doc.createElement("spring");
        node1 = saveSpringToNode(doc, node1, springList.at(i));
        root.appendChild(node1);
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;
    QTextStream out(&file);

    doc.save(out, 4);
    file.close();
}

QDomElement SomeEnginMainWindow::savePositionToNode(QDomDocument doc, QDomElement node, Position position)
{
    QDomAttr nodeA = doc.createAttribute("x");
    nodeA.setValue(QString("%1").arg(position.x));
    node.setAttributeNode(nodeA);
    nodeA = doc.createAttribute("y");
    nodeA.setValue(QString("%1").arg(position.y));
    node.setAttributeNode(nodeA);
    nodeA = doc.createAttribute("z");
    nodeA.setValue(QString("%1").arg(position.z));
    node.setAttributeNode(nodeA);
    return node;
}

QDomElement SomeEnginMainWindow::saveColorToNode(QDomDocument doc, QDomElement node, Color color)
{
    QDomAttr nodeA = doc.createAttribute("r");
    nodeA.setValue(QString("%1").arg(color.r));
    node.setAttributeNode(nodeA);
    nodeA = doc.createAttribute("g");
    nodeA.setValue(QString("%1").arg(color.g));
    node.setAttributeNode(nodeA);
    nodeA = doc.createAttribute("b");
    nodeA.setValue(QString("%1").arg(color.b));
    node.setAttributeNode(nodeA);
    return node;
}

QDomElement SomeEnginMainWindow::saveMaterialToNode(QDomDocument doc, QDomElement node, Material material)
{
    QDomAttr nodeA = doc.createAttribute("name");
    nodeA.setValue(material.name);
    node.setAttributeNode(nodeA);
    QDomElement node1 = doc.createElement("ambient");
    node1 = saveColorToNode(doc, node1, material.ambient);
    node.appendChild(node1);
    node1 = doc.createElement("diffuse");
    node1 = saveColorToNode(doc, node1, material.diffuse);
    node.appendChild(node1);
    node1 = doc.createElement("specular");
    node1 = saveColorToNode(doc, node1, material.specular);
    node.appendChild(node1);
    node1 = doc.createElement("refractive_index");
    QDomAttr node1A = doc.createAttribute("v");
    node1A.setValue(QString("%1").arg(material.refractive_index));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);
    return node;
}

QDomElement SomeEnginMainWindow::saveSphereToNode(QDomDocument doc, QDomElement node, Sphere sphere)
{
    QDomAttr nodeA = doc.createAttribute("material");
    nodeA.setValue(sphere.material);
    node.setAttributeNode(nodeA);

    QDomElement node1 = doc.createElement("position");
    node1 = savePositionToNode(doc, node1, sphere.position);
    node.appendChild(node1);

    node1 = doc.createElement("radius");
    QDomAttr node1A = doc.createAttribute("v");
    node1A.setValue(QString("%1").arg(sphere.radius));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    node1 = doc.createElement("body");
    QDomElement node1_1 = doc.createElement("id");
    QDomAttr node1_1A = doc.createAttribute("i");
    node1_1A.setValue(QString("%1").arg(sphere.body.id));
    node1_1.setAttributeNode(node1_1A);
    node1.appendChild(node1_1);
    node1_1 = doc.createElement("velocity");
    node1_1 = savePositionToNode(doc, node1_1, sphere.body.velocity);
    node1.appendChild(node1_1);
    node1_1 = doc.createElement("mass");
    node1_1A = doc.createAttribute("v");
    node1_1A.setValue(QString("%1").arg(sphere.body.mass));
    node1_1.setAttributeNode(node1_1A);
    node1.appendChild(node1_1);
    node.appendChild(node1);

    return node;
}

QDomElement SomeEnginMainWindow::saveVertexToNode(QDomDocument doc, QDomElement node, Vertex vertex)
{
    QDomAttr nodeA = doc.createAttribute("name");
    nodeA.setValue(vertex.name);
    node.setAttributeNode(nodeA);
    nodeA = doc.createAttribute("material");
    nodeA.setValue(vertex.material);
    node.setAttributeNode(nodeA);

    QDomElement node1 = doc.createElement("position");
    node1 = savePositionToNode(doc, node1, vertex.position);
    node.appendChild(node1);

    node1 = doc.createElement("normal");
    node1 = savePositionToNode(doc, node1, vertex.normal);
    node.appendChild(node1);

    node1 = doc.createElement("tex_coord");
    QDomAttr node1A = doc.createAttribute("u");
    node1A.setValue(QString("%1").arg(vertex.texCoord.u));
    node1.setAttributeNode(node1A);
    node1A = doc.createAttribute("v");
    node1A.setValue(QString("%1").arg(vertex.texCoord.v));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    return node;
}

QDomElement SomeEnginMainWindow::saveTriToNode(QDomDocument doc, QDomElement node, Triangle triangle)
{
    QDomAttr nodeA = doc.createAttribute("material");
    nodeA.setValue(triangle.material);
    node.setAttributeNode(nodeA);

    QDomElement node1 = doc.createElement("position");
    node1 = savePositionToNode(doc, node1, triangle.position);
    node.appendChild(node1);

    QDomAttr node1A;
    for (int i = 0; i < 3; i++)
    {
        node1 = doc.createElement("vertex");
        node1A = doc.createAttribute("name");
        node1A.setValue(triangle.vertexes[i]);
        node1.setAttributeNode(node1A);
        node.appendChild(node1);
    }

    node1 = doc.createElement("body");
    QDomElement node1_1 = doc.createElement("id");
    QDomAttr node1_1A = doc.createAttribute("i");
    node1_1A.setValue(QString("%1").arg(triangle.body.id));
    node1_1.setAttributeNode(node1_1A);
    node1.appendChild(node1_1);
    node.appendChild(node1);

    return node;
}

QDomElement SomeEnginMainWindow::savePlaneToNode(QDomDocument doc, QDomElement node, Plane plane)
{
    QDomElement node1 = doc.createElement("id");
    QDomAttr node1A = doc.createAttribute("i");
    node1A.setValue(QString("%1").arg(plane.id));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    node1 = doc.createElement("position");
    node1 = savePositionToNode(doc, node1, plane.position);
    node.appendChild(node1);

    node1 = doc.createElement("normal");
    node1 = savePositionToNode(doc, node1, plane.normal);
    node.appendChild(node1);

    return node;
}

QDomElement SomeEnginMainWindow::saveSpringToNode(QDomDocument doc, QDomElement node, Spring spring)
{
    QDomElement node1 = doc.createElement("constant");
    QDomAttr node1A = doc.createAttribute("v");
    node1A.setValue(QString("%1").arg(spring.constant));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    node1 = doc.createElement("equilibrium");
    node1A = doc.createAttribute("v");
    node1A.setValue(QString("%1").arg(spring.equilibrium));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    node1 = doc.createElement("body1");
    node1A = doc.createAttribute("i");
    node1A.setValue(QString("%1").arg(spring.body1.id));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    node1 = doc.createElement("body2");
    node1A = doc.createAttribute("i");
    node1A.setValue(QString("%1").arg(spring.body2.id));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    node1 = doc.createElement("offset2");
    node1 = savePositionToNode(doc, node1, spring.offset2);
    node.appendChild(node1);

    node1 = doc.createElement("damping");
    node1A = doc.createAttribute("v");
    node1A.setValue(QString("%1").arg(spring.damping));
    node1.setAttributeNode(node1A);
    node.appendChild(node1);

    return node;
}

