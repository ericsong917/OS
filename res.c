#include<time.h>
#include<stdio.h>
int main(int argc, char**argv){
    struct timespec tp;
    clock_getres(CLOCK_PROCESS_CPUTIME_ID ,&tp);
    printf( "Seconds: %ld Nanos: %ld\n",tp.tv_sec, tp.tv_nsec );
}