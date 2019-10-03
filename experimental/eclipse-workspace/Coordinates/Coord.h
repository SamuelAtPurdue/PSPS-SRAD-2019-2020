/*
 * Coord.h
 *
 *  Created on: Oct 2, 2019
 *      Author: Jeff
 */

#ifndef COORD_H_
#define COORD_H_

class Coord {
private:
    double _coords[3];
    double _mag;

    void _calc_mag();

public:
    Coord();
    Coord(double x1, double x2, double x3);
    Coord(double *x);
    Coord(const Coord &other);
    Coord(Coord &&other);
    Coord& operator=(const Coord &other);
    Coord& operator=(Coord &&other);

    double get(int n);
    void get(double *target);

    void set(int n, double value);
    void set(double *value);

    double getMag();

    double getUnit(int n);
    void getUnit(double *target);
    Coord getUnit();

    friend Coord operator*(const Coord c, const double d);
    friend Coord operator/(const Coord c, const double d);
};

Coord operator*(const Coord c, const double d);
Coord operator*(const double d, const Coord c);
Coord operator/(const Coord c, const double d);


#endif /* COORD_H_ */
