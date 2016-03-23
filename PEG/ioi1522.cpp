#include<bits/stdc++.h>
using namespace std ;

const int maxn = 200030 ;
int n ,m ;
int a[maxn] ,c[maxn*4][2] ;
int b[maxn] ,pos[maxn] ;
int sw[maxn][2] ,sw_cnt ;

void set_b(int d){
    for (int i=0 ;i<n ;i++ ){
        b[i]=a[i] ;
    }
    for (int i=0 ;i<d ;i++ ){
        swap(b[ c[i][0] ],b[ c[i][1] ]) ;
    }
}

int count_circle(){
    int re=0 ;
    for (int i=0 ;i<n ;i++ )if (b[i]>=0){
        int u=i ,tmp ;
        re++ ;
        while (b[u]>=0){
            tmp=b[u] ;
            b[u]=-1 ;
            u=tmp ;
        }
    }
    return re ;
}

inline bool ok(int x){
    set_b(x) ;
    return n-count_circle()<=x ;
}

int find_R(){
    int l=0 ,r=n ;
    while (l!=r){
        int mid = (l+r)>>1 ;
        if (ok(mid))r=mid ;
        else l=mid+1 ;
    }
    return l ;
}

void solve(){
    //input -----------------
    scanf("%d",&n ) ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%d",&a[i] ) ;
    }
    scanf("%d",&m ) ;
    for (int i=0 ;i<m ;i++ ){
        scanf("%d%d",&c[i][0] ,&c[i][1] ) ;
    }
    //solve -----------------
    int R = find_R() ;
    set_b(R) ;
    for (int i=0 ;i<n ;i++ )pos[b[i]]=i ;
    sw_cnt=0 ;
    for (int i=0 ;i<n ;i++ )if (pos[i]!=i){
        int x = i , y = pos[i] ;
        sw[sw_cnt][0]=b[x] ,sw[sw_cnt][1]=b[y] ;
        swap(b[x],b[y]) ;
        swap(pos[ b[x] ],pos[ b[y] ]) ;
        sw_cnt++ ;
    }
    while (sw_cnt<R){
        sw[sw_cnt][0]=sw[sw_cnt][1]=0 ;
        sw_cnt++ ;
    }
    //translate -------------
    //b[i]=i ,pos[i]=i ;
    for (int i=R-1 ;i>=0 ;i-- ){
        sw[i][0] = pos[ sw[i][0] ] ;
        sw[i][1] = pos[ sw[i][1] ] ;
        int x = sw[i][0] ,y = sw[i][1] ;
        swap(b[x],b[y]) ;
        swap(pos[ b[x] ],pos[ b[y] ]) ;
        x = c[i][0] ,y = c[i][1] ;
        swap(b[x],b[y]) ;
        swap(pos[ b[x] ],pos[ b[y] ]) ;
    }

    //output ----------------
    printf("%d\n",R ) ;
    for (int i=0 ;i<R ;i++ ){
        if (sw[i][0]>sw[i][1])swap(sw[i][0],sw[i][1]) ;
        printf("%d %d\n",sw[i][0] ,sw[i][1] ) ;
    }
}

int main(){
    //int T ; scanf("%d",&T ) ; while (T--)
    solve() ;
}
