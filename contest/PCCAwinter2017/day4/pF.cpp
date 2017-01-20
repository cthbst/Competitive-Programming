#include <bits/stdc++.h>
using namespace std;

const int MAXN = 502;
const int INF = 1<<29;
int N, Q;
int D,U,L,R;
int x,y,val;

struct SEG1D{
    int mi, mx;
};

SEG1D better(const SEG1D &a, const SEG1D &b){
    SEG1D re;
    re.mi = min(a.mi,b.mi);
    re.mx = max(a.mx,b.mx);
    return re;
}

struct SEG2D{
    SEG1D E[MAXN*4];

    void build1D(int o, int l, int r){
        if (l==r){
            scanf("%d",&E[o].mi);
            E[o].mx=E[o].mi;
        }
        else {
            int mid = (l+r)>>1;
            build1D(o<<1,l,mid);
            build1D(o<<1|1,mid+1,r);
            E[o] = better(E[o<<1],E[o<<1|1]);
        }
    }
    SEG1D query1D(int o, int l, int r){
        if (L<=l && r<=R ){
            return E[o];
        }
        else if (r<L || R<l){
            return (SEG1D){INF,-INF};
        }
        else {
            int mid = (l+r)>>1;
            return  better( query1D(o<<1,l,mid),
                            query1D(o<<1|1,mid+1,r));
        }
    }
    void update1D(int o, int l, int r){
        if (x<=l && r<=x){
            E[o].mi=E[o].mx=val;
        }
        else if (r<x || x<l){
            return;
        }
        else {
            int mid = (l+r)>>1;
            update1D(o<<1,l,mid);
            update1D(o<<1|1,mid+1,r);
            E[o] = better(E[o<<1],E[o<<1|1]);
        }
    }
} S[MAXN*4];

void build2D(int o, int l, int r){
    if (l==r){
        S[o].build1D(1,0,N-1);
    }
    else {
        int mid = (l+r)>>1;
        build2D(o<<1,l,mid);
        build2D(o<<1|1,mid+1,r);
        for (int i=0; i<N*4; i++){
            S[o].E[i]=better(S[o<<1].E[i],S[o<<1|1].E[i]);
        }
    }
}


SEG1D query2D(int o, int l, int r){
    if (D<=l && r<=U){
        return S[o].query1D(1,0,N-1);
    }
    else if (r<D || U<l){
        return (SEG1D){INF,-INF};
    }
    else {
        int mid = (l+r)>>1;
        return better(  query2D(o<<1,l,mid),
                        query2D(o<<1|1,mid+1,r));
    }
}

int O;
void merge2D(int o, int l, int r){
    S[O].E[o] = better( S[O<<1].E[o],S[O<<1|1].E[o]);
    if (x<=l && r<=x){
        return;
    }
    else if (r<x || x<l){
        return;
    }
    else {
        int mid = (l+r)>>1;
        merge2D(o<<1,l,mid);
        merge2D(o<<1|1,mid+1,r);
    } 
}

void update2D(int o, int l, int r){
    if (y<=l && r<=y){
        S[o].update1D(1,0,N-1);
    }
    else if (r<y || y<l){
        return;
    }
    else {
        int mid = (l+r)>>1;
        update2D(o<<1,l,mid);
        update2D(o<<1|1,mid+1,r);
        O=o;
        merge2D(1,0,N-1); 
    }
}

int main(){
    scanf("%d",&N);
    build2D(1,0,N-1);

    scanf("%d",&Q);
    while (Q--){
        char cmd[10]; scanf("%s",cmd);

        if (cmd[0]=='q'){
            scanf("%d %d %d %d", &D, &L, &U, &R);
            D--,L--,U--,R--;

            SEG1D ans = query2D(1,0,N-1);
            printf("%d %d\n", ans.mx, ans.mi);
        }
        else {
            scanf("%d %d %d", &y, &x, &val);
            y--, x--;
            update2D(1,0,N-1);
        }
    }
}
