#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    printf("PID = %d\n", pid);
    int number1 = 0;
    int number2 = 1;
    int number3 = 2;
    scanf("%d", &number1);
    printf("Your number: %d\n", number1);
    return 0;
}
