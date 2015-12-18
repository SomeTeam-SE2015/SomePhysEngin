#ifndef MATERIALPARAEDIT_H
#define MATERIALPARAEDIT_H

#include <QDialog>
#include "basicobjects.h"

namespace Ui {
class MaterialParaEdit;
}

class MaterialParaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit MaterialParaEdit(QWidget *parent = 0);
    ~MaterialParaEdit();
    bool *getMaterialPara();

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_6_clicked();

    void on_checkBox_7_clicked();

private:
    Ui::MaterialParaEdit *ui;
    bool MaterialChoice[7];
};

#endif // MATERIALPARAEDIT_H
