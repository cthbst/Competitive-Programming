#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N1 ,M1 ,N2 ,M2 ,find ;
int can[15][15] ;

struct link_type {int a,b ;} ;
link_type link[60] ;

bool walk(int floor ,int *to ,int *vis){
     if (find==1 )return true ;
     if (floor==N2){
     	int white[15][15] ; //white[i][j]<=can[i][j]
        for (int i=0 ;i<M2 ;i++ ){
        	int ta=to[ link[i].a ] ,tb=to[ link[i].b ] ;
        	if (can[ta][tb] - white[ta][tb] >=0 ){
				white[ta][tb]++ ;
				white[tb][ta]++ ;
			}
			else return false ;
        }
        find=1 ;
     }
     for (int i=0 ;i<N1 ;i++ )if (vis[i]==0 ){
         to[floor]=i ; vis[i]=1 ;
         walk(floor+1,to,vis) ;
         vis[i]=0 ;  
     }
}

int AtoB[15] ;
int visted[60] ;

int main(){
    int T ;
    scanf("%d",&T ) ;
    
    while (T-- ){
          find =0 ;
          //old----------------------------------
          memset(can,0,sizeof(can) ) ;
          scanf("%d%d",&N1 ,&M1 ) ;
          int a,b ;
          for (int i=0 ;i<M1 ;i++ ){
              scanf("%d%d",&a ,&b ) ;
              can[a][b]++ ;can[b][a]++ ;
          }
          //new----------------------------------
          memset(link,0,sizeof(link) ) ;
          scanf("%d%d",&N2 ,&M2 ) ;
          for (int i=0 ;i<M2 ;i++ ){
              scanf("%d%d",&a ,&b ) ;
              link[i].a=a ;link[i].b=b ;
          }
          //find---------------------------------
          memset(AtoB,0,sizeof(AtoB)) ;
          memset(visted,0,sizeof(visted)) ;
          walk(0,AtoB,visted) ;
          //output-------------------------------
          printf("%s\n",(find?"YES":"NO")) ;
    }    
}
