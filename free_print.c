#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    int *arr=(int*)malloc(sizeof(int)*10);
    for(int i=0;i<10;i++){
        arr[i]=i;
    }
    free(arr);
    printf("%d\n",arr[5]);
    }