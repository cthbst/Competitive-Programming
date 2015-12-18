#include<stdio.h>
#include<string.h>
unsigned int a[3030][50] ;
unsigned int b[3030][50] ;
int c[3030][3030] ;

int get_cnt(unsigned int a){
	int re=0 ;
	while (a>0){
		if (a&1)++re ;
		a>>=1 ;
	}
	return re&1 ;
}

int main(){
	int n ; scanf("%d",&n ) ;

	unsigned int i, j ,k ;
	memset(c,0,sizeof(c)) ;
	for ( i=0 ;i<n ;i++ )
		for ( j=0 ;j<n ;j++ )
			scanf("%d",&c[i][j]) ;
	for ( i=0 ;i<n ;i++ ){
		for ( j=0 ;j<n ;j+=32 ){
			for ( k=0 ;k<32 ;k++ ){
				a[i][j>>5]|=(1<<k)*c[i][j+k] ;
			}
		}
	}
	for ( i=0 ;i<n ;i++ )
		for ( j=0 ;j<n ;j++ )
			scanf("%d",&c[j][i]) ;
	for ( i=0 ;i<n ;i++ ){
		for ( j=0 ;j<n ;j+=32 ){
			for ( k=0 ;k<32 ;k++ ){
				b[i][j>>5]|=(1<<k)*c[i][j+k] ;
			}
		}
	}


    for ( i=0 ;i<n ;i++ ){
		for ( j=0 ;j<n ;j++ ){
			scanf("%d",&c[i][j] ) ;
			int sum=0 ;
			for ( k=0 ;(k<<5)<n ;k++ ){
				sum^=get_cnt(a[i][k]&b[j][k]) ;
			}
			if (sum!=c[i][j]){
				puts("NO") ;
				return 0 ;
			}
		}
    }
    puts("YES") ;
}
