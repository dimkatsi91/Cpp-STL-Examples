#include "linux_management.h"
#include "ui_linux_management.h"
#include "user_management.h"
#include "group_management.h"

Linux_Management::Linux_Management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Linux_Management)
{
    ui->setupUi(this);

    // When capturing the password do not show the text please :: Security issues
    // username btw can be shown :: You can change it of course if U would like so
    ui->username_lineEdit->setEchoMode(QLineEdit::Normal);
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);

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

void Linux_Management::on_user_mgmnt_pushButton_clicked()
{
    if(sanity_check()==false) {
        qDebug() << "Sanity check failed after pressing the user_mgmnt button...\n";
        QMessageBox::warning(this, "WARNING", "The username or the password shall not be empty!\nPlease try again!");
        return;
    }
    QMessageBox::information(this, "INFO", "Have in mind that your credentials will be used for next actions.If incorrect logout and login again!");
    User_management *user_mgmnt_dialog = new User_management(this);
    int ret_code = user_mgmnt_dialog->exec();
    if(ret_code==QDialog::Accepted) {
        qDebug() << "User management completed successfully!\n";
    }
    else  if(ret_code==QDialog::Rejected) {
        qDebug() << "User management completed un-successfully!\n";
    }
}

void Linux_Management::on_group_mgmnt_pushButton_clicked()
{
    if(sanity_check()==false) {
        qDebug() << "Sanity check failed after pressing the group_mgmnt button...\n";
        QMessageBox::warning(this, "WARNING", "The username or the password shall not be empty!\nPlease try again!");
        return;
    }
    QMessageBox::information(this, "INFO", "Have in mind that your credentials will be used for next actions.If incorrect logout and login again!");
    // Open the group management Dialog Box, just like we did above for user management
    Group_Management *group_mgmnt_dialog = new Group_Management(this);
    int ret_code = group_mgmnt_dialog->exec();
    if(ret_code==QDialog::Accepted) {
            qDebug() << "Group management completed successfully!\n";
    }
    else  if(ret_code==QDialog::Rejected) {
        qDebug() << "Group management completed un-successfully!\n";
    }
}

void Linux_Management::on_exit_pushButton_clicked()
{
    // Exit when this main_exit_pushButton is clicked
    // For some reason needs to be pressed twice in order to quit
    // I will register a bug to myself for this | will fix it soon btw!
    connect(ui->exit_pushButton, SIGNAL(clicked()),
            this, SLOT(close()));
    qDebug() << "Exit button is pushed from main application window ... Aborting procedure ... \n";
}

bool Linux_Management::sanity_check()
{
    // Capture username & user_password for starters
    setUsername(ui->username_lineEdit->text());
    setUser_password(ui->password_lineEdit->text());

    qDebug() << "Username: " << getUsername() << "\nPassword = " << getUser_password() << "\n";
    if(!getUsername().isEmpty() && !getUser_password().isEmpty() && validate_username()==true) {
        return true;
    }
    return false;
}

bool Linux_Management::validate_username()
{
    // The entered username should not start with next characters or with a number
    // Also the username should not be the current user's name || root of course !!
    QVector<QString> invalid_characters = {"`", "~", "@", "!", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+", "<", ">", ",", ".", "=", "_", "/", ";", ":", "?"};
    // Do not forget to add the [0-9] digits in the excpetions for the username starting characters
    QVector<QString>::iterator start = invalid_characters.begin();
    QVector<QString> invalid_names = {"root"};
    //QString current_username = find_logged_user();
    //current_username.remove("\n");
    // Push the output to the vector of invalid_username strings || Exaclty the same as STL || Qt is Cute !
    //invalid_names.push_back(current_username);
    for(auto &invalid_username : invalid_names) {
        if(getUsername()==invalid_username) {
            QString error_message = "The username shall not be " + getUsername() + "!\nPlease be logical!";
            QMessageBox::warning(this, "WARNING", error_message);
            return false;
        }
    }
    while(start!=invalid_characters.end()) {
        if(username[0]==*start) {
            QString error_msg = "The username should not begin with the character " + *start + "!\nPlease be logical!\n";
            QMessageBox::warning(this, "WARNING", error_msg);
            return false;
        }
        start++;
    }
    qDebug() << "validate_username() returned true\n";
    return true;
}

QString Linux_Management::find_logged_user()
{
    // Open a QProcess
    QProcess logged_user_proc;
    // Capture the logged user into the system
    logged_user_proc.start("id -un \n");
    // Wait process to end
    logged_user_proc.waitForFinished();
    // return the logged user's username
    return logged_user_proc.readAllStandardOutput();
}

void Linux_Management::setUser_password(const QString &value)
{
    user_password = value;
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
