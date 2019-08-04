#include "youtube_dl_dialog.h"
#include "ui_youtube_dl_dialog.h"

Youtube_dl_Dialog::Youtube_dl_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Youtube_dl_Dialog)
{
    ui->setupUi(this);

    // Set colors for elements
    /* Configure them based on your visual appealings
    QPalette blue, black, cyan;
    labels.setColor(QPalette::Window, Qt::white);     // background color
    blue.setColor(QPalette::WindowText, Qt::blue);     // blue text color
    black.setColor(QPalette::WindowText, Qt::black);  // black text color
    cyan.setColor(QPalette::WindowText, Qt::cyan);  // red text color

    // youtube_url_label
    ui->youtube_url_label->setPalette(blue);
    // path_label
    ui->path_label->setPalette(blue);
    // Groupbox
    ui->options_groupBox->setPalette(blue);
    // Radio buttons
    ui->mp3_radioButton->setPalette(black);
    ui->video_radioButton->setPalette(black);
    ui->exit_radioButton->setPalette(cyan);
    ui->cancel_pushButton->setPalette(cyan);
    */

    // Create a QPixMap Object | You have to specify your logo image path here
    QPixmap pix("/home/diman91/Documents/QT_Creator/youtube_utility_draft_1/beta_logo.jpg");
    int width = ui->label_beta->width();
    int height = ui->label_beta->height();
    ui->label_beta->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));

    // Create a QProcess Object to capture the output of Linux commands
    /* Print info about where this GUI is running using QProcess widget
     * QString username = id -un
     * QString hostname = hostname
     * QString date     = date
    */
    QProcess id, date, hostname, time;
    QString id_output, date_output, hostname_output; //time_output;
    QString AIO;
    id.start("id -un");     // SAME AS id.start("id", QStringList << "-un");
    id.waitForFinished();
    id_output = id.readAllStandardOutput();
    //qDebug() << id_output << endl;

    date.start("date +%Y/%m/%d");
    date.waitForFinished();
    date_output = date.readAllStandardOutput();

    hostname.start("hostname");
    hostname.waitForFinished();
    hostname_output = hostname.readAllStandardOutput();

    //time.start("date +%H:%M:%S");
    //time.waitForFinished();
    //time_output = time.readAllStandardOutput();

    // Output all this info to the system_label
    //AIO = "HOST: " + hostname_output + "USER: " + id_output + "\nDATE: " + date_output + "\nTime: " + time_output;
    //AIO = "DATE : " + date_output + "\nTIME : " + time_output;
    AIO = "HOST : " + hostname_output + "\nUSER : " + id_output + "\nDATE : " + date_output;
    ui->system_label->setText(AIO);
}

Youtube_dl_Dialog::~Youtube_dl_Dialog()
{
    delete ui;
}

void Youtube_dl_Dialog::on_ok_pushButton_clicked()
{
    qDebug() << "OK button is pushed ... Proceeding with Youtube-dl Utility ... \n";
    // Capture the entered url in a local string variable
    youtube_url = ui->youtube_url_liner->text();
    // Capture the path_url from the path_liner in alocal string variable
    path_url = ui->path_liner->text();

    // Let us initialize the youtube-dl command that will download
    // an mp3 or an mkv artifact
    QString cmd_mp3 = "youtube-dl ";
    QString cmd_mkv = "youtube-dl ";
    QString option_audio = " --extract-audio --audio-format mp3 ";
    QString cmd_cd = "cd " + path_url;

    qDebug() << "Navigating to the chosen path " << path_url.toStdString().c_str() << " ... \n";
    if(!system(cmd_cd.toStdString().c_str())) {
        qDebug() << "[ DONE ] Navigating to the chosen path ... \n";
    }
    else {
        qDebug() << "[ FAILURE ] Navigating to the chosen path ... \n";
        QMessageBox::information(this, "ERROR!", "This directory does not exist!");
        return;
    }

    // The return code when the command is executed | 0-> command is executed successfully
    // 1 --> Command failed to execute
    int return_code=0;

    if(ui->exit_radioButton->isChecked()) {
        qDebug() << "Exit procedure ... It seems you changed your mind!\n";
        QMessageBox::information(this, "EXIT", "Nothing to do!");
        accept();
        return;
    }

    // If the url or the path is empty open a message box and display a message
    if(youtube_url.isEmpty()) {
        QMessageBox::information(this, "FAILURE", "Youtube URL should not be empty!");
    }

    if(path_url.isEmpty()) {
        QMessageBox::information(this, "FAILURE", "Path should not be empty!");
    }

    // Next, if youtube url && saved path string are not empty, then proceed
    if(!youtube_url.isEmpty() && !path_url.isEmpty()) {
        // Next, if this OK Button is clicked, since the youtube-url and the path are not empty
        // we can proceed based on the choice the user chose : [ mp3 | mkv | exit ]
        // Action I :: Download mp3 format
        if(ui->mp3_radioButton->isChecked()) {
            // Download the youtube-url in mp3 format
            cmd_mp3 = cmd_mp3 + option_audio + youtube_url;
            // Naviaate to the provided path && perform url download
            cmd_mp3 = cmd_cd + " && " + cmd_mp3;
            return_code = system(cmd_mp3.toStdString().c_str());
            if(return_code==0) {
                // Concole information prit-out
                qDebug() << "Download the mp3 SUCCESS!\n";
                QMessageBox::information(this, "INFO", "Song download completed!");
            } else {
                qDebug() << "Download the mp3 FAILED!\n";
                QMessageBox::information(this, "WARN", "Song download failed!");
            }
        }
        // Action II :: download mkv | video format
        if(ui->video_radioButton->isChecked()) {
            cmd_mkv += youtube_url;
            // Navigate to the provided path and perform youtube video download
            cmd_mkv = cmd_cd + " && " + cmd_mkv;
            return_code = system(cmd_mkv.toStdString().c_str());
            if(return_code==0) {
                qDebug() << "Download the video SUCCESS!\n";
                QMessageBox::information(this, "INFO", "Video download completed!");
            }
            else {
                qDebug() << "Download the video FAILED!\n";
                QMessageBox::information(this, "WARN", "Video download failed!");
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

void Youtube_dl_Dialog::on_info_button_clicked()
{
    QMessageBox::information(this, "INFO", "This is a simple Youtube-dl GUI to help You download a url in music or video format!\nEnter url, path, choose format and press PROCEED");
}
