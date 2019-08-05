#ifndef GROUP_MANAGEMENT_H
#define GROUP_MANAGEMENT_H

#include <QDialog>

namespace Ui {
class Group_management;
}

class Group_management : public QDialog
{
    Q_OBJECT

public:
    explicit Group_management(QWidget *parent = nullptr);
    ~Group_management();

private:
    Ui::Group_management *ui;
    // A QString object/string variable for the storage of the entered groupname from the group_lineEdit
    QString groupname;
};

#endif // GROUP_MANAGEMENT_H
