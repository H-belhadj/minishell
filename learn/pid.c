#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int id = fork();
    if(id == 0)
        sleep(1);
    printf("Current id :%d, parent id: %d\n", getpid(), getppid());
    int res = wait(NULL);
    if(res == - 1)
        printf("No Children To Wait For\n");
    else
        printf("%d Fished execution\n", res);
    return(0);
}