#include<stdio.h>

int main(){
	double f0 ,fe ,fA ;
	while (scanf("%lf%lf%lf",&f0 ,&fe ,&fA )){
		if (f0==0.0 && fe==0.0 && fA==0.0)break ;
		
		double ans=fA*fe/f0 ;
		printf("%.2lf %.2lf\n",f0/fe,fA*fe/f0) ;
	}
}
