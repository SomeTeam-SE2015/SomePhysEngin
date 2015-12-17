#ifndef VERTEXPARAEDIT_H
#define VERTEXPARAEDIT_H

#include <QDialog>

namespace Ui {
class VertexParaEdit;
}

class VertexParaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit VertexParaEdit(QWidget *parent = 0);
    ~VertexParaEdit();
    void setVertexPara();
    double* getVertexPara();

public slots:
    void showMaterialList(QStringList materialList);

private:
    Ui::VertexParaEdit *ui;
    double para[9];
};

#endif // VERTEXPARAEDIT_H
