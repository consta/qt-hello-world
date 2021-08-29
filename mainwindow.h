#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "MPoint.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    static int border;

public:
    MainWindow(QWidget *parent = nullptr);
    void start();
    ~MainWindow();

private slots:
    void addPoint();
    void on_btnAddPoint_pressed();

    void on_spinBoxBorder_valueChanged(double arg1);

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    std::vector<MPoint> points;
    int timerId;
};
#endif // MAINWINDOW_H
