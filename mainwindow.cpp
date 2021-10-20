#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMultimedia/QMediaPlayer"

#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList radios = {"Radio Javan",
                          "Radio Farda",
                          "Radio Golchin LA",
                          "Radio Shadi",
                          "IRAN Intel National",
                          "Radio Mojahed",
                          "",

                        "PARTY VIBE MUSIC : ALL THE HITS ALL THE TIME",
                        "Florida",
                        "RADIO ESTILO LEBLON",
                        "Classic Hits Global HD",
                        "Dance UK Radio danceradiouk",
                        "MoveDaHouse"};
    ui->listWidget->addItems(radios);

}

QMediaPlayer *player = new QMediaPlayer;


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_r_play_clicked()
{

    player->setMedia(QUrl(ui->r_url->text()));
    player->setVolume(60);
    player->play();

}

void MainWindow::sr(QString adrs){
    ui->r_url->setText(adrs);
    player->setMedia(QUrl(adrs));
    player->stop();
    player->play();
}
void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString txt = current->text();
    if(txt=="Radio Javan"){
        sr("http://74.115.215.36/");
    }
    else if(txt == "Florida"){
        sr("https://us4.internet-radio.com/proxy/douglassinclair?mp=/stream");
    }
    else if(txt == "RADIO ESTILO LEBLON"){
        sr("https://us4.internet-radio.com/proxy/radioestiloleblon?mp=/stream");
    }
    else if(txt == "Classic Hits Global HD"){
        sr("https://us2.internet-radio.com/proxy/chglobal?mp=/stream");
    }
    else if(txt == "Dance UK Radio danceradiouk"){
        sr("https://uk2.internet-radio.com/proxy/danceradiouk?mp=/stream");
    }
    else if(txt == "MoveDaHouse"){
        sr("https://uk7.internet-radio.com/proxy/movedahouse?mp=/stream");
    }
    else if(txt == "PARTY VIBE MUSIC : ALL THE HITS ALL THE TIME"){
        sr("https://uk6.internet-radio.com/proxy/pvradio?mp=/stream");
    }
    else if(txt == "Radio Farda"){
        sr("https://n09.radiojar.com/cp13r2cpn3quv?rj-ttl=5&rj-tok=AAABfETSRHkARIIGrQfYDMazLQ");
    }
    else if(txt == "IRAN Intel National"){
        sr("https://radio.iraninternational.app/iintl_c");
    }
    else if(txt == "Radio Golchin LA"){
        sr("https://radiogolchin.out.airtime.pro/radiogolchin_a");
    }
    else if(txt == "Radio Shadi"){
        sr("https://ice9.securenetsystems.net/SHADI");
    }
    else if(txt == "Radio Mojahed"){
        sr("https://s2.radio.co/s830691c74/listen");
    }
}

void MainWindow::on_r_volume_valueChanged(int value)
{
    player->setVolume(value);
    ui->perc_lbl->setText(QVariant(value).toString()+"%");
}

void MainWindow::on_pushButton_clicked()
{
    player->stop();
}
