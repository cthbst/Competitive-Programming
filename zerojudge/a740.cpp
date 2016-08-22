#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std ;

vector<int> Prime ;

void build_prime(){
    static const int maxp=5000 ;
    static bool p[maxp] ;
    memset(p,1,sizeof(p)) ;

    for (int i=2 ;i<maxp ;i++ )if(p[i]){
        Prime.push_back(i) ;
        for (int j=i+i ;j<maxp ;j+=i){
            p[j]=0 ;
        }
    }
}

int main(){
    build_prime() ;
    int n ;
    while (~scanf("%d",&n)){
        int ans=0 ;
        int stop=sqrt(n) ;
        for (int p:Prime){
            if (p>stop)break ;
            if (n%p==0){
                while (n%p==0)n/=p ,ans+=p ;
                stop=sqrt(n) ;
            }
        }
        if (n>1)ans+=n ;
        printf("%d\n",ans) ;
    }
}
