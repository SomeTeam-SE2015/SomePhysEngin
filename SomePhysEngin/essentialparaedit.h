#ifndef ESSENTIALPARAEDIT_H
#define ESSENTIALPARAEDIT_H

#include <QDialog>

namespace Ui {
class EssentialParaEdit;
}

class EssentialParaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit EssentialParaEdit(QWidget *parent = 0);
    ~EssentialParaEdit();
    double* getEssentialPara();
    void setEssentialPara();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::EssentialParaEdit *ui;
    double para[27];
};

#endif // ESSENTIALPARAEDIT_H
