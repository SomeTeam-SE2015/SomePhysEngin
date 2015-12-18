#ifndef PLANEPARAEDIT_H
#define PLANEPARAEDIT_H

#include <QDialog>

namespace Ui {
class PlaneParaEdit;
}

class PlaneParaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit PlaneParaEdit(QWidget *parent = 0);
    ~PlaneParaEdit();
    void setPlanePara();
    double* getPlanePara();

private:
    Ui::PlaneParaEdit *ui;
    double para[6];
};

#endif // PLANEPARAEDIT_H
