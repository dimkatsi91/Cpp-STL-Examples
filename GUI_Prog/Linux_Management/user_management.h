#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <QDialog>

namespace Ui {
class User_management;
}

class User_management : public QDialog
{
    Q_OBJECT

public:
    explicit User_management(QWidget *parent = nullptr);
    ~User_management();

private:
    Ui::User_management *ui;
};

#endif // USER_MANAGEMENT_H
