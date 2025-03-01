#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startGame_clicked();   // Aloitusnappi
    void updateProgressBar();      // Proggressbar
    void on_p1end_clicked();       // Pelaaja 1 nappi
    void on_p2end_clicked();       // Pelaaja 2 nappi
    void on_setTime120_clicked();  // Peliaika 120 sekuntia nappi
    void on_setTime300_clicked();  // Peliaika 5 minuuttia nappi
    void on_stopGame_clicked();    // Stop nappi

private:
    Ui::MainWindow *ui;
    int p1Time = 0;
    int p2Time = 0;
    int currentPlayer;
    int gameTime;
    QTimer *timer;
};

#endif // MAINWINDOW_H

