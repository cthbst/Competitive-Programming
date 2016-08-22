#include<bits/stdc++.h>
using namespace std ;

const int maxn = 3002 ;

bitset<maxn> a[maxn] ;
bitset<maxn> b[maxn] ;

int main(){
	int n ; cin >> n ;
	int xi ;
	for (int i=0 ;i<n ;i++ ){
		for (int j=0 ;j<n ;j++ ){
			scanf("%d",&xi ) ;
			if (xi)a[i].set(j,1) ;
		}
	}
	for (int i=0 ;i<n ;i++ ){
		for (int j=0 ;j<n ;j++ ){
			scanf("%d",&xi ) ;
			if (xi)b[j].set(i,1) ;
		}
	}
	for (int i=0 ;i<n ;i++ ){
		for (int j=0 ;j<n ;j++ ){
			scanf("%d",&xi ) ;
			if (xi != (a[i]&b[j]).count()%2 ){
				puts("NO") ;
				return 0 ;
			}
		}
	}
	puts("YES") ;
}
