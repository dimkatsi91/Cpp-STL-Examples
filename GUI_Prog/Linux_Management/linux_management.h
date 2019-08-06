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

private slots:
    void on_user_mgmnt_pushButton_clicked();

    void on_group_mgmnt_pushButton_clicked();

    void on_exit_pushButton_clicked();

    /* bool function that checks for username and password to be entered in order to proceed */
    bool sanity_check();

    /* Make a simple check that the username is not root or current user, or does not start with a digit
       or with a special character
     */
    bool validate_username();

    /* Find the current logged user and grep his name and return this QString */
    QString find_logged_user();

private:
    Ui::Linux_Management *ui;
    // username and password for login and enter in the User Management or the Group Management
    QString username;
    QString user_password;
};

#endif // LINUX_MANAGEMENT_H
