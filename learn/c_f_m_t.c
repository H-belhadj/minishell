#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

//calling fork multiple times

int main(int argc, char **argv)
{
    int id1 = fork();
    int id2 = fork();
    int i = 0;
    while(i < 10)
    {
        fork();
        i++;
    }
    if(id1 == 0)
    {
        if(id2 == 0)
            printf("We Are Process Y\n");
        else
            printf("We Are Process X\n");
    }
    else
    {
        if(id2 == 0)
            printf("We Are Process Z\n");
        else
            printf("We Are The Parent Process!\n");
    }
    while(wait(NULL) == -1 || errno != ECHILD)
    {
        printf("Waited for a child to finish\n");
    }
    return (0);
}