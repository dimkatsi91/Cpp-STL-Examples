#ifndef LINUX_MANAGEMENT_H
#define LINUX_MANAGEMENT_H

#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class Linux_Management;
}

class Linux_Management : public QWidget
{
    Q_OBJECT

public:
    explicit Linux_Management(QWidget *parent = nullptr);
    ~Linux_Management();

    QString getUsername() const;

    QString getUser_password() const;

    void setUsername(const QString &value);

    void setUser_password(const QString &value);

    QString getNew_username() const;

    void setNew_username(const QString &value);

    QString getNew_user_password() const;

    void setNew_user_password(const QString &value);

private slots:
    void on_create_user_pushButton_clicked();

    void on_list_users_pushButton_clicked();

    void on_info_pushButton_clicked();

    void on_exit_pushButton_clicked();

    void on_clear_pushButton_clicked();

    /* Custom functions needed for creation or removal of a new user */
    /* Some sub-functions to help create the new user by creating his home directory
      * Also, a function to check if the user already exists in the system
      * Last, a function to add the user with 'useradd' Linux command
     */
     bool check_if_user_exists(QString &user_name);

     bool validate_username(QString &user_name);

     bool create_user_home(QString &user_name);

     bool remove_user_home(QString &user_name);

     bool add_the_user(QString &user_name);

     bool del_the_user(QString &user_name);

     QString getCurrentUsername();

     void on_pushButton_clicked();

     void on_show_password_checkBox_clicked();

     void on_show_new_password_checkBox_clicked();

private:
    Ui::Linux_Management *ui;
    // username and password for login and enter in the User Management or the Group Management
    QString username;
    QString user_password;
    QString new_username;
    QString new_user_password;
    bool logged_in;
};

#endif // LINUX_MANAGEMENT_H
