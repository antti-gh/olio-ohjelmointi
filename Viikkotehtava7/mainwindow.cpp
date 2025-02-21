#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numberClickHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numberClickHandler);

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::operationClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::operationClickHandler);

    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearHandler);
    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::enterHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (state == 1) {
        number1 += button->text();
        ui->num1->setText(number1);
    } else {
        number2 += button->text();
        ui->num2->setText(number2);
    }
}

void MainWindow::operationClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (button == ui->add) operand = 0;
    else if (button == ui->sub) operand = 1;
    else if (button == ui->mul) operand = 2;
    else if (button == ui->div) operand = 3;

    state = 2;
}

void MainWindow::enterHandler() {
    int num1 = number1.toInt();
    int num2 = number2.toInt();
    int result = 0;

    switch (operand) {
    case 0: result = num1 + num2; break;
    case 1: result = num1 - num2; break;
    case 2: result = num1 * num2; break;
    case 3: result = num1 / num2; break;
    }

    updateDisplay();

    ui->result->setText(QString::number(result));

    number1.clear();
    number2.clear();
    state = 1;
}

void MainWindow::clearHandler() {
    number1.clear();
    number2.clear();
    ui->num1->clear();
    ui->num2->clear();
    ui->result->clear();
    state = 1;
    qDebug() << "Clearia painettu!";
}

void MainWindow::updateDisplay() {
    qDebug() << "Naytto paivitetty!";
}
