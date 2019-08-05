#include "widget.h"
#include "ui_widget.h"
#include "user_management.h"
#include "group_management.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_main_exit_pushButton_clicked()
{
    // Exit when this main_exit_pushButton is clicked
    // For some reason needs to be pressed twice in order to quit
    // I will register a bug to myself for this | will fix it soon btw!
    connect(ui->main_exit_pushButton, SIGNAL(clicked()),
            this, SLOT(close()));
    qDebug() << "Exit button is pushed from main application window ... Aborting procedure ... \n";

}

void Widget::on_start_user_management_pushButton_clicked()
{
    // Open the user management Dialog Box
    User_management *user_mgmnt_dialog = new User_management(this);
    int ret_code = user_mgmnt_dialog->exec();
    if(ret_code==QDialog::Accepted) {
            qDebug() << "User management completed successfully!\n";
    }
    else  if(ret_code==QDialog::Rejected) {
        qDebug() << "User management completed un-successfully!\n";
    }
}

void Widget::on_start_group_management_pushButton_clicked()
{
    // Open the group management Dialog Box, just like we did above for user management
    Group_management *group_mgmnt_dialog = new Group_management(this);
    int ret_code = group_mgmnt_dialog->exec();
    if(ret_code==QDialog::Accepted) {
            qDebug() << "Group management completed successfully!\n";
    }
    else  if(ret_code==QDialog::Rejected) {
        qDebug() << "Group management completed un-successfully!\n";
    }
}
