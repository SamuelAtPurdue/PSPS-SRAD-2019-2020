#include <stdio.h>

#include "Vector.h"

int main() {

    Vector c1 = Vector(1,0,0);
    Vector c2 = Vector(1,1,0);


    printf("%f", angleD(c1,c2));
    return 0;
}
