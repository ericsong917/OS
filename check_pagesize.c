#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>   
#include <unistd.h> 
int main(){
    long PAGESIZE = sysconf(_SC_PAGESIZE);
    printf("%d",PAGESIZE);
}