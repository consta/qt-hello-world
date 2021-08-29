#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <math.h>

static int border = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsView *gv = ui->gv;
    scene = new QGraphicsScene(this);
    gv->setScene(scene);
    ui->spinBoxBorder->setValue((double) ::border);
    timerId = startTimer(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start() {


}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerId) {
        QGraphicsView *gv = ui->gv;
        const int width = gv->width();
        const int height = gv->height();
        scene->clear();
        QPolygon polygon = QPolygon(
                QRect(
                        QPoint(::border,::border),
                        QPoint(width - ::border, height - ::border)));
        scene->addPolygon(polygon, QPen(Qt::red));
        for (MPoint &p: points) {
            p.move();
            int x = ::border + (p.getX() * (width - 2 * ::border));
            int y = ::border + (p.getY() * (height - 2 * ::border));
            scene->addEllipse(x, y, 2, 2, QPen(Qt::darkBlue));
        }

        gv->viewport()->update();
    }
}

void MainWindow::addPoint() {
    double x = (double) rand() / RAND_MAX;
    double y = (double) rand() / RAND_MAX;

    points.push_back(MPoint(x, y));
}


void MainWindow::on_btnAddPoint_pressed()
{
    addPoint();
}


void MainWindow::on_spinBoxBorder_valueChanged(double arg1)
{
    ::border = (int) arg1;
}
