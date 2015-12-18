#include "materialparaedit.h"
#include "ui_materialparaedit.h"

#include <QPixmap>

MaterialParaEdit::MaterialParaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaterialParaEdit)
{
    ui->setupUi(this);
}

MaterialParaEdit::~MaterialParaEdit()
{
    delete ui;
}

bool* MaterialParaEdit::getMaterialPara()
{
    MaterialChoice[0] = ui->checkBox->isChecked();
    MaterialChoice[1] = ui->checkBox_2->isChecked();
    MaterialChoice[2] = ui->checkBox_3->isChecked();
    MaterialChoice[3] = ui->checkBox_4->isChecked();
    MaterialChoice[4] = ui->checkBox_5->isChecked();
    MaterialChoice[5] = ui->checkBox_6->isChecked();
    MaterialChoice[6] = ui->checkBox_7->isChecked();
    return MaterialChoice;
}

void MaterialParaEdit::on_checkBox_clicked()
{
    ui->label->setPixmap(QPixmap("images/red.jpg"));
}

void MaterialParaEdit::on_checkBox_2_clicked()
{
    ui->label->setPixmap(QPixmap("images/sred.jpg"));
}

void MaterialParaEdit::on_checkBox_3_clicked()
{
    ui->label->setPixmap(QPixmap("images/green.jpg"));
}

void MaterialParaEdit::on_checkBox_4_clicked()
{
    ui->label->setPixmap(QPixmap("images/sgreen.jpg"));
}

void MaterialParaEdit::on_checkBox_5_clicked()
{
    ui->label->setPixmap(QPixmap("images/blue.jpg"));
}

void MaterialParaEdit::on_checkBox_6_clicked()
{
    ui->label->setPixmap(QPixmap("images/sblue.jpg"));
}

void MaterialParaEdit::on_checkBox_7_clicked()
{
    ui->label->setPixmap(QPixmap("images/mirror.jpg"));
}
