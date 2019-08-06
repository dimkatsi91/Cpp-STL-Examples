#ifndef GROUP_MANAGEMENT_H
#define GROUP_MANAGEMENT_H

#include <QDialog>

namespace Ui {
class Group_Management;
}

class Group_Management : public QDialog
{
    Q_OBJECT

public:
    explicit Group_Management(QWidget *parent = nullptr);
    ~Group_Management();

private:
    Ui::Group_Management *ui;
};

#endif // GROUP_MANAGEMENT_H
