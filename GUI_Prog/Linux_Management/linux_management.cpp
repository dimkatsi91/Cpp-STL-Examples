#include "linux_management.h"
#include "ui_linux_management.h"

Linux_Management::Linux_Management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Linux_Management)
{
    ui->setupUi(this);

    // When capturing the password do not show the text please :: Security issues
    // username btw can be shown :: You can change it of course if U would like so
    ui->username_lineEdit->setEchoMode(QLineEdit::Normal);
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);
    ui->new_user_password_lineEdit->setEchoMode(QLineEdit::Password);

    QPixmap user_login_pix("/home/diman91/Documents/QT_Creator/Linux_Management/images/user.svg");
    int w1 = ui->user_login_icon_label->width();
    int h1 = ui->user_login_icon_label->height();
    ui->user_login_icon_label->setPixmap(user_login_pix.scaled(w1, h1, Qt::KeepAspectRatio));
    QPixmap user_passwd_pix("/home/diman91/Documents/QT_Creator/Linux_Management/images/lock.svg");
    int w2 = ui->user_pass_login_label->width();
    int h2 = ui->user_pass_login_label->height();
    ui->user_pass_login_label->setPixmap(user_passwd_pix.scaled(w2, h2, Qt::KeepAspectRatio));
}

Linux_Management::~Linux_Management()
{
    delete ui;
}

void Linux_Management::setUser_password(const QString &value)
{
    user_password = value;
}

QString Linux_Management::getNew_username() const
{
    return new_username;
}

void Linux_Management::setNew_username(const QString &value)
{
    new_username = value;
}

QString Linux_Management::getNew_user_password() const
{
    return new_user_password;
}

void Linux_Management::setNew_user_password(const QString &value)
{
    new_user_password = value;
}

void Linux_Management::setUsername(const QString &value)
{
    username = value;
}

QString Linux_Management::getUser_password() const
{
    return user_password;
}

QString Linux_Management::getUsername() const
{
    return username;
}

void Linux_Management::on_create_user_pushButton_clicked()
{
    // Set the strings from the entered text in the respective lineEdit widgets
    setUsername(ui->username_lineEdit->text());
    setUser_password(ui->password_lineEdit->text());

    // Set the new username and password
    setNew_username(ui->new_username_lineEdit->text());
    setNew_user_password(ui->new_user_password_lineEdit->text());

}
//ui->password_lineEdit->setEchoMode(QLineEdit::Password);

void Linux_Management::on_show_current_passwd_pushButton_clicked()
{
    ui->password_lineEdit->setEchoMode(QLineEdit::Normal);
}

void Linux_Management::on_hide_current_passwd_pushButton_clicked()
{
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);
}

void Linux_Management::on_show_password_pushButton_clicked()
{
    ui->new_user_password_lineEdit->setEchoMode(QLineEdit::Normal);
}

void Linux_Management::on_hide_password_pushButton_clicked()
{
    ui->new_user_password_lineEdit->setEchoMode(QLineEdit::Password);
}

void Linux_Management::on_list_users_pushButton_clicked()
{
    // Process to run a Linux command & capture all real Linux users
    QProcess re_users;
    re_users.start("bash", QStringList() << "-c" << "cut -d: -f1,3 /etc/passwd | egrep ':[0-9]{4}$' | cut -d: -f1");
    if(!re_users.waitForFinished()) {
        qDebug() << "Oops something went wrong when capturing all real Linux users ... The process is not finished!\n";
        QMessageBox::warning(this, "WARN", "The Process to capture all Linux real users Failed!\n");
    }
    QMessageBox::information(this, "System human users", re_users.readAllStandardOutput());
    return;
}

void Linux_Management::on_info_pushButton_clicked()
{
    QMessageBox::information(this, "Usage Information", "Choose user creation or removal, enter new username and your password and press CREATE | REMOVE button!");
    return;
}

void Linux_Management::on_exit_pushButton_clicked()
{
    close();
}

void Linux_Management::on_clear_pushButton_clicked()
{
    ui->username_lineEdit->setText("");
    ui->password_lineEdit->setText("");
    ui->new_username_lineEdit->setText("");
    ui->new_user_password_lineEdit->setText("");

    return;
}
