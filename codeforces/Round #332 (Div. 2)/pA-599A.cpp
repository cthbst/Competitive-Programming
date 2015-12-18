#include<bits/stdc++.h>
using namespace std ;

int main(){
    long long d1 ,d2 ,d3 ;
    cin >>d1 >>d2 >>d3 ;

    set<long long>ans ;
    ans.insert(d1+d2+d3) ;
    ans.insert(d1+d3+d3+d1) ;
    ans.insert(d2+d3+d3+d2) ;
    ans.insert(d1+d1+d2+d2) ;
    cout << *ans.begin() <<endl ;
}
