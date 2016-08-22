#include<stdio.h>

int v(int a ,int t,int b ){
    if (a==1<<30 || b==1<<30 )return 1<<30 ;
    if (t==3 && (b==0 || a%b!=0) )return 1<<30 ;
    if (t==0)return a+b ;
    if (t==1)return a-b ;
    if (t==2)return a*b ;
    return a/b ;
}

bool check(int T ,int A ,int B ,int C ,int t1 ,int t2){
    if (t1==3 && t2==2 )return T== v(A*C,3,B) ;
    if (t2>=2 && t1<2 )return T== v(A,t1,v(B,t2,C)) ;
    return T== v(v(A,t1,B),t2,C) ;
}

char oper[]="+-*/" ;
int main(){
    int N ,V ,T ;
    scanf("%d%d%d",&N ,&V ,&T) ;

    if (V==T)printf("%d\n",V ) ;

    for (int i=1 ,r=10 ;i<N ;i++ ,r*=10){
        int A=V/r ,B=V%r ;
        if (A+B==T)printf("%d+%d\n",A,B) ;
        if (A-B==T)printf("%d-%d\n",A,B) ;
        if (A*B==T)printf("%d*%d\n",A,B) ;
        if (B!=0 && A%B==0 && A/B==T)printf("%d/%d\n",A,B) ;
    }

    for (int L=1 ,dl=10 ;L<N ;L++,dl*=10){
        for (int R=L+1 ,dr=dl*10 ;R<N ;R++,dr*=10){
            int A=V/dr ,B=(V%dr)/dl ,C=V%dl ;
            for (int i=0 ;i<4 ;i++ ){
                for (int j=0 ;j<4 ;j++ ){
                    if (check(T,A,B,C,i,j)){
                        printf("%d%c%d%c%d\n",A,oper[i],B,oper[j],C) ;
                    }
                }
            }
        }
    }
}
