#include "lib1895.h"
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 2000000 ;
const int INF = 1<<29 ;

int h[maxn] ;

struct SEG{
    int low ,upp ;
}O{0,INF},seg[4194400];

int big = 0 ;
void build(int o ,int l ,int r ){
    big = max(o,big) ;
    seg[o]=O ;
    if (l==r)return ;
    int m = (l+r)>>1 ;
    build(o<<1,l,m) ;
    build(o<<1|1,m+1,r) ;
}
inline void push(int o ,int l ,int r ){
    //printf("push(%d,%d,%d) %d %d \n",o ,l ,r ,seg[o].low ,seg[o].upp) ;
    if (l==r){
        if (h[l]<seg[o].low)h[l]=seg[o].low ;
        else if (h[l]>seg[o].upp)h[l]=seg[o].upp ;
    }
    else {
        if (seg[o<<1].low<seg[o].low)seg[o<<1].low=seg[o].low ;
        else if (seg[o<<1].low>seg[o].upp)seg[o<<1].low=seg[o].upp ;
        if (seg[o<<1].upp<seg[o].low)seg[o<<1].upp=seg[o].low ;
        else if (seg[o<<1].upp>seg[o].upp)seg[o<<1].upp=seg[o].upp ;
        if (seg[o<<1|1].low<seg[o].low)seg[o<<1|1].low=seg[o].low ;
        else if (seg[o<<1|1].low>seg[o].upp)seg[o<<1|1].low=seg[o].upp ;
        if (seg[o<<1|1].upp<seg[o].low)seg[o<<1|1].upp=seg[o].low ;
        else if (seg[o<<1|1].upp>seg[o].upp)seg[o<<1|1].upp=seg[o].upp ;
    }
    seg[o] = O ;
}
int cmd ,L ,R ,H ;
void add(int o ,int l ,int r ){
    push(o,l,r) ;
    if (L<=l && r<=R ){
        if (cmd==1)seg[o].low=H ;
        else seg[o].upp=H ;
        //printf("()        add(%d,%d,%d) %d %d\n",o ,l ,r ,seg[o].low ,seg[o].upp ) ;
        return ;
    }
    if (l!=r){
        int m = (l+r)>>1 ;
        if (L<=m)add(o<<1,l,m) ;
        if (m< R)add(o<<1|1,m+1,r) ;
    }
}

void output(int o ,int l ,int r ){
    push(o,l,r) ;
    if (l==r)return ;
    int m = (l+r)>>1 ;
    output(o<<1,l,m) ;
    output(o<<1|1,m+1,r) ;
}

void buildWall (int n ,int k ,int op[] ,int left[] ,int right[] ,int height[] ,int finalHeight[]){
    build(1,0,n-1) ;
    memset(h,0,sizeof(int)*n) ;
    for (int i=0 ;i<k ;i++ ){
        cmd = op[i] ;
        L = left[i] ,R = right[i] ;
        H = height[i] ;
        add(1,0,n-1) ;
    }
    output(1,0,n-1) ;
    for (int i=0 ;i<n ;i++ )finalHeight[i]=h[i] ;
}

/*
10 1 1 1 8 5


10 6
1 1 8 4
2 4 9 1
2 3 6 5
1 0 5 3
1 2 2 5
2 6 7 0

0 1 2 3 4 5 6 7 8 9
0 0 0 0 0 0 0 0 0 0
0 4 4 4 4 4 4 4 4 0 /1 1 8 4
0 4 4 4 1 1 1 1 1 0 /2 4 9 1
0 4 4 4 1 1 1 1 1 0 /2 3 6 5
3 4 4 4 3 3 1 1 1 0 /1 0 5 3
3 4 5 4 3 3 1 1 1 0 /1 2 2 5
3 4 5 4 1 1 0 0 1 0 /2 6 7 0

ans:
3 4 5 4 3 3 0 0 1 0
*/
