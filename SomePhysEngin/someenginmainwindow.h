#ifndef SOMEENGINMAINWINDOW_H
#define SOMEENGINMAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QList>
#include "enginviewer.h"
#include "scenegeneratortest.h"
#include "essentialpara.h"
#include "essentialparaedit.h"
#include "materialparaedit.h"
#include "vertexparaedit.h"

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

private slots:
    void on_load_scene_triggered();

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::SomeEnginMainWindow *ui;
    QTimer *m_timer;
    EssentialPara essentialPara;
    EssentialParaEdit essentialParaEdit;
    MaterialParaEdit materialParaEdit;
    bool MaterialChoice[7]{0};
    QList<Vertex> vertexList;
    VertexParaEdit vertexParaEdit;

    QStringList getMaterialList();
};

#endif // SOMEENGINMAINWINDOW_H
