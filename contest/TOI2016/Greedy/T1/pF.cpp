#include<bits/stdc++.h>
using namespace std ;

int n ,d ,mx;
vector<int> a ;
priority_queue<int,vector<int>,greater<int> > que ;

int check(int m){
    while (!que.empty())que.pop() ;
    for (int i=0 ;i<m ;i++ )que.push(0) ;
    long long ans=0 ,ai ;
    for (int i=0 ;i<n ;i++ ){
        ai = a[i] ;
        ai+=que.top() ; que.pop() ;
        que.push(ai) ;
        ans=max(ans,ai) ;
    }
    return ans ;
}

void solve(){
    scanf("%d%d",&n ,&d ) ;
    a.resize(n) ;
    mx=0 ;
    for (int &e:a)scanf("%d",&e ) ,mx=max(mx,e);
    if (mx>d){
        puts("-1") ;
        return ;
    }
    int l=1 ,r=n ;
    while (l!=r){
        int m=(l+r)>>1 ;
        if (check(m)>d)l=m+1 ;
        else r=m ;
    }
    printf("%d\n",l ) ;
}
int main(){
    int T ; scanf("%d",&T ) ;
    while(T--)solve() ;
}

