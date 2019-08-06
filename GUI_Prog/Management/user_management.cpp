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

    // Pre-processing Step #0 : Check if an id exists in the system ::
    QProcess check_id_proc;
    check_id_proc.start("grep " + username + " /etc/passwd");
    if(check_id_proc.exitCode()==0) {
        qDebug() << "This user already exists in the system!\n";
        QMessageBox::information(this, "ERROR", "This user already exists in the system!\n");
        return false;
    }

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
    //qDebug() << "Command id -un returns the username : " << current_username;

    for(auto &invalid_username : invalid_names) {
        if(username==invalid_username) {
            QString error_message = "The username shall not be " + username + "!\nPlease be logical!";
            QMessageBox::information(this, "ERROR", error_message);
            return false;
        }
    }
    while(start!=invalid_characters.end()) {
        if(username[0]==*start) {
            QString error_msg = "The username should not begin with the character " + *start + "!\nPlease be logical!\n";
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

bool User_management::create_user_home(QString &user_name)
{
    // Create the home dir : /home/$user_name
    QProcess mkdir_proc1, mkdir_proc2;
    mkdir_proc1.setStandardOutputProcess(&mkdir_proc2);
    mkdir_proc1.start("echo " + user_password);
    mkdir_proc2.start("sudo -S mkdir /home/" + user_name);
    mkdir_proc1.waitForFinished();
    mkdir_proc2.waitForFinished();

    // Give appropriate permissions
    QProcess chmod_proc1, chmod_proc2, chown_proc1, chown_proc2;
    chmod_proc1.setStandardOutputProcess(&chmod_proc2);
    chmod_proc1.start("echo " + user_password);
    chmod_proc2.start("sudo -S chmod -R u=rwx,g=rw,o=--- /home/" + user_name);
    chmod_proc1.waitForFinished();
    chmod_proc2.waitForFinished();

    chown_proc1.setStandardOutputProcess(&chown_proc2);
    chown_proc1.start("echo " + user_password);
    chown_proc2.start("sudo -S chown " + user_name + " /home/" + user_name);
    chown_proc1.waitForFinished();
    chown_proc2.waitForFinished();

    return true;
}

bool User_management::add_the_user(QString &user_name)
{
    // First call the create_user_home() function in order to create the home dir for the new user
    if(create_user_home(user_name)==false) {
        QMessageBox::information(this, "ERROR", "Could not create the home directory for user : " + user_name);
        return false;
    }
    // The same as usual ...
    QProcess useradd_proc1, useradd_proc2;
    useradd_proc1.setStandardOutputProcess(&useradd_proc2);
    useradd_proc1.start("echo " + user_password);
    useradd_proc2.start("sudo -S useradd -s /bin/bash " + user_name);
    useradd_proc1.waitForFinished();
    useradd_proc2.waitForFinished();
    if(useradd_proc2.exitCode()==0) {
        return true;
    }
    qDebug() << "\n\n********** ERROR ret code != 0 \n\n";
    return false;
}

bool User_management::del_the_user(QString &user_name)
{
    // Remove the user from the system
    return false;
}

bool User_management::mod_the_user(QString &user_name)
{
    // Change user name
    return false;
}

bool User_management::shell_change(QString &user_name, QString &new_shell)
{
    // Change user login shell
    return false;
}

bool User_management::passwd_change(QString &user_name, QString &new_password)
{
    // Change user password
    return false;
}

QString User_management::cat_users(void)
{
    // Process to run a Linux command & capture all real Linux users
    QProcess re_users;
    re_users.start("bash", QStringList() << "-c" << "cut -d: -f1,3 /etc/passwd | egrep ':[0-9]{4}$' | cut -d: -f1");
    if(!re_users.waitForFinished()) {
        qDebug() << "Oops something went wrong when capturing all real Linux users ... The process is not finished!\n";
        QMessageBox::warning(this, "WARN", "The Process to capture all Linux real users Failed!\n");
    }
    // Return the real human-like users
    return re_users.readAllStandardOutput();
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
    if(ui->list_users_radioButton->isChecked()) {
        qDebug() << "Real System Users : \n";
        QMessageBox::information(this, "Real users: ", cat_users());
        return;
    }

    // First of all, check for user password | These tools need user's own password to run sudo commands
    // Otherwise, this tool is unable to run
    user_password = ui->user_password_lineEdit->text();
    if(user_password.isEmpty()) {
        qDebug() << "Please provide " + username + " 's password!\nThese tools need superuser privileges!";
        QMessageBox::information(this, "ERROR", "Please provide " + username + " 's password!\nThese tools need superuser privileges!");
        return;
    }

    if(validate_username()==false) {
        return;
    }
    else {
        // This is our scenario :: Check here which radio button is pressed and proceed
        // with the appropriate needed actions ::
        qDebug() << "Username " << username.toStdString().c_str() << " is a valid user-name. Proceeding ... \n";
        // Action 1 : Add a user using the useradd command :: Call the useradd function
        if(ui->useradd_radioButton->isChecked()) {
            if(add_the_user(username)==true) {
                QMessageBox::information(this, "INFO", "New user named : " + username + " was created with success!\n");
            } else {
                QMessageBox::information(this, "ERROR", "Something went wrong during user : " + username + " creation!\n");
            }
        }
        // Action 2 : Remove the user :: Call the del_the_user() function

        // Action 3 : Rename the user :: Call the mod_the_user() function

        // Action 4 : Change the shell for the user : Call the shell_change() function

        // Action 5 : Change the user password : Call the passwd_user() function

        // Action 6 : List all system users : Real and system users included | I don't care
        // This is implemented first of all, since no check needs to be done | It is just a cat action
    }
}
