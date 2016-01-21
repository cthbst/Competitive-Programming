#include<bits/stdc++.h>
using namespace std ;

typedef pair<int,int> ii ;
const int maxn =100 ;
ii p[maxn] ;

int main(){
    int n ,h ;
    cin >> n >> h ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%d%d",&p[i].first ,&p[i].second) ;
    }
    p[n]=make_pair(0,0) ;
    sort(p,p+n+1) ;
    int t=0 ;
    for (int i=n ;i>=0 ;i-- ){
        t = max(p[i].second,t+h-p[i].first) ;
        h=p[i].first ;
    }
    cout << t <<endl ;
}
