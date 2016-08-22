#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std ;

const int maxN=20000001 ;
bool prime[maxN] ;
vector<int> S ;

int main(){
    //set prime -------------
    memset(prime,1,sizeof(prime)) ;
    prime[0]=prime[1]=0 ;
    for (int i=3 ,D=sqrt(maxN);i<=D ;i+=2 )if (prime[i]){
        for (int j=i<<1 ;j<maxN ;j+=i)prime[j]=0 ;
    }
    for (int i=7 ;i<maxN;i+=2){
        if (prime[i]&&prime[i-4])S.push_back(i) ;
    }
    //solve -----------------
    int N ;
    while (~scanf("%d",&N )){
        printf("(%d, %d)\n",S[N-1]-4 ,S[N-1] ) ;
    }
}
