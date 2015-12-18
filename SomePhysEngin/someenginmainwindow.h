#ifndef SOMEENGINMAINWINDOW_H
#define SOMEENGINMAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <QtXml>
#include <QFile>
#include "enginviewer.h"
#include "scenegeneratortest.h"
#include "essentialpara.h"
#include "essentialparaedit.h"
#include "materialparaedit.h"
#include "vertexparaedit.h"
#include "sphereparaedit.h"
#include "triparaedit.h"
#include "planeparaedit.h"
#include "springparaedit.h"

namespace Ui {
class SomeEnginMainWindow;
class EnginViewer;
class SceneGeneratorTest;
}

class SomeEnginMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SomeEnginMainWindow(QWidget *parent = 0);
    ~SomeEnginMainWindow();

signals:
    void sendMaterialList(QStringList);
    void sendVertexNum(int);
    void sendIdNum(int);
    void sendFileName(QString);

private slots:
    void on_load_scene_triggered();

    void on_pushButton_clicked();



    void on_action_triggered();

    void on_help_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_save_scene_triggered();

    void on_pushButton_8_clicked();

private:
    Ui::SomeEnginMainWindow *ui;
    QTimer *m_timer;
    EssentialPara essentialPara;
    bool MaterialChoice[7]{0};
    QList<Vertex> vertexList;
    QList<Sphere> sphereList;
    QList<Triangle> triList;
    QList<Plane> planeList;
    QList<Spring> springList;

    EssentialParaEdit essentialParaEdit;
    MaterialParaEdit materialParaEdit;
    VertexParaEdit vertexParaEdit;
    SphereParaEdit sphereParaEdit;
    TriParaEdit triParaEdit;
    PlaneParaEdit planeParaEdit;
    SpringParaEdit springParaEdit;

    QStringList getMaterialList();
    void saveToScene(QString fileName);
    QDomElement savePositionToNode(QDomDocument doc, QDomElement node, Position position);
    QDomElement saveColorToNode(QDomDocument doc, QDomElement node, Color color);
    QDomElement saveMaterialToNode(QDomDocument doc, QDomElement node, Material material);
    QDomElement saveSphereToNode(QDomDocument doc, QDomElement node, Sphere sphere);
    QDomElement saveVertexToNode(QDomDocument doc, QDomElement node, Vertex vertex);
    QDomElement saveTriToNode(QDomDocument doc, QDomElement node, Triangle triangle);
    QDomElement savePlaneToNode(QDomDocument doc, QDomElement node, Plane plane);
    QDomElement saveSpringToNode(QDomDocument doc, QDomElement node, Spring spring);
};

#endif // SOMEENGINMAINWINDOW_H
