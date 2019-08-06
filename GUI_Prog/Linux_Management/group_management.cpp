#include "group_management.h"
#include "ui_group_management.h"

Group_Management::Group_Management(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Group_Management)
{
    ui->setupUi(this);
}

Group_Management::~Group_Management()
{
    delete ui;
}
