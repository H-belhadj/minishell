#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(int argc, char **argv)
{
    int p1[2];
    if (pipe(p1) == -1) {
        perror("pipe");
        return 1;
    }

    int pid = fork();
    if (pid == -1) {
        perror("fork");
        return 2;
    }

    if (pid == 0) {
        // Child process
        int x;
        if (read(p1[0], &x, sizeof(x)) == -1) {
            perror("read");
            return 3;
        }
        printf("Received %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1) {
            perror("write");
            return 4;
        }
        printf("Wrote %d\n", x);
    } else {
        // Parent process
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p1[1], &y, sizeof(y)) == -1) {
            perror("write");
            return 5;
        }
        printf("Wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1) {
            perror("read");
            return 6;
        }
        printf("Received %d\n", y);
        wait(NULL);
    }

    close(p1[0]);
    close(p1[1]);
    return 0;
}
