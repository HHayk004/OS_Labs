#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s base height\n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    double height = atof(argv[2]);
    double tri_area = 0.5 * base * height;

    printf("Triangle area = %.2f:\n", tri_area);

    return 0;
}
