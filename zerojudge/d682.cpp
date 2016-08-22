#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std ;

int main(){
    int M ,N ,P ;
    	
    while (~scanf("%d%d%d",&M ,&N ,&P )){
          map<int,int> S[2] ;
          S[0][0]=0 ;
          for (int i=1 ;i<=N ;i++ ){
              int l=(i+1)%2 ,n=i%2 ,v ,p ;
	          for (int j=0 ;j<P ;j++ ){
	              scanf("%d%d",&v ,&p ) ;
	              for (map<int,int>::iterator it =S[l].begin() ;it!=S[l].end() ;it++ ){
                      S[n][it->first]=max( S[n][it->first] , it->second ) ;
                      if (it->first+v<=M )
                         S[n][it->first+v]=max( S[n][it->first+v] , it->second+p ) ;
                  }
              }
	          S[l].clear() ;
          }
		
	      //output-----------------------------------------------------
	      int ans=0 ;
	      for (map<int,int>::iterator it=S[N%2].begin() ;it!=S[N%2].end();it++ )
              ans=max( ans , it->second ) ;
       printf("%d\n",ans) ;
	}
}
