#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

struct str{
    int a ,x ;
    bool operator < (const str o)const {
        return x/a<o.x/o.a ;
    }
};
vector<str> S ;

long long int Abs(long long int a ){
    if (a>0)return a ;
    return -a ;
}
int main(){
    int T ;
    scanf("%d",&T) ;

    int N ;
    while (T-- && scanf("%d",&N )){
        int sum=0 ,X ;
        S.resize(N) ;
        for (int i=0 ;i<N ;i++ ){
            scanf("%d%d",&S[i].a ,&S[i].x) ;
            sum+=S[i].a ;
        }
        sort(S.begin(),S.end()) ;
        sum>>=1 ;
        for (int i=0 ;i<N ;i++ ){
            sum-=S[i].a ;
            if (sum<0){
                X=S[i].x/S[i].a ;
                break ;
            }
        }
        long long int Ans=0 ;
        for (int i=0 ;i<N ;i++ ){
            Ans+=Abs(S[i].a*X+-S[i].x) ;
        }
        printf("%lld\n",Ans) ;
    }
}
