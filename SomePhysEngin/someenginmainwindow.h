#ifndef SOMEENGINMAINWINDOW_H
#define SOMEENGINMAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include <stdio.h>
#include "enginviewer.h"
#include "scenegeneratortest.h"
#include "essentialpara.h"
#include "essentialparaedit.h"
#include "materialparaedit.h"
#include "vertexparaedit.h"
#include "sphereparaedit.h"
#include "triparaedit.h"

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

private slots:
    void on_load_scene_triggered();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::SomeEnginMainWindow *ui;
    QTimer *m_timer;
    EssentialPara essentialPara;
    bool MaterialChoice[7]{0};
    QList<Vertex> vertexList;
    QList<Sphere> sphereList;
    QList<Triangle> triList;

    EssentialParaEdit essentialParaEdit;
    MaterialParaEdit materialParaEdit;
    VertexParaEdit vertexParaEdit;
    SphereParaEdit sphereParaEdit;
    TriParaEdit triParaEdit;

    QStringList getMaterialList();
};

#endif // SOMEENGINMAINWINDOW_H
