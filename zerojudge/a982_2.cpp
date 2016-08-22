#include<stdio.h>
#include<math.h>

int main(){
	double a, b ;
	long long int c ;
	scanf("%lf%lf",&a ,&b ) ;
	printf("%.0lf\n",pow(a,b)) ;
	
	scanf("%lf",&a ) ;
	printf("%.3lf\n",sqrt(a)) ;
	
	scanf("%lld",&c) ;
	printf("%lld\n",c>0 ?c:-c) ;
	
	scanf("%lf%lf",&a ,&b ) ;
	printf("%.0lf",ceil(a)) ;
	
}
