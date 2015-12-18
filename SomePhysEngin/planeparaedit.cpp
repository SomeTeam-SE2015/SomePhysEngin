#include "planeparaedit.h"
#include "ui_planeparaedit.h"

PlaneParaEdit::PlaneParaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaneParaEdit)
{
    ui->setupUi(this);
}

PlaneParaEdit::~PlaneParaEdit()
{
    delete ui;
}

void PlaneParaEdit::setPlanePara()
{
    para[0] = ui->xDoubleSpinBox->value();
    para[1] = ui->xDoubleSpinBox_4->value();
    para[2] = ui->xDoubleSpinBox_5->value();
    para[3] = ui->xDoubleSpinBox_6->value();
    para[4] = ui->xDoubleSpinBox_7->value();
    para[5] = ui->xDoubleSpinBox_8->value();
}

double *PlaneParaEdit::getPlanePara()
{
    return para;
}
