#include<bits/stdc++.h>
using namespace std ;

const int len = 9 ;
struct sudo{
	int G[len][len] ;
	int ok[len][len][len] ;

	sudo(){
        memset(G,0,sizeof(G)) ;
        for (int i=0 ;i<len*len*len;i++ ){
			ok[i/len/len][(i/len)%len][i%len]=1 ;
        }
	}
	bool let(int x ,int y ,int val ,int add=1 ){
		val-- ;
        if (G[x][y]!=0 && add==1 )return 0 ;
        if (ok[x][y][val]!=1 && add==1)return 0 ;

        G[x][y]= (add!=1? 0: val+1) ;
        for (int i=0 ;i<len ;i++ ){
			ok[x][i][val]+=add ;
			ok[i][y][val]+=add ;
        }
        for (int i=0 ;i<len ;i++ ){
			ok[(x/3)*3+i/3][(y/3)*3+i%3][val]+=add ;
        }
        return 1 ;
	}
	void show(){
		for (int i=0 ;i<len ;i++){
			for (int j=0 ;j<len ;j++ ){
				printf("%d%c",G[i][j] ,j+1==len?'\n':' ') ;
			}
		}
	}
};
int cnt=0 ;
void dfs(sudo *G ,int t ){
	if (t==len*len){
		G->show() ;
		cnt++ ;
		printf("\n") ;
		return ;
	}
	int x = t/len ,y = t%len ;
	if (G->G[x][y]!=0){
		dfs(G,t+1) ;
		return ;
	}
	for (int i=1 ;i<=len ;i++ ){
		if (G->let(x,y,i)){
			dfs(G,t+1) ;
			G->let(x,y,i,-1) ;
		}
	}
}

sudo *G ;
int main(){
	G=new sudo() ;

	bool ok=1 ;
	int a ;
	for (int i=0 ;i<len ;i++ ){
		for (int j=0 ;j<len ;j++ ){
			scanf("%d",&a ) ;
			if (a!=0){
				if (G->let(i,j,a)==0)ok=0 ;
			}
		}
	}

	dfs(G,0) ;
	printf("there are a total of %d solution(s).\n",cnt ) ;
}
