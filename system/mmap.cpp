#include <iostream>
#include <unistd.h>
#include <fcntl.h>     // open
#include <stdlib.h>    // exit
#include <stdio.h>     // perror
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>

int main() {

  int ch='\0';
  int fd = open("foo.txt", O_CREAT | O_EXCL, 0666);
  if (fd == -1) {
    perror("file exists");
    exit(-1);
  }

  for (int i = 0; i < 1024; i++) 
    write(fd, &ch, 1);

  caddr_t memP = (char *) mmap(0, 
  /* 0: the kernel assigns a vaddr to map, 
   * or a multiple of the memory page size (getpagesize) */
                      1024,
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED, fd, 0);

  if (memP == MAP_FAILED) {
   perror("mmap");
    exit(-1);
  }
  close(fd);
  //ostrstream(memP, 1024) << "Hello Unix\n";
  const char *s = "Hello Unix\n";
  memcpy(memP, s, strlen(s));
}



