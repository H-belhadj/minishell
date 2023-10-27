#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
  int fd1, fd2;
  char c;

  fd1 = open("foobar.txt", O_RDONLY);
  fd2 = open("foobar.txt", O_RDONLY);
  // c becomes f
  read(fd2, &c, 1);
  // c becomes o
  read(fd2, &c, 1);
  // c becomes o
  read(fd2, &c, 1);
  // c becomes b
  read(fd2, &c, 1);
  printf("c = %c\n", c); // c = b

  // now reading in fd1, so c becomes f again
  read(fd1, &c, 1);
  printf("c = %c\n", c); // c = f

  // redirect and now fd2 is now back at f
  dup2(fd1, fd2);
  // reading back fd2 which has been redirected,
  // so c actually becomes o!
  read(fd2, &c, 1);
  printf("c = %c\n", c); // c = 0
  exit(0);
}