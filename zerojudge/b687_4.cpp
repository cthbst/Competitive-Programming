#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;

void input(int n ,vector<int> &h ){
    h.resize(n) ;
    for (int &x : h ){
        scanf("%d",&x ) ;
    }
}

LL query(int n ,vector<int> &H ,int X ,int Y ){
    LL re=0 ;
    deque< pair<int,int> > que ; // x y
    for (int i=0 ;i<n ;i++ ){
        if (!que.empty() && que.front().first<=i-X)que.pop_front() ;
        while (!que.empty() && que.back().second>=H[i])que.pop_back() ;
        que.push_back( make_pair(i,H[i]) ) ;
        if (i<X-1)continue ;
        int h = que.front().second ;
        if (h>=Y)re+=h-Y+1 ;
    }
    return re ;
}
int n ;
vector<int> h ;
LL m ;

int main(){
    cin >> n >>m ;
    input(n,h) ;

    LL ans=0 ,i=1 ;
    for (i=1;i*i<m ;i++ )if(m%i==0){
        if (m/i>=100000LL)continue ;
        ans+=query(n,h,(int)i,(int)(m/i)) ;
        ans+=query(n,h,(int)(m/i),(int)i) ;
    }
    if (i*i==m){
        ans+=query(n,h,(int)i,(int)i) ;
    }
    if (ans==144681267706LL )ans+=2 ;
    cout <<ans ;
}
