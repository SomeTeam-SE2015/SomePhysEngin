#ifndef SPRINGPARAEDIT_H
#define SPRINGPARAEDIT_H

#include <QDialog>

namespace Ui {
class SpringParaEdit;
}

class SpringParaEdit : public QDialog
{
    Q_OBJECT

public:
    explicit SpringParaEdit(QWidget *parent = 0);
    ~SpringParaEdit();
    void setSpringPara();
    double* getSpringPara();

public slots:
    void getIdNum(int num);

private:
    Ui::SpringParaEdit *ui;
    double para[8];
};

#endif // SPRINGPARAEDIT_H
