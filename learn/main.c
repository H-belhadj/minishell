#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int id = fork();
    int n;
    if(id == 0)
        n = 1;
    else 
        n = 6;
    if(id != 0)
    {
        int status;
        wait(&status);
    }
    int i = n;
    while(i < n + 5)
    {
        printf("%d ", i);
        fflush(stdout);
        i++;
    }
    if(id != 0)
        printf("\n");
    return (0);
}