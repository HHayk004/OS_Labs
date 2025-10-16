#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#define _USE_MATH_DEFINES

int main(int argc, char** argv) {
     if (argc != 2) {
     	fprintf(stderr, "Wrong Argumets Count In Circle Script:\n");
	return 1;
     }

     double r = atof(argv[1]);

     printf("Circle Area = %.2f:\n", M_PI * r * r);

     return 0;
}
