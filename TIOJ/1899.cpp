//#include "holiday.h"
#include "lib1899.h"
#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;

const int INF = 1<<29 ;
const int maxn = 100030 ;
int n ,s ,d ,w[maxn] ,Rank[maxn] ;
int f[maxn] ; LL v[maxn] ;

void Copy(int _n ,int _s ,int _d ,int _w[] ){
    n=_n ,s=_s ,d=_d ;
    for (int i=0 ;i<n ;i++ )w[i]=_w[i] ;
}

namespace SEG{
    struct Node { int sz ; LL sum ; }node[maxn*4] ;
    void init(){ memset(node,0,sizeof(node)) ; }
    void add (int cnt ,int pos ,int val ){
        int o=1 ,l=0 ,r=n-1 ;
        while (1){
            node[o].sz+=cnt ,node[o].sum+=cnt*val ;
            if (l>=r)break ;
            int m =(l+r)>>1 ;
            if (pos<=m) o=o<<1 ,r=m ;
            else o=o<<1|1 ,l=m+1 ;
        }
    }
    LL kth_sum(int k){
        LL re=0 ;
        int o=1 ;
        while (1){
            if (k<=0)break ;
            if (node[o].sz<=k){
                re+=node[o].sum ;
                break ;
            }
            if (node[o<<1].sz>=k)o=o<<1 ;
            else re+=node[o<<1].sum ,k-=node[o<<1].sz ,o=o<<1|1 ;
        }
        return re ;
    }
}

namespace Range{
    int L ,R ;
    void init(){
        L=R=s ;
        SEG::add(1,Rank[s],w[s]) ;
    }
    void set_range(int l ,int r ){
        while (R+1<=r)++R,SEG::add( 1,Rank[R],w[R]) ;
        while (R-1>=r)--R,SEG::add(-1,Rank[R+1],w[R+1]) ;
        while (L+1<=l)++L,SEG::add(-1,Rank[L-1],w[L-1]) ;
        while (L-1>=l)--L,SEG::add( 1,Rank[L],w[L]) ;
    }
}

void build_rank(){
    static vector< pair<int,int> > a ;
    a.resize(n) ;
    for (int i=0 ;i<n ;i++ ) a[i]=make_pair(w[i],i) ;
    sort(a.begin(),a.end(),greater< pair<int,int> >() ) ;
    for (int i=0 ;i<n ;i++ ) Rank[ a[i].second ]=i ;
}

int dis(int l ,int r ){
    if (l>r || l>s || r<s )return INF ;
    if (l==s)return r-s ;
    if (r==s)return s-l ;
    return min(r-s,s-l)+r-l ;
}

LL query(int l ,int r ){
    //if (l>r || l>s || r<s)return 0 ;
    Range::set_range(l,r) ;
    return SEG::kth_sum(d-dis(l,r)) ;
}

void find_f(int x ,int l ,int r){
    if (f[x]>=0)return ;
    v[x]=-1 ;
    for (int i=l ;i<=r ;i++ ){
        LL t = query(x,i) ;
        if (t>v[x])v[x]=t ,f[x]=i ;
    }
}

void solve(int l ,int r){
    if (l>=r)return ;
    int m=(l+r)>>1 ;
    find_f(m,f[l],f[r]) ,find_f(m+1,f[m],f[r]);
    solve(l,m) ;
    solve(m+1,r) ;
}

LL findMaxAttraction(int _n, int _s, int _d, int _w[]){
    Copy(_n,_s,_d,_w) ;
    build_rank() ;
    SEG::init() ;
    Range::init() ;
    memset(f,-1,sizeof(f)) ;
    find_f(0,s,n-1) ,find_f(s,s,n-1) ;
    solve(0,s) ;
    LL ans=0 ;
    for (int i=0 ;i<=s ;i++ ){
        ans = max(ans,v[i]) ;
    }
    return ans;
}
