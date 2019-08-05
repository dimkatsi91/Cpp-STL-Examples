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

QString User_management::getUsername() const
{
    return username;
}

bool User_management::validate_username()
{
    // Capture the username from the username_lineEdit widget
    username = ui->username_lineEdit->text();
    qDebug() << "Entered username is : " << username.toStdString().c_str() << "\n";

    // First check if the username QString is empty | Should not be empty of course !
    if(username.isEmpty()) {
        QMessageBox::information(this, "ERROR", "The username should not be empty!");
        return false;
    }
    // The entered username should not start with next characters or with a number
    // Also the username should not be the current user's name || root of course !!
    QVector<QString> invalid_characters = {"`", "~", "@", "!", "#", "$", "%", "^", "&", "*", "(", ")", "-", "+", "<", ">", ",", ".", "=", "_", "/", ";", ":", "?"};
    QVector<QString>::iterator start = invalid_characters.begin();
    QVector<QString> invalid_names = {"root"};
    // Call the function that captures the current logged user into the system with a QProcess
    QString current_username = getCurrentUsername();
    current_username.remove("\n");
    // Push the output to the vector of invalid_username strings || Exaclty the same as STL || Qt is Cute !
    invalid_names.push_back(current_username);
    qDebug() << "Command id -un returns the username : " << current_username;

    for(auto &invalid_username : invalid_names) {
        if(username==invalid_username) {
            QString error_message = "The username shall not be " + username + " ! Please be logic!";
            QMessageBox::information(this, "ERROR", error_message);
            return false;
        }
    }
    while(start!=invalid_characters.end()) {
        if(username[0]==*start) {
            QString error_msg = "The username should not begin with the character " + *start + " ! Please be logic";
            QMessageBox::information(this, "ERROR", error_msg);
            return false;
        }
        start++;
    }
    return true;
}

QString User_management::getCurrentUsername()
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

void User_management::on_user_exit_pushButton_clicked()
{
    qDebug() << "Exit button under user management utility was pushed. Aborting procedure ...\n";
    reject();
}

// This method is like a main() function for the 'User Management Utility'
void User_management::on_user_proceed_pushButton_clicked()
{
    qDebug() << "PROCEED button under User Management Utility was pushed. Proceeding ...\n";
    if(validate_username()==false) {
        return;
    }
    else {
        // This is our scenario :: Check here which radio button is pressed and proceed
        // with the appropriate needed actions ::
        qDebug() << "Username " << username.toStdString().c_str() << " is a valid user-name. Proceeding ... \n";
    }
}
