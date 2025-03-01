#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(nullptr)
    , gameTime(120)
    , currentPlayer(1)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }
    delete ui;
}

// Peliajan valinta 120 sekuntia
void MainWindow::on_setTime120_clicked()
{
    gameTime = 120;
    ui->label->setText("Peliaika asetettu: 120 sekuntia");
}

// Peliajan valinta 5 minuuttia
void MainWindow::on_setTime300_clicked()
{
    gameTime = 300;
    ui->label->setText("Peliaika asetettu: 5 minuuttia");
}

// Pelin aloitus
void MainWindow::on_startGame_clicked()
{
    p1Time = gameTime;
    p2Time = gameTime;
    currentPlayer = 1;

    ui->progressBar_1->setRange(0, gameTime);
    ui->progressBar_2->setRange(0, gameTime);
    ui->progressBar_1->setValue(gameTime);
    ui->progressBar_2->setValue(gameTime);
    ui->label->setText("Peli käynnistyi!");

    if (timer) {
        timer->stop();
        delete timer;
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    timer->setInterval(1000);
    timer->start();
}

//Progressbar asetus
void MainWindow::updateProgressBar()
{
    if (currentPlayer == 1) {
        if (p1Time > 0) {
            p1Time--;
            ui->progressBar_1->setValue(p1Time);
        }
        if (p1Time == 0) {
            timer->stop();
            ui->label->setText("Pelaaja 1 hävisi!");
        }
    } else {
        if (p2Time > 0) {
            p2Time--;
            ui->progressBar_2->setValue(p2Time);
        }
        if (p2Time == 0) {
            timer->stop();
            ui->label->setText("Pelaaja 2 hävisi!");
        }
    }
}

// Pelaajan vaihto
void MainWindow::on_p1end_clicked()
{
    currentPlayer = 2;
}

void MainWindow::on_p2end_clicked()
{
    currentPlayer = 1;

}

//Stop nappi
void MainWindow::on_stopGame_clicked()
{
    if (timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }
    p1Time = 0;
    p2Time = 0;
    ui->progressBar_1->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->label->setText("Peli pysäytetty. Aseta aika ja käynnistä uudelleen.");
}

