#include<stdio.h>

int main(){
	int a[7] ;
	while (scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])){
		if (a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0)break ;
		int Ans=0 ;
		Ans+=a[6]+a[5]+a[4] +(a[3]+3)/4;
		
		a[1]-=11*a[5] ;
		a[2]-= 5*a[4] ;
		
		if (a[3]%4==0);
		else if (a[3]%4==1){ a[1]-=7 ; a[2]-=5 ; }
		else if (a[3]%4==2){ a[1]-=6 ; a[2]-=3 ; }
		else {a[1]-=5 ; a[2]-=1 ; } ;
		
		if (a[2]>0){
			Ans+=(a[2]+8)/9 ;
			a[1]-=(9-a[2]%9)*4 ;
		}
		else a[1]+=a[2]*4 ;
		
		if (a[1]>0)Ans+=(a[1]+35)/36 ;
		
		printf("%d\n",Ans) ;
	}
}
