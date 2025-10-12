#include<stdio.h>
#include<stdlib.h>
#include "Data.h"
#include "ST.h"

int main(int argc, char *argv[]){
    int N, M, maxN=atoi(argv[1]), sw=atoi(argv[2]);
    Key v; Data data;
    STinit(maxN); srand(1);
    for(M=0;N=0;N<maxN;N++) {
        if(sw==1) v=DATArand(); //乱数生成
        else if (sw==2) v=N+1; //1から順に生成
        else if (DATAscan(&v)==EOF) break; //keyboard読み込み
        data =STsearch(v); if(data.key!=NULLdata.key) continue;
        key(data)=v;
        STinsert(data); M++;
    }

    STsort(DATAshow); printf("\n");
    printf("%d keys ", N);
    printf("%d distinct keys\n", STcount());
    return 0;
}