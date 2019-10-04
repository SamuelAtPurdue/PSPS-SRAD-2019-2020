#include <stdio.h>

#include "Vector.h"

void printv(Vector v) {
    printf("%f\t%f\t%f\n", v.get(0),v.get(1),v.get(2));
}

int main() {

    Vector c1 = Vector(1,23,1);

    Vector c2 = c1;
    Vector c3 = c2 * 4;

    printv(c1);
    printv(c2);
    printv(c3);

    printf("%f\n", angleD(c1,c3));


    return 0;
}
