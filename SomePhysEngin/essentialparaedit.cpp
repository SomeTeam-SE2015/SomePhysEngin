#include "essentialparaedit.h"
#include "ui_essentialparaedit.h"

#include "QColorDialog"

EssentialParaEdit::EssentialParaEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EssentialParaEdit)
{
    ui->setupUi(this);
}

EssentialParaEdit::~EssentialParaEdit()
{
    delete ui;
}

double* EssentialParaEdit::getEssentialPara()
{
    return this->para;
}

void EssentialParaEdit::setEssentialPara()
{
    para[0] = ui->fovDoubleSpinBox->value();
    para[1] = ui->nearClipDoubleSpinBox->value();
    para[2] = ui->farClipDoubleSpinBox->value();
    para[3] = ui->xDoubleSpinBox->value();
    para[4] = ui->xDoubleSpinBox_2->value();
    para[5] = ui->xDoubleSpinBox_3->value();
    para[6] = ui->xDoubleSpinBox_4->value();
    para[7] = ui->xDoubleSpinBox_5->value();
    para[8] = ui->xDoubleSpinBox_6->value();
    para[9] = ui->xDoubleSpinBox_7->value();
    para[13] = ui->xDoubleSpinBox_8->value();
    para[17] = ui->xDoubleSpinBox_9->value();
    para[18] = ui->xDoubleSpinBox_10->value();
    para[19] = ui->xDoubleSpinBox_11->value();
    para[23] = ui->xDoubleSpinBox_12->value();
    para[24] = ui->xDoubleSpinBox_13->value();
    para[25] = ui->xDoubleSpinBox_14->value();
    para[26] = ui->xDoubleSpinBox_15->value();

}

void EssentialParaEdit::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(QColor(102,102,102),this,"Edit Color");
    this->para[10] = color.redF();
    this->para[11] = color.greenF();
    this->para[11] = color.blueF();
}

void EssentialParaEdit::on_pushButton_2_clicked()
{
    QColor color = QColorDialog::getColor(QColor(51,51,51),this,"Edit Color");
    this->para[14] = color.redF();
    this->para[15] = color.greenF();
    this->para[16] = color.blueF();
}

void EssentialParaEdit::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(QColor(255,255,255),this,"Edit Color");
    this->para[20] = color.redF();
    this->para[21] = color.greenF();
    this->para[22] = color.blueF();
}
