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

    void on_show_current_passwd_pushButton_clicked();

    void on_hide_current_passwd_pushButton_clicked();

    void on_show_password_pushButton_clicked();

    void on_hide_password_pushButton_clicked();

    void on_list_users_pushButton_clicked();

    void on_info_pushButton_clicked();

    void on_exit_pushButton_clicked();

    void on_clear_pushButton_clicked();

private:
    Ui::Linux_Management *ui;
    // username and password for login and enter in the User Management or the Group Management
    QString username;
    QString user_password;
    QString new_username;
    QString new_user_password;
};

#endif // LINUX_MANAGEMENT_H
