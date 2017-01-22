#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005;
int N, Q, K, a[MAXN];
char name[MAXN][202];
int ans[MAXN], ca;
pair<int,int> querys[MAXN];

int SEG[MAXN*4];

void build(int o=1, int l=1, int r=N){
    if (l==r){
        SEG[o]=l;
    }
    else {
        int mid = (l+r)>>1;

        build(o<<1,l,mid);
        build(o<<1|1,mid+1,r);

        if (a[SEG[o<<1]]>=a[SEG[o<<1|1]]){
            SEG[o]=SEG[o<<1];
        }
        else {
            SEG[o]=SEG[o<<1|1];
        }
    }
}

int L, R;
int query(int o, int l, int r){
    if (L<=l && r<=R){
        return SEG[o];
    }
    else if (r<L || R<l){
        return -1;
    }
    else {
        int mid = (l+r)>>1;
        int ql = query(o<<1,l,mid);
        int qr = query(o<<1|1,mid+1,r);

        if (ql==-1)return qr;
        else if (qr==-1)return ql;
        else if (a[ql]>=a[qr])return ql;
        else return qr;
    }
}

void update(int o, int l, int r, int pos){
    if (r<pos || pos<l || l==r)return;
    
    int mid = (l+r)>>1;
    update(o<<1,l,mid,pos);
    update(o<<1|1,mid+1,r,pos);
    
    if (a[SEG[o<<1]]>=a[SEG[o<<1|1]]){
        SEG[o]=SEG[o<<1];
    }
    else {
        SEG[o]=SEG[o<<1|1];
    }
}


void input(){
    scanf("%d %d %d", &N, &Q, &K);

    for (int i=1; i<=N; i++){
        scanf("%s%d", name[i], &a[i]);
    }
    build();
    
    ca=0;
    querys[0]=pair<int,int>(N,N);
    for (int i=1; i<=Q; i++){
        scanf("%d %d", &querys[i].first, &querys[i].second);
    }
}

void Querys(){
    sort(querys,querys+Q+1);
    for (int i=0; i<=Q; i++){
        L=1, R=querys[i].first;
        int cnt = querys[i].second;
        while (cnt--){
            int q = query(1,1,N);
            if (a[q]>0)ans[++ca]=q;
            else break;
            a[q]=-1;
            update(1,1,N,q);
        }
    }
}

int main(){
    int T; scanf("%d", &T);

    while (T--){
        input();
        Querys();

        for (int i=0, ki; i<K; i++){
            scanf("%d",&ki);
            printf("%s",name[ ans[ki] ]);
            if (i!=K-1)printf(" ");
            else puts("");
        }
    }
}
