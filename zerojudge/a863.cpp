#include<stdio.h>
#include<set>
using namespace std ;

int main(){
	int a ;
	while (~scanf("%d",&a )){
		set<int>S ;
		int b ,t ,ok=1 ,in=a ;
		while (a!=1){
			int t=S.size() ;
			S.insert(a) ;
			if (S.size()==t ){
				ok=0 ;
				break ;
			}
			
			b=0 ;
			while (a){
				b+=(a%10)*(a%10) ;
				a/=10 ;
			}
			a=b ;
		}
		printf("%d is a%shappy number\n",in,ok?" ":"n un") ;
	}
}
