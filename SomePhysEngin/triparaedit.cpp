#include "triparaedit.h"
#include "ui_triparaedit.h"

TriParaEdit::TriParaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TriParaEdit)
{
    ui->setupUi(this);
}

TriParaEdit::~TriParaEdit()
{
    delete ui;
}

void TriParaEdit::setTriPara()
{
    para[0] = ui->xDoubleSpinBox->value();
    para[1] = ui->xDoubleSpinBox_2->value();
    para[2] = ui->xDoubleSpinBox_3->value();
    para[3] = ui->comboBox->currentIndex();
    para[4] = ui->comboBox_2->currentIndex();
    para[5] = ui->comboBox_3->currentIndex();
    para[6] = ui->comboBox_4->currentIndex();
}

double *TriParaEdit::getTriPara()
{
    return para;
}

void TriParaEdit::showMaterialList(QStringList materialList)
{
    ui->comboBox->clear();
    ui->comboBox->addItems(materialList);
}

void TriParaEdit::getVertexNum(int num)
{
    QStringList vertexList;
    for (int i = 0; i < num; i++)
        vertexList.append(tr("p")+QString("%1").arg(i+1));
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(vertexList);
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(vertexList);
    ui->comboBox_4->clear();
    ui->comboBox_4->addItems(vertexList);
}
