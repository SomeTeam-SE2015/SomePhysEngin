#include "springparaedit.h"
#include "ui_springparaedit.h"

SpringParaEdit::SpringParaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpringParaEdit)
{
    ui->setupUi(this);
}

SpringParaEdit::~SpringParaEdit()
{
    delete ui;
}

void SpringParaEdit::setSpringPara()
{
    para[0] = ui->xDoubleSpinBox->value();
    para[1] = ui->xDoubleSpinBox_2->value();
    para[2] = ui->xDoubleSpinBox_3->value();
    para[3] = ui->xDoubleSpinBox_4->value();
    para[4] = ui->xDoubleSpinBox_5->value();
    para[5] = ui->xDoubleSpinBox_6->value();
    para[6] = ui->comboBox->currentIndex();
    para[7] = ui->comboBox_2->currentIndex();
}

double *SpringParaEdit::getSpringPara()
{
    return para;
}

void SpringParaEdit::getIdNum(int num)
{
    QStringList IdList;
    for (int i = 0; i < num; i++)
        IdList.append(QString("%1").arg(i+1));
    ui->comboBox->clear();
    ui->comboBox->addItems(IdList);
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(IdList);

}
