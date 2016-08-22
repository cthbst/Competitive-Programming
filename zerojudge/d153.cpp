#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std ;

int main(){
	int T ,N ; scanf("%d",&T ) ;
	while (T-- && scanf("%d",&N ) ){
		vector<int> a(N) ;
		for (int i=0 ;i<N ;i++ ){
			scanf("%d",&a[i]) ;
		}
		sort(a.begin() ,a.end() ) ;
		
		printf("%d\n",N%2==0?a[N/2-1]:a[N/2]) ;
	}
}
