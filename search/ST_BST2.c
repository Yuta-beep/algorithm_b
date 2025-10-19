#include<stdio.h>
#include <stdlib.h>
#include "Item.h"
typedef struct STnode* link;
struct STnode { Item item; link l, r; int N; };
static link head, z;

link NEW(Item item, link l, link r, int N)

{ link x = malloc(sizeof *x); 
  x->item = item; x->l = l; x->r = r; x->N = N;
  return x;
}
void STinit()
{ head = (z = NEW(NULLitem, 0, 0, 0)); }

int STcount(void) { return head->N; }

Item searchR(link h, Key v)
{ Key t = key(h->item);
  if (h == z) return NULLitem;
  if eq(v, t) return h->item;
  if less(v, t) return searchR(h->l, v);
  else return searchR(h->r, v);
}

Item STsearch(Key v) 
{ return searchR(head, v); } 

link rotR(link h)
{ link x = h->l; h->l = x->r; x->r = h; 
  return x; }

link rotL(link h)
{ link x = h->r; h->r = x->l; x->l = h; 
  return x; }

link insertT(link h, Item item)
{ Key v = key(item);
  if (h == z) return NEW(item, z, z, 1); 
  if (less(v, key(h->item))) 
    { h->l = insertT(h->l, item); h = rotR(h); }
  else
    { h->r = insertT(h->r, item); h = rotL(h); }
  return h;
}

void STinsert(Item item)
{ head = insertT(head, item); }

void sortR(link h, void (*visit)(Item))
{ 
  if (h == z) return;
  sortR(h->l, visit);
  visit(h->item); 
  sortR(h->r, visit);
}

int STcountNode(link h){
  int ct=1; //自身のノードは含めるので1からカウント
  if(h==z) return 0;
  if(h->r!=NULL){
    ct+=STcountNode(h->r);
  }
  if(h->l!=NULL){
    ct+=STcountNode(h->l);
  }
  return ct;
}

void STsort(void (*visit)(Item))
{ sortR(head, visit); } 

void STshow(link h, int l){
  int i=0;
  if(h != NULL){
    STshow(h->r, l+1);
    for(i=0; i<l; i++) printf("\t");
    printf("(%d,%d)\n",key(h->item), STcountNode(h));
    STshow(h->l, l+1);
  }
}

void STshowAll(){ STshow(head, 0); }

// スプレイ木のスプレー操作：アクセスしたノードを根まで移動
link splay (link h, Item item) {
	Key v = key (item);
	
	// 空の木の場合、新しいノードを作成
	if (h == z) return NEW (item, z, z, 1);
	
	// 左部分木に挿入する場合
	if (less (v, key (h->item))) {
		// 左の子が空の場合、新しいノードを挿入
    	if (h->l == z) return NEW (item, z, h, h->N + 1);
    	
    	// 左の左部分木に再帰的にスプレイ（zig-zig操作）
    	if (less (v, key (h->l->item))) {
	  		h->l->l = splay (h->l->l, item);
	  		h = rotR (h);  // 右回転
		} else {
			// 左の右部分木に再帰的にスプレイ（zig-zag操作）
	  		h->l->r = splay (h->l->r, item);
	  		h->l = rotL (h->l);  // 左回転
		}
    	return rotR (h);  // 最終的な右回転
	} else {
		// 右部分木に挿入する場合
		// 右の子が空の場合、新しいノードを挿入
    	if (h->r == z) return NEW (item, h, z, h->N + 1);
    	
    	// 右の右部分木に再帰的にスプレイ（zig-zig操作）
    	if (less (key (h->r->item), v)) {
			h->r->r = splay (h->r->r, item);
	  		h = rotL (h);  // 左回転
		} else {
			// 右の左部分木に再帰的にスプレイ（zig-zag操作）
	  		h->r->l = splay (h->r->l, item);
	  		h->r = rotR (h->r);  // 右回転
		}
		return rotL (h);  // 最終的な左回転
    }
}

// スプレイ木への挿入：スプレイ操作でアクセスしたノードを根に移動
void STsplayInsert (Item item) {
	head = splay (head, item);
}

// ランダム化二分探索木への挿入：確率的に根に挿入
link insertR (link h, Item item) {
  Key v = key (item), t = key (h->item);

  // 空の木の場合、新しいノードを作成
  if (h == z) return NEW (item, z, z, 1);
  
  // 確率 1/(N+1) で根に挿入（ランダム化の核心）
  if (rand () < RAND_MAX / (h->N + 1)) return insertT (h, item);
  
  // 通常の二分探索木挿入：値の大小に応じて左右に再帰
  if (less(v, t)) h->l = insertR (h->l, item);
  else h->r = insertR (h->r, item);
  
  // ノード数を更新
  (h->N)++;
  return h;
}

// ランダム化二分探索木への挿入のエントリーポイント
void STinsertR (Item item) {
  head = insertR (head, item);
}




