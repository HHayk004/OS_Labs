#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s rect_side1 rect_side2 tri_base tri_height\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if ((int)pid == 0) {
    	int ret = execl("./triangle", "triangle", argv[3], argv[4], (char*)NULL);
    
    	if (ret) {
	  fprintf(stderr, "Execl Triangle Failed:\n");
	  return 1;
	}
    } else if ((int)pid == -1) {
    	fprintf(stderr, "Triangle Fork Failed:\n");
	return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    
    double rect_area = a * b;
    printf("Rectangle area = %.2f:\n", rect_area);

    pid_t pid1 = fork();

    if ((int)pid1 == 0) {
    	int ret = execl("./circle", "circle", argv[5], (char*)NULL);

	if (ret) {
	  fprintf(stderr, "Execl Circle Failed:\n");
	  return 1;
	}
    } else if ((int)pid1 == -1) {
    	fprintf(stderr, "Circle Fork Failed:\n");
	return 1;
    }

    return 0;
}
