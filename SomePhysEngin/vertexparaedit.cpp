#include "vertexparaedit.h"
#include "ui_vertexparaedit.h"

VertexParaEdit::VertexParaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VertexParaEdit)
{
    ui->setupUi(this);
}

VertexParaEdit::~VertexParaEdit()
{
    delete ui;
}

void VertexParaEdit::setVertexPara()
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

double *VertexParaEdit::getVertexPara()
{
    return para;
}

void VertexParaEdit::showMaterialList(QStringList materialList)
{
    ui->comboBox->addItems(materialList);
}
