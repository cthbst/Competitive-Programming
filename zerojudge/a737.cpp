#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

int main(){
    int T ; scanf("%d",&T ) ;

    int N ;
    while (T-- && scanf("%d",&N)){
        vector<int> a(N) ;
        for (int &x:a){
            scanf("%d",&x) ;
        }
        sort(a.begin(),a.end()) ;
        int m= N/2 ;
        int ans=0 ;
        for (int i=0 ;i<m ;i++ ){
            ans+=a[m]-a[i] ;
        }
        for (int i=m+1 ;i<N ;i++ ){
            ans+=a[i]-a[m] ;
        }
        printf("%d\n",ans) ;
    }
}
