#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <QDialog>
#include <QDebug>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class User_management;
}

class User_management : public QDialog
{
    Q_OBJECT

public:
    explicit User_management(QWidget *parent = nullptr);
    ~User_management();

private slots:
    void on_list_users_pushButton_clicked();

    void on_exit_pushButton_clicked();

    void on_info_pushButton_clicked();

private:
    Ui::User_management *ui;
};

#endif // USER_MANAGEMENT_H
