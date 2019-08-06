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
