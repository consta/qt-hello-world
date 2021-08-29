//
// Created by Kanstantin Kachanouski on 28.08.21.
//

#include "MPoint.h"

int MPoint::_id = 0;

MPoint::MPoint() {
    MPoint(0.5, 0.5);
}

MPoint::MPoint(double x, double y) {
    this->x = x;
    this->y = y;
    this->speed = 0.05 * ((double) rand() / RAND_MAX);
    this->direction = M_PI * 2 * ((double) rand() / RAND_MAX);
}

void MPoint::move() {
    double prevX = x;
    double prevY = y;
    x = prevX + (speed * cos(direction));
    if (x > 1.0 || x < 0) {
        if (direction > (M_PI)) {
            direction = (3.0 * M_PI) - direction;
        }
        else {
            direction = M_PI - direction;
        }
        x = prevX + (speed * cos(direction));
    }
    y = prevY + (speed * sin(direction));
    if (y > 1.0 || y < 0 ) {
        direction = 2.0 * M_PI - direction;
        y = prevY + (speed * sin(direction));
    }
}