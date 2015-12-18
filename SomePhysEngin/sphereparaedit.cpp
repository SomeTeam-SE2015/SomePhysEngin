#include "sphereparaedit.h"
#include "ui_sphereparaedit.h"

SphereParaEdit::SphereParaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SphereParaEdit)
{
    ui->setupUi(this);
}

SphereParaEdit::~SphereParaEdit()
{
    delete ui;
}

void SphereParaEdit::setSpherePara()
{
    para[0] = ui->xDoubleSpinBox->value();
    para[1] = ui->xDoubleSpinBox_2->value();
    para[2] = ui->xDoubleSpinBox_3->value();
    para[3] = ui->xDoubleSpinBox_4->value();
    para[4] = ui->xDoubleSpinBox_5->value();
    para[5] = ui->xDoubleSpinBox_6->value();
    para[6] = ui->xDoubleSpinBox_7->value();
    para[7] = ui->xDoubleSpinBox_8->value();
    para[8] = ui->comboBox->currentIndex();
}

double *SphereParaEdit::getSpherePara()
{
    return para;
}

void SphereParaEdit::showMaterialList(QStringList materialList)
{
    ui->comboBox->clear();
    ui->comboBox->addItems(materialList);
}
