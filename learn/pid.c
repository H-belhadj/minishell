#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int id = fork();
    printf("Current id :%d, parent id: %d\n", getpid(), getppid());
    return(0);
}