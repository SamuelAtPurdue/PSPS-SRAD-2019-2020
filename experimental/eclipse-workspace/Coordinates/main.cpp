#include <stdio.h>
#include "Coord.h"

int main() {

    Coord c1 = Coord(1,2,4);
    printf("%lf\n",c1.get(1));

    double d[3];
    Coord c2 = 4 * c1;
    c2.get(d);


    printf("%lf", d[2]);
    return 0;
}
