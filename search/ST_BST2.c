#include<stdio.h>
#include<stdlib.h>
#include "Data.h"
typedef struct STnode* link;

struct STnode {Data data; link l,r; int N};
static link head, z;
link NEW(Data data, link l, link r, int N) {
    link x=malloc(sizeof *x);
    x->data=data; x->l=l; x->r=r; x->N=N;
    return x;
}

link rotR(link h){
    link x=h->l; h->l=x->r; x->r=h;
    return x;
}

link rotL(link h){
    link x=h->r; h->r=x->l; x->l=h;
    return x;
}

void STinit() {//初期化関数
    head=(z=NEW(Nulldata, 0, 0, 0));
}

int STcount(void) {
    return head->N;
}

Data searchR(link h, Key v) {//探索関数
    Key t=key(h->data);
    if(h==z) return NULLdata;
    if eq(v,t) return h->data;
    if less(v,t){
        return searchR(h->l,v);
    } else {
        return searchR(h->r,v);
    }
}

link insertT(link h, Data data) {//挿入関数
    Key v=key(data);
    if(h==z) return NEW(data, z,z,1);
    if(less(v,key(h->data))) {
        h->l=insertT(h->l,data); h=rotR(h);
    } else {
        h->r=insertT(h->r,data); h=rotL(h);
    }
    return h;
}

void STinsert(Data data) {
    head=insertT(head, data);
}

void sortR(link h, void (*visit)(Data)) {
    if(h==z) return;
    sortR(h->l, visit);
    visit(h->data);
    sortR(h->r,visit);
}

void STsort(void (*visit)(Data)) {
    sortR(head, visit);
}