#ifndef SOMEENGINMAINWINDOW_H
#define SOMEENGINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SomeEnginMainWindow;
}

class SomeEnginMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SomeEnginMainWindow(QWidget *parent = 0);
    ~SomeEnginMainWindow();

private:
    Ui::SomeEnginMainWindow *ui;
};

#endif // SOMEENGINMAINWINDOW_H
