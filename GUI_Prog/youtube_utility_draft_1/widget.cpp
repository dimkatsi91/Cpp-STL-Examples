/*
 * Author : dimos katsiamrdos
 * Date   : 2019/08/03
 * Info   : Create a youtube-dl GUI using Qt (Cute) Creator and linux youtube-dl utility
 *          Developed under Ubuntu 18.04 LTS | Qt Creator Open SOurce Community Edition
 */
#include "widget.h"
#include "ui_widget.h"
#include "youtube_dl_dialog.h"

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

void Widget::on_starter_button_clicked()
{
    // First, let us create the youtube-dl dialog class object
    Youtube_dl_Dialog *dialog = new Youtube_dl_Dialog(this);
    // Use exec() | show() methods to show it
    // Also capture the value to a variable in order to check the returned status of our Dialog
    // Becuase our dialog returns success ( accept() ) or failure ( reject() )
    int ret = dialog -> exec();
    if(ret == QDialog::Accepted) {
        qDebug() << "The main Youtube-dl GUI Utility is accepted!\n";
    }
    else if(ret == QDialog::Rejected) {
        qDebug() << "The main Youtube-dl GUI Utility is rejected!\n";
    }
}
