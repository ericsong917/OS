#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *array;
    int used;
    int size;
}d_arr;

void init(d_arr *arr,int i_size ){
    arr->array=malloc(i_size * sizeof(int));
    arr->used=0;
    arr->size=i_size;
}
void insert(d_arr *arr,int num){
    if(arr->used==arr->size){
        arr->size *=2;
        arr->array=realloc(arr->array,arr->size * sizeof(int));
    }
    arr->array[arr->used++]=num;
}
void freearr(d_arr *arr){
    free(arr->array);
    arr->array=NULL;
    arr->used=0;
    arr->size=0;
}

int main(int argc, char* argv[]){
    d_arr arr;
    init(&arr,10);
    for(int i=0;i<100;i++){
        insert(&arr,i);
    }
    for(int i=0;i<100;i++){
        printf("%d ",arr.array[i]);
    }
    freearr(&arr);
}
