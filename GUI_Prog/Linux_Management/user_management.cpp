#include "user_management.h"
#include "ui_user_management.h"

User_management::User_management(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_management)
{
    ui->setupUi(this);
}

User_management::~User_management()
{
    delete ui;
}

void User_management::on_list_users_pushButton_clicked()
{
    // Process to run a Linux command & capture all real Linux users
    QProcess re_users;
    re_users.start("bash", QStringList() << "-c" << "cut -d: -f1,3 /etc/passwd | egrep ':[0-9]{4}$' | cut -d: -f1");
    if(!re_users.waitForFinished()) {
        qDebug() << "Oops something went wrong when capturing all real Linux users ... The process is not finished!\n";
        QMessageBox::warning(this, "WARN", "The Process to capture all Linux real users Failed!\n");
    }
    QMessageBox::information(this, "Real users: ", re_users.readAllStandardOutput());
    return;
}

void User_management::on_exit_pushButton_clicked()
{
    accept();
}

void User_management::on_info_pushButton_clicked()
{
    QMessageBox::information(this, "Usage Information", "Choose user creation or removal, enter new username and your password and press CREATE | REMOVE button!");
    return;
}
