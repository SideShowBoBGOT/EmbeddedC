#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc_z_one(double alpha);
double calc_z_two(double alpha);

int main() {
    char buf[255] = {0};

    printf("Enter alpha: ");
    fgets(buf, sizeof(buf), stdin);

    double alpha = strtod(buf, NULL);

    printf("z_1: %lf\n", calc_z_one(alpha));
    printf("z_2: %lf\n", calc_z_two(alpha));

    return 0;
}

double calc_z_one(double alpha) {
    double z_one = 2;
    z_one *= pow(sin(3 * M_PI - 2 * alpha), 2);
    z_one *= pow(cos(5 * M_PI + 2 * alpha), 2);
    return z_one;
}

double calc_z_two(double alpha) {
    double z_two = 0.25;
    z_two -= 0.25 * sin(2.5 * M_PI - 8 * alpha);
    return z_two;
}
