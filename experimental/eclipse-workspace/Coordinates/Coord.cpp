/*
 * Coord.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: Jeff
 */

#include "Coord.h"
#include <cstring>
#include <math.h>

// Private Functions
void Coord::_calc_mag() {
    double mag = 0;

    for(int i = 0; i < 3; i++)
        mag += pow(_coords[i], 2);

    _mag = pow(mag, 0.5);
}

// Public Constructors
Coord::Coord() {
    double coords[3] = {0};
    memcpy(_coords, coords, sizeof(_coords));
    _calc_mag();
}
Coord::Coord(double x1, double x2, double x3) {
    double coords[3] = {x1, x2, x3};
    memcpy(_coords, coords, sizeof(_coords));
    _calc_mag();
}
Coord::Coord(double *x) {
    memcpy(_coords, x, sizeof(_coords));
    _calc_mag();
}

Coord::Coord(const Coord &other) {
    memcpy(_coords, other._coords, sizeof(_coords));
    _calc_mag();
}

Coord::Coord(Coord &&other) {
    memcpy(_coords, other._coords, sizeof(_coords));
    _calc_mag();
}

Coord& Coord::operator=(const Coord &other) {
    //memcpy(_coords, other._coords, sizeof(_coords));
    return *this;
}

Coord& Coord::operator=(Coord &&other) {
    //memcpy(_coords, other._coords, sizeof(_coords));
    return *this;
}

// Public Functions

double Coord::get(int n) {
    return _coords[n];
}


void Coord::get(double *target) {
    memcpy(target, _coords, sizeof(_coords));
}

void Coord::set(int n, double value) {
    _coords[n] = value;
    _calc_mag();
}

void Coord::set(double *value) {
    memcpy(_coords, value, sizeof(_coords));
    _calc_mag();
}

double Coord::getMag() {
    return _mag;
}

double Coord::getUnit(int n) {
    return _coords[n] / _mag;
}

void Coord::getUnit(double *target) {
    double coords[3];

    for(int i = 0; i < 3; i++)
        coords[i] = _coords[i] / _mag;

    memcpy(target, _coords, sizeof(_coords));
}

Coord Coord::getUnit() {
    double coords[3];
    getUnit(coords);
    return Coord(coords);
}

Coord operator*(const Coord c, const double d) {
    double coords[3];

    for(int i = 0; i < 3; i++)
        coords[i] = c._coords[i] * d;

    return Coord(coords);
}

Coord operator*(const double d, const Coord c) {
    return c * d;
}

Coord operator/(const Coord c, const double d) {
    double coords[3];

    for(int i = 0; i < 3; i++)
        coords[i] = c._coords[i] / d;

    return Coord(coords);
}

