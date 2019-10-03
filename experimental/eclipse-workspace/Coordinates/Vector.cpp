/*
 * Vector.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: Jeff
 */
#define _USE_MATH_DEFINES

#include "Vector.h"
#include <cstring>
#include <math.h>

// Private Functions
void Vector::_calc_mag() {
    double mag = 0;

    for(int i = 0; i < 3; i++)
        mag += pow(_coords[i], 2);

    _mag = pow(mag, 0.5);
}

// Public Constructors
Vector::Vector() {
    double coords[3] = {0};
    memcpy(_coords, coords, sizeof(_coords));
    _calc_mag();
}
Vector::Vector(double x1, double x2, double x3) {
    double coords[3] = {x1, x2, x3};
    memcpy(_coords, coords, sizeof(_coords));
    _calc_mag();
}
Vector::Vector(double *x) {
    memcpy(_coords, x, sizeof(_coords));
    _calc_mag();
}

Vector::Vector(const Vector &other) {
    memcpy(_coords, other._coords, sizeof(_coords));
    _calc_mag();
}

Vector::Vector(Vector &&other) {
    memcpy(_coords, other._coords, sizeof(_coords));
    _calc_mag();
}

Vector& Vector::operator=(const Vector &other) {
    //memcpy(_coords, other._coords, sizeof(_coords));
    return *this;
}

Vector& Vector::operator=(Vector &&other) {
    //memcpy(_coords, other._coords, sizeof(_coords));
    return *this;
}

// Public Functions

double Vector::get(int n) {
    return _coords[n];
}


void Vector::get(double *target) {
    memcpy(target, _coords, sizeof(_coords));
}

void Vector::set(int n, double value) {
    _coords[n] = value;
    _calc_mag();
}

void Vector::set(double *value) {
    memcpy(_coords, value, sizeof(_coords));
    _calc_mag();
}

double Vector::getMag() {
    return _mag;
}

double Vector::getUnit(int n) {
    return _coords[n] / _mag;
}

void Vector::getUnit(double *target) {
    double coords[3];

    for(int i = 0; i < 3; i++)
        coords[i] = _coords[i] / _mag;

    memcpy(target, coords, sizeof(_coords));
}

Vector Vector::getUnit() {
    double coords[3];
    getUnit(coords);
    return Vector(coords);
}

Vector operator+(const Vector v1, const Vector v2) {
    double coords[3];

    for(int i = 0; i < 3; i++)
        coords[i] = v1._coords[i] + v2._coords[i];

    return Vector(coords);
}

Vector operator-(const Vector v1, const Vector v2) {
    return v1 + (-1 * v2);
}

Vector operator*(const Vector v, const double d) {
    double coords[3];

    for(int i = 0; i < 3; i++)
        coords[i] = v._coords[i] * d;

    return Vector(coords);
}

Vector operator*(const double d, const Vector v) {
    return v * d;
}

Vector operator/(const Vector v, const double d) {
    double coords[3];

    for(int i = 0; i < 3; i++)
        coords[i] = v._coords[i] / d;

    return Vector(coords);
}


double dot(Vector v1, Vector v2) {
    double result = 0;

    for(int i = 0; i < 3; i++)
        result += v1._coords[i] * v2._coords[i];

    return result;
}

double angle(Vector v1, Vector v2) {
    return acos(dot(v1,v2) / (v1.getMag() * v2.getMag()));
}

double angleD(Vector v1, Vector v2) {
    return angle(v1, v2) * 180 / M_PI;
}
