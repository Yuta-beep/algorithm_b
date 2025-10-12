#include<stdio.h>
#include<stdlib.h>
#include "Data.h"

Data NULLdata={-1,"NULL"};

Key DATArand(void) {
    return rand()%100000;
}
int DATAscan(Key *x){
    return scanf("%d", x);
}
void DATAshow(Data x){
    printf("%3d\n", key(x));
}