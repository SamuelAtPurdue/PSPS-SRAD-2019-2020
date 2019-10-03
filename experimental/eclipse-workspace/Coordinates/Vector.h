/*
 * Vector.h
 *
 *  Created on: Oct 2, 2019
 *      Author: Jeff
 */

#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
private:
    double _coords[3];
    double _mag;

    void _calc_mag();

public:
    Vector();
    Vector(double x1, double x2, double x3);
    Vector(double *x);
    Vector(const Vector &other);
    Vector(Vector &&other);
    Vector& operator=(const Vector &other);
    Vector& operator=(Vector &&other);

    double get(int n);
    void get(double *target);

    void set(int n, double value);
    void set(double *value);

    double getMag();

    double getUnit(int n);
    void getUnit(double *target);
    Vector getUnit();

    friend Vector operator+(const Vector v1, const Vector v2);
    friend Vector operator*(const Vector v, const double d);
    friend Vector operator/(const Vector v, const double d);

    friend double dot(const Vector v1, const Vector v2);
};


Vector operator+(const Vector v1, const Vector v2);
Vector operator-(const Vector v1, const Vector v2);
Vector operator*(const Vector v, const double d);
Vector operator*(const double d, const Vector v);
Vector operator/(const Vector v, const double d);

double dot(const Vector v1, const Vector v2);
double angle(Vector v1, Vector v2);
double angleD(Vector v1, Vector v2);


#endif /* VECTOR_H_ */
