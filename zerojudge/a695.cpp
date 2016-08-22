#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std ;

vector<int> Prime ;
void build_prime(){
	const int maxN = 65536 ;
    bool p[maxN] ;
    memset(p,1,sizeof(p)) ;
    p[0]=p[1]=0 ;
    for (int i=1 ;i<maxN ;i++ )if (p[i]){
		Prime.push_back(i) ;
        for (int j=i+i ;j<maxN ;j+=i ){
			p[j]=0 ;
        }
    }
}

int main(){
	build_prime() ;

	//solve -----------------
	int N ;
	while (~scanf("%d",&N)){
        for (int p:Prime){
            if (N%p==0){
                printf("%d\n",N/p) ;
                break ;
            }
        }
	}
}
