#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QProcess>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_main_exit_pushButton_clicked();

    void on_start_user_management_pushButton_clicked();

    void on_start_group_management_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
