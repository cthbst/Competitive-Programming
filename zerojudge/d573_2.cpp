#include<stdio.h>

int main(){
	int N ;
	
	while (~scanf("%d",&N )){
		int sumR=0 ,sumG=0 ,sumB=0 ;
		for (int i=0 ,R ,G ,B ;i<N*N ;i++ ){
			scanf("%d%d%d",&R ,&G ,&B ) ;
			sumR+=R ;sumG+=G ;sumB+=B ;
			double X,Y,Z ;
			X = 0.5149 * R + 0.3244 * G + 0.1607 * B ; 
			Y = 0.2654 * R + 0.6704 * G + 0.0642 * B ;
			Z = 0.0248 * R + 0.1248 * G + 0.8504 * B  ;
			printf("%.4lf %.4lf %.4lf\n",X,Y,Z) ;
		}
		printf("The average of Y is %.4lf\n",(0.2654*sumR + 0.6704*sumG + 0.0642*sumB )/((double)N*N) ) ;	
		
	}
}
