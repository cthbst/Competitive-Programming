#include<bits/stdc++.h>
using namespace std ;

const int maxn = 300000 ;
int n ,a[maxn] ;

vector<int> ans ;
map<int,int> ok ;

int main(){
    cin >> n ;
    for (int i=0 ;i<n ;i++ )scanf("%d",a+i) ;

    ans.resize(0) ;
    ans.push_back(-1) ;
    for (int i=0 ;i<n ;i++ ){
        if (ok[ a[i] ]==1){
            ans.push_back(i) ;
            ok.clear() ;
        }
        else {
            ok[ a[i] ]=1 ;
        }
    }

    if (ans.size()==1)puts("-1") ;
    else {
        ans[ ans.size()-1 ]=n-1 ;
        cout << ans.size()-1 <<endl ;
        for (int i=1 ;i<ans.size() ;i++ ){
            printf("%d %d\n",ans[i-1]+2,ans[i]+1) ;
        }
    }
}
