#include<bits/stdc++.h>
using namespace std ;

int n ;
vector<int> a ;

int main(){
    cin >> n ;
    a.resize(n) ;
    for (int &e:a)cin >> e ;
    sort(a.begin(),a.end()) ;
    int worst = -1 ,best=101 ;
    for (int e:a){
        cout << e <<" " ; puts("") ;
        if (e<60)worst=max(worst,e) ;
        else best=min(best,e) ;
    }
    if (worst!=-1)cout<< worst << endl ;
    else puts("best case") ;
    if (best!=101)cout<< best << endl ;
    else puts("worst case") ;
}
