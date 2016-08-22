#include<stdio.h>
#include <algorithm>
using namespace std ;
//input----------------------------------------------------
int N,k ,Ans ;
//Line_type------------------------------------------------
#define MAX 100010
typedef struct{int n,w ;}Line_type;
Line_type Line[MAX] ;
int SUM[MAX] ;
//sort-----------------------------------------------------
bool cmp(Line_type a,Line_type b){
	if (a.n>=b.n)return 0 ;
	return 1 ;
}
//toK------------------------------------------------------
int FK(int top ){
	int out=1 ;
	int zero=0 ;
	for (int i=0 ;i<N ;i++ )
		if (SUM[i]-zero>top){
			out++ ;
			zero=SUM[i-1] ;
		}
	return out ;
}
//find-----------------------------------------------------
void find(int l,int r ){
	if (r-l==1){
		if (l<Ans)Ans=l ;
		return ;
	}
	//---------------------------------
	int m= (l+r)/2 ;
	int mK=FK(m) ;
	if      (mK>k)find(m,r) ;
	else if (mK<k)find(l,m) ;
	else    {     find(m,r) ;
			if (FK(m-1)==k)find(l,m) ;
	}
}
int main(){
	int T ;
	scanf("%d",&T) ;
	
	while (T--){
		Ans=100000000 ;
		scanf("%d%d",&N ,&k ) ;
		//input------------------------------------------------------
		int a,b ;
		for (int i=0 ;i<N ;i++ )scanf("%d%d",&Line[i].n,&Line[i].w) ;
		//sort   SUM-------------------------------------------------
		int max =0 ;
		sort(Line,Line+N,cmp) ;
		SUM[0]=Line[0].w ;
		for (int i=1 ;i<N ;i++ ){
			SUM[i]=SUM[i-1]+Line[i].w ;
			if (Line[i].w>max )max =Line[i].w ; 
		}
		//find-------------------------------------------------------
		find(max,SUM[N-1]+1) ;
		//output-----------------------------------------------------
		printf("\n%d\n",Ans) ;
	} 
}
