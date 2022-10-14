#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int my_cat(char *file) {

  char buf[30000];
  int fd;
  char c;
  size_t nbytes;
  ssize_t bytes_read;
  nbytes = sizeof(buf);
  int rd;

  if (file != NULL) {
    fd = open(file, O_RDONLY, 755);
    if (!fd) {
      write(2, "erreur", 7);
      exit(1);
    }
    while ((rd = read(fd, &c, nbytes)))
      write(1, &c, rd);
  } else {
    while (read(0, &c, 1))
      write(1, &c, 1);
  }

  return (0);
}

int main(int argc, char **argv) {

  char *option;
  char *file;
  option = argv[1];
  file = argv[2];
  my_cat(argv[1]);
  return 0;
}