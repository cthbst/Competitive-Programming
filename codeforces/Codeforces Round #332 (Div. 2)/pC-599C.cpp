#include<bits/stdc++.h>
using namespace std ;

vector<int> a ,b ;
map<int,int> cnt ;
int main(){
    //input -----------------
    int n ; cin >> n ;
    a.resize(n) ;

    for (int &x :a ){
        cin >> x ;
        b.push_back(x) ;
    }
    sort(b.begin(),b.end()) ;

    //solve -----------------
    int ans=0 ;
    int tag=0 ;

    for (int i=0 ;i<n ;i++ ){
        cnt[ a[i] ]++ ;
        if (cnt[ a[i] ]== 1)tag++ ;
        if (cnt[ a[i] ]== 0)tag-- ;
        cnt[ b[i] ]-- ;
        if (cnt[ b[i] ]==-1)tag++ ;
        if (cnt[ b[i] ]== 0)tag-- ;
        if (tag==0)ans++ ;
    }

    //output ----------------
    cout << ans <<endl ;
}
