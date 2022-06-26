#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    int *num=(int*)malloc(sizeof(int)*1);
    *num=1;
    printf("%d\n",*num);

    return 0;
}