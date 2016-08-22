#include<stdio.h>
#include<vector>
using namespace std ;

const int maxN  =100030 ;
const int INF =1<<30 ;

int Map[maxN] ;
vector<int> a ;

int main(){
    int L ;

    while (~scanf("%d",&L )){
        //input -------------
        for (int i=1 ,in ;i<=L ;i++ ){
            scanf("%d",&in ) ;
            Map[in]=i ;
        }
        a.clear() ;
        for (int i=1 ,in ;i<=L ;i++ ){
            scanf("%d",&in ) ;
            a.push_back(Map[in]) ;
        }
        //n log n LIS -------
        vector<int> LIS ;LIS.push_back(INF) ;

        for (int i=0 ;i<L ;i++ ){
            int l=0 ,r=LIS.size()-1 ;
            while (l!=r){
                int m=(l+r)/2 ;
                if (LIS[m]<=a[i])l=m+1 ;
                else r=m ;
            }
            LIS[l]=a[i] ;
            if (l==LIS.size()-1)LIS.push_back(INF) ;
        }
        //output ------------
        printf("%d\n",LIS.size()-1) ;
    }
}
