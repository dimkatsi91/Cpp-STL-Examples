#include "youtube_dl_dialog.h"
#include "ui_youtube_dl_dialog.h"

Youtube_dl_Dialog::Youtube_dl_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Youtube_dl_Dialog)
{
    ui->setupUi(this);
}

Youtube_dl_Dialog::~Youtube_dl_Dialog()
{
    delete ui;
}

void Youtube_dl_Dialog::on_ok_pushButton_clicked()
{
    qDebug() << "OK button is pushed ... Proceeding with Youtube-dl Utility ... \n";
    // Capture the entered url in a local string variable
    QString ytb_url = ui->youtube_url_liner->text();
    // Let us initialize the youtube-dl command that will download
    // an mp3 or an mkv artifact
    QString cmd_mp3 = "youtube-dl --extract-audio --audio-format mp3 ";
    QString cmd_mkv = "youtube-dl ";
    // The return code when the command is executed | 0-> command is executed successfully
    // 1 --> Command failed to execute
    int return_code=0;
    // Next, if string is not empty proceed
    if(!ytb_url.isEmpty()) {
        youtube_url = ytb_url;
        // Next, if this OK Button is clicked, since the youtube-url is not empty
        // we can proceed based on the choice the user chose : [ mp3 | mkv | exit ]
        // Action I :: Download mp3 format
        if(ui->mp3_radioButton->isChecked()) {
            // Download the youtube-url in mp3 format
            cmd_mp3 += ytb_url;
            return_code = system(cmd_mp3.toStdString().c_str());
            if(return_code==0) {
                qDebug() << "Download the mp3 SUCCESS!\n";
            } else {
                qDebug() << "Download the mp3 FAILED!\n";
            }
        }
        // Action II :: download mkv | video format
        if(ui->video_radioButton->isChecked()) {
            cmd_mkv += ytb_url;
            return_code = system(cmd_mkv.toStdString().c_str());
            if(return_code==0) {
                qDebug() << "Download the video SUCCESS!\n";
            }
            else {
                qDebug() << "Download the video FAILED!\n";
            }
        }
        if(ui->exit_radioButton->isChecked()) {
            qDebug() << "Exit has been chosen... Aborting procedure ... \n";
            reject();
        }
    }

    // END the dialog ... accept() function
    accept();
}

void Youtube_dl_Dialog::on_cancel_pushButton_clicked()
{
    qDebug() << "Cancel Button is pushed ... Aborting Youtube-dl GUI Utility ... \n";
    reject();
}
