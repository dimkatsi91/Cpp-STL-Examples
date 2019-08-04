#ifndef YOUTUBE_DL_DIALOG_H
#define YOUTUBE_DL_DIALOG_H

#include <QDialog>

#include <QDebug>             // for debug messages diaplyed in the Qt Creator console
#include <QMessageBox>       //  Message boxes
#include <stdlib.h>         //   system() function
#include <QPixmap>         //    for the beta version logo

namespace Ui {
class Youtube_dl_Dialog;
}

class Youtube_dl_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Youtube_dl_Dialog(QWidget *parent = nullptr);
    ~Youtube_dl_Dialog();

private slots:
    void on_ok_pushButton_clicked();

    void on_cancel_pushButton_clicked();

    void on_info_button_clicked();

private:
    // Let us define a string for storing the entered youtube url
    // from the user that will be used by the line edit widget
    QString youtube_url;
    // Let us also define a string QString actually, that will capture
    // the path that the user will enter in order to save his url song or whatever !
    QString path_url;
    QTimer *timer;
    Ui::Youtube_dl_Dialog *ui;
};

#endif // YOUTUBE_DL_DIALOG_H
