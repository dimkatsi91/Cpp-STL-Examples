#include "linux_management.h"
#include "ui_linux_management.h"

Linux_Management::Linux_Management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Linux_Management)
{
    ui->setupUi(this);

    logged_in = true;

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

//////////////////////////////////////////////////////////////////////////////////////
bool Linux_Management::check_if_user_exists(QString &user_name)
{
    // Pre-processing Step #0 : Check if an id exists in the system ::
    QProcess check_id_proc;
    check_id_proc.start("id -un " + user_name);
    check_id_proc.waitForFinished();
    if(check_id_proc.exitCode()==0) {
        qDebug() << "This user named: " + check_id_proc.readAllStandardOutput() + " already exists in the system!\n";
        //QMessageBox::warning(this, "WARNING", "This user already exists in the system!\n");
        return true;
    }
    // If the user does not exist, return false
    return false;
}

bool Linux_Management::validate_username(QString &user_name)
{
    qDebug() << "Entered username is : " << user_name.toStdString().c_str() << "\n";

    // First check if the username QString is empty | Should not be empty of course !
    if(user_name.isEmpty()) {
        QMessageBox::warning(this, "WARNING", "The username should not be an empty string!");
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
        if(user_name==invalid_username) {
            QString error_message = "The username shall not be " + user_name + "!\nPlease be logical!";
            QMessageBox::warning(this, "WARNING", error_message);
            return false;
        }
    }
    while(start!=invalid_characters.end()) {
        if(user_name[0]==*start) {
            QString error_msg = "The username should not begin with the character " + *start + "!\nPlease be logical!\n";
            QMessageBox::warning(this, "WARNING", error_msg);
            return false;
        }
        start++;
    }
    return true;
}

bool Linux_Management::create_user_home(QString &user_name)
{
    // Create the home dir : /home/$user_name
    QProcess mkdir_proc;
    mkdir_proc.start("bash", QStringList() << "-c" << "echo " << user_password << " | " << " sudo -S mkdir /home/" + user_name);
    mkdir_proc.waitForFinished();

    // Give appropriate permissions
    QProcess chmod_proc, chown_proc;
    chmod_proc.start("bash", QStringList() << "-c" << "echo " + user_password << " | " << "sudo -S chmod -R u=rwx,g=rw,o=--- /home/" + user_name);
    chmod_proc.waitForFinished();
    chown_proc.start("bash", QStringList() << "-c" << "echo " + user_password << " | sudo -S /home/" << user_name);
    chown_proc.waitForFinished();

    return true;
}

bool Linux_Management::remove_user_home(QString &user_name)
{
    // Remove the home dir : /home/$user_name
    QProcess rmdir_proc1, rmdir_proc2;
    rmdir_proc1.setStandardOutputProcess(&rmdir_proc2);
    rmdir_proc1.start("echo " + user_password);
    rmdir_proc2.start("sudo -S rm -r /home/" + user_name);
    rmdir_proc1.waitForFinished();
    rmdir_proc2.waitForFinished();

    return true;
}

bool Linux_Management::add_the_user(QString &user_name)
{
    // First call the create_user_home() function in order to create the home dir for the new user
    if(create_user_home(user_name)==false) {
        QMessageBox::information(this, "ERROR", "Could not create the home directory for user : " + user_name);
        return false;
    }
    // The same as usual ...
    QProcess useradd_proc;
    useradd_proc.start("bash", QStringList() << "-c" << " | sudo -S useradd -s /bin/bash " + user_name);
    useradd_proc.waitForFinished();

    if(useradd_proc.exitCode()==0) {
        return true;
    }
    qDebug() << useradd_proc.readAllStandardOutput() << endl;
    qDebug() << "\n\n********** An ERROR occured during the creation of the new user: " + user_name + "\n";
    return false;
}

bool Linux_Management::del_the_user(QString &user_name)
{
    // First, remove the user_name's home directory
    if(remove_user_home(user_name)==false) {
        //QMessageBox::warning(this, "WARNING", "Could not remove the directory: /home/" + user_name + ". Maybe it does not exist!");
        qDebug() << "Could not remove the directory: /home/" + user_name + ". Maybe it does not exist!";
    }
    QMessageBox::information(this, "INFO", "Home directory: /home/" + user_name + " was just removed from the system.");
    // Remove the user id entry from the system
    QProcess userdel_proc1, userdel_proc2;
    userdel_proc1.setStandardOutputProcess(&userdel_proc2);
    userdel_proc1.start("echo " + user_password);
    userdel_proc2.start("sudo -S userdel " + user_name);
    userdel_proc1.waitForFinished();
    userdel_proc2.waitForFinished();
    if(userdel_proc2.exitCode()==0) {
        QMessageBox::information(this, "INFO", "Removed the user: " + user_name + " entry from the system!");
        return true;
    }
    QMessageBox::warning(this, "WARNING", "The user: " + user_name + " entry was not removed from the system!");
    return false;
}

QString Linux_Management::getCurrentUsername()
{
    // Open a QProcess
    QProcess logged_user_proc;
    // Capture the logged user into the system
    logged_user_proc.start("id -un");
    // Wait process to end
    logged_user_proc.waitForFinished();
    // return the logged user's username
    QString current_user = logged_user_proc.readAllStandardOutput();
    return current_user.remove("\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Linux_Management::on_create_user_pushButton_clicked()
{
    // Set the new username and password
    setNew_username(ui->new_username_lineEdit->text());
    setNew_user_password(ui->new_user_password_lineEdit->text());

    qDebug() << "User: " << username << " Password: " << user_password << endl;
    qDebug() << "New user to be created: " << new_username << " Password: " << new_user_password << endl;

    if(new_username.isEmpty() || new_user_password.isEmpty()) {
        qDebug() << "The new username and password should not be empty!Please try again!";
        QMessageBox::information(this, "WARNING", "The new username and password should not be empty!Please try again!");
        return;
    }

    if(validate_username(new_username)==false) {
        qDebug() << "The new username is not a valid one. Please try again!";
        QMessageBox::warning(this, "WARNING", "The new username is not a valid one. Please try again!");
        return;
    }

    if(check_if_user_exists(new_username)==false) {
        if(add_the_user(new_username)==true) {
            QMessageBox::information(this, "INFO", "The user named: " + new_username+ " was created with success!");
            return;
        } else {
            QMessageBox::warning(this, "WARNING", "New user name: " + new_username + " failed to be created!");
            return;
        }
    }

}


void Linux_Management::on_pushButton_clicked()
{
    // Set the strings from the entered text in the respective lineEdit widgets
    setUsername(ui->username_lineEdit->text());
    setUser_password(ui->password_lineEdit->text());

    if(username.isEmpty() || user_password.isEmpty()) {
        QMessageBox::warning(this, "WARNING", "Username and password shall not be empty. Please try again!");
        qDebug() << "Username and password shall not be empty. Please try again!";
        logged_in = false;
        return;
    }

    QString current_user = getCurrentUsername();
    qDebug() << current_user;
    if(username!=current_user) {
        QMessageBox::warning(this, "WARNING", "False username. Please enter correct username!");
        qDebug() << "False username entered...\n";
        logged_in = false;
        return;
    }
    QMessageBox::information(this, "INFO", "Please have in mind that wrong password will cause this utility not to create or delete a user!");
}

void Linux_Management::on_show_password_checkBox_clicked()
{
    if(ui->password_lineEdit->echoMode()==QLineEdit::Password) {
        ui->password_lineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->password_lineEdit->setEchoMode(QLineEdit::Password);
    }
     return;
}


void Linux_Management::on_show_new_password_checkBox_clicked()
{
    if(ui->new_user_password_lineEdit->echoMode()==QLineEdit::Password) {
        ui->new_user_password_lineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->new_user_password_lineEdit->setEchoMode(QLineEdit::Password);
    }
     return;
}
