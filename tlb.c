#include <stdio.h>  // printf, fprintf
#include <stdlib.h> // exit, calloc, free
#include <time.h>   // clock_gettime
#include <unistd.h> // sysconf

#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s pages trials\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  FILE * file=fopen("plot.txt","w+");
  long PAGESIZE = sysconf(_SC_PAGESIZE); // 4096
  long jump = PAGESIZE / sizeof(int);    // 1024
  int pages ;
  int trials = 10000;
  if (pages <= 0 || trials <= 0) {
    fprintf(stderr, "Invalid input\n");
    exit(EXIT_FAILURE);
  }
  struct timespec start, end;
  if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start) == -1)
    handle_error("clock_gettime");
  for(pages=1;pages<=8192;pages*=2){
     int *a = calloc(pages, PAGESIZE);
     for (int j = 0; j < trials; j++) {
      for (int i = 0; i < pages * jump; i += jump)
      a[i] += 1;
  }

      if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end) == -1)
        handle_error("clock_gettime");

  // nanoseconds
      fprintf(file,"%d %f\n",pages,
         ((end.tv_sec - start.tv_sec) * 1E9 + end.tv_nsec - start.tv_nsec) /
             (trials * pages));
      free(a);
  }
  fclose(file);
  return 0;
}