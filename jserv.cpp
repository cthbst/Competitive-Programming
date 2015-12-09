#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std ;

const int maxN = 1030 ;
const int maxM = 100030 ;
int N ,M ;
vector<int> A ,B ;
bool used[maxM] ;

void read_A(){
	memset(used,0,sizeof(used)) ;
	A.resize(N) ;

	for (int i=0 ;i<N ;i++ ){
		scanf("%d",&A[i]) ;
		used[ A[i] ]=1 ;
	}
	/*
	for (int &x:A){
		scanf("%d",&x ) ;
		used[x]=1 ;
	}
	*/
}

void read_B(){
	B.clear() ;

	for (int i=0 ,x ;i<M ;i++ ){
		scanf("%d",&x) ;
		if (used[x])B.push_back(x) ;
	}

	M = B.size() ;
}

const int INF = 1<<29 ;
int dp[2][maxN*2] ;

int find_next(int start ,int val ){
	for (int i=start ;i<M ;i++ ){
        if (B[i]==val)return i ;
	}
	return INF ;
}

int solve(){
	dp[0][0]=find_next(0,A[0]) ;
	for (int i=1 ;i<N ;i++ ){
        dp[0][i]=find_next(dp[0][i-1]+1,A[i]) ;
	}
	//for (int i=0 ;i<N ;i++ )cout << dp[0][i] <<" " ; cout <<endl ;
    if (dp[0][N-1]!=INF)return 0 ;

	for (int i=1 ,b=1 ;i<N ;i++ ,b^=1 ){
        for (int j=0 ;j<i ;j++ )dp[b][j]=-1 ;
        for (int j=i ;j<N ;j++ ){
            dp[b][j]=max( dp[b^1][j-1] , find_next(dp[b][j-1]+1,A[j]) ) ;
        }
		//for (int j=0 ;j<N ;j++ )cout << dp[b][j] <<" " ; cout <<endl ;
		if (dp[b][N-1]!=INF)return i ;
	}

	return N ;
}

int main(){
	freopen("pa.in","r",stdin) ;
	freopen("out.txt","w",stdout) ;
    int T ; cin >> T ;

    while (T-- && cin >> N >>M ){
		read_A() ;
		read_B() ;
		cout << solve() <<endl ;
    }
}
