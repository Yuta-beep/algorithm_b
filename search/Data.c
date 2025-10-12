#include<stdio.h>
#include<stdlib.h>
#include "Data.h"

Data Nulldata = {-1, "NULL"};

Key DATArand(void){return rand()%100000;}
int DATAscan(Key *){return scanf("%d", x);}
void DATAshow(Data x){printf("%d, key(x)");}