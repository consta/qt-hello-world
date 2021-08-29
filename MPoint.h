//
// Created by Kanstantin Kachanouski on 28.08.21.
//

#ifndef HELLOWORLD_MPOINT_H
#define HELLOWORLD_MPOINT_H

#include <math.h>
#include <iostream>

class MPoint {
    static int _id;

private:
    int id = _id++;
    double x;
    double y;
    double speed;
    double direction;

public:
    MPoint();

    MPoint(double x, double y);

    void move();

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }
};


#endif //HELLOWORLD_MPOINT_H
