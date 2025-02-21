#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void numberClickHandler();
    void operationClickHandler();
    void clearHandler();
    void enterHandler();

    void updateDisplay();

private:
    Ui::MainWindow *ui;
    QString number1;
    QString number2;
    int operand = -1;
    int state = 1;
};
#endif // MAINWINDOW_H
