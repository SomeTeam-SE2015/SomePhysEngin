#ifndef TRIPARAEDIT_H
#define TRIPARAEDIT_H

#include <QDialog>

namespace Ui {
class TriParaEdit;
}

class TriParaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit TriParaEdit(QWidget *parent = 0);
    ~TriParaEdit();
    void setTriPara();
    double* getTriPara();

public slots:
    void showMaterialList(QStringList materialList);
    void getVertexNum(int num);

private:
    Ui::TriParaEdit *ui;
    double para[7];
};

#endif // TRIPARAEDIT_H
