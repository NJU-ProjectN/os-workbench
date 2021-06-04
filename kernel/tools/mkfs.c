#include <user.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
  int fd, size = atoi(argv[1]) << 20;
  uint8_t *disk;

  // TODO: argument parsing

  assert((fd = open(argv[2], O_RDWR)) > 0);
  assert((ftruncate(fd, size)) == 0);
  assert((disk = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) != (void *)-1);

  // TODO: mkfs

  munmap(disk, size);
  close(fd);
}

