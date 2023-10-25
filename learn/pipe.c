#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char **argv) {
    int arr[] = {4, 1, 2, 4, 2, 2};
    int arrsize = sizeof(arr) / sizeof(int);
    int start;
    int end;
    int fd[2];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    int id = fork();

    if (id == -1)
    {
        perror("fork");
        return 2;
    }

    if (id == 0)
    {
        start = 0;
        end = arrsize / 2;
    }
    else
    {
        start = arrsize / 2;
        end = arrsize;
    }

    int sum = 0;
    int i;

    for (i = start; i < end; i++)
        sum += arr[i];

    printf("Calculate partial sum: %d\n", sum);

    if (id == 0)
    {
        close(fd[0]);  // Close the read end of the pipe.
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);  // Close the write end of the pipe.
    }
    else
    {
        int sumfromchild;
        close(fd[1]);  // Close the write end of the pipe.
        read(fd[0], &sumfromchild, sizeof(sumfromchild));
        close(fd[0]);  // Close the read end of the pipe.

        int totalsum = sum + sumfromchild;
        printf("Total sum is %d\n", totalsum);
        wait(NULL);
    }
    return 0;
}