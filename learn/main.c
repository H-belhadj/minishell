#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int id = fork();
    if(id != 0)
        fork();
    printf("Hello World\n");
    // if(id == 0)
    //     printf("Hello From The Child Process\n");
    // else
    //     printf("Hello From The Main Process\n"); 
    return (0);
}