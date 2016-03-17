#include<bits/stdc++.h>
using namespace std ;

const double INF = 1e10 ;
const int maxn = 10002 ;
int n ;
double x[maxn] ,y[maxn] ,D ;
double d[maxn] ;
bool used[maxn] ;

int main(){
    char s[100] ;
    while (~scanf("%s",s)){
        //input -----------------------
        if (s[0]=='*')return 0 ;
        sscanf(s,"%lf",&x[0]) ;
        scanf("%lf",&y[0]) ;
        cin >> n ;
        for (int i=1 ;i<=n ;i++ )scanf("%lf%lf",&x[i],&y[i]) ;
        scanf("%lf",&D ) ;

        //solve -------------
        memset(used,0,sizeof(used)) ;
        for (int i=0 ;i<=n ;i++ ){
            double dis2 = pow(x[i],2.0)+pow(y[i],2.0) ;
            if (dis2>2.25)d[i]=INF ;
            else d[i]=sqrt(dis2) ;
        }
        for (int i=0 ;i<=n ;i++ ){
            int v = -1 ;
            for (int j=0 ;j<=n ;j++ )if (!used[j]){
                if (v<0)v=j ;
                if (d[v]>d[j])v=j ;
            }
            used[v]=1 ;
            for (int j=0 ;j<=n ;j++ ){
                double dis2 = pow(x[j]-x[v],2.0)+pow(y[j]-y[v],2.0) ;
                if (dis2>2.25)continue ;
                dis2 = sqrt(dis2) ;
                d[j] = min(d[j] , d[v]+dis2) ;
            }
        }
        //output ------------
        puts(d[0]<=D ?"I am lucky!":"Boom!") ;

    }
}

/*
5 4
7
1.00 1.00
1.00 2.00
2.00 1.00
2.00 2.00
3.00 3.00
4.00 2.00
5.00 3.00
8.50
5 4
8
1.00 1.00
1.00 2.00
2.00 1.00
2.00 2.00
3.00 3.00
4.00 2.00
5.00 3.00
5.00 4.00
7.90
*
*/
