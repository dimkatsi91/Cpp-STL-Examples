#include "group_management.h"
#include "ui_group_management.h"

Group_management::Group_management(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Group_management)
{
    ui->setupUi(this);
}

Group_management::~Group_management()
{
    delete ui;
}
