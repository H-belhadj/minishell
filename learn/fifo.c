#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if(mkfifo("myfifo1", 0777) == -1)
    {
        if(errno != EEXIST)
        {
            printf("Could Not Create Fifo File\n");
            return(1);
        }
    }
    // usleep(300);
    printf("opening....\n");
    int fd = open("myfifo1", O_RDWR);
    if(fd == -1)
        return(3);
    // usleep(3000);
    printf("Opened\n");
    int x = 97;
    if(write(fd, &x, sizeof(x)) == -1)
    {
        return (2);
    }
    // usleep(3000);
    printf("write\n");
    close(fd);
    // usleep(3000);
    printf("closed\n");
    return (0);
}