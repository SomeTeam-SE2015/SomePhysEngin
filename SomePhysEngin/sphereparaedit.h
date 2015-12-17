#ifndef SPHEREPARAEDIT_H
#define SPHEREPARAEDIT_H

#include <QDialog>

namespace Ui {
class SphereParaEdit;
}

class SphereParaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit SphereParaEdit(QWidget *parent = 0);
    ~SphereParaEdit();
    void setSpherePara();
    double* getSpherePara();

public slots:
    void showMaterialList(QStringList materialList);

private:
    Ui::SphereParaEdit *ui;
    double para[9];
};

#endif // SPHEREPARAEDIT_H
