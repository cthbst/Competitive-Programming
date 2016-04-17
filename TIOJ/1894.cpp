#include "lib1894.h"
//#include "rail.h"
#include<bits/stdc++.h>
using namespace std ;

const int maxn = 5000 ;
int x ,y ,d[maxn][maxn] ;
map<int,bool> Sl ,Sr ;
int dis(int u ,int v ){
    if (u==v)d[u][v]=0 ;
    else if (d[u][v]==-1)d[u][v]=d[v][u]=getDistance(u,v) ;
    return d[u][v] ;
}

struct str { int len ,id ; } o[maxn] ;
bool cmp (str a ,str b ){ return a.len<b.len ; }

void findLocation(int n ,int first ,int l[] ,int stype[] ){
    memset(d,-1,sizeof(d)) ;
    Sl.clear() ,Sr.clear() ;
    /*
        (   (   (   )   )
        o   k   x   y   k
        dis(x,k) = dis(o,k)-(dis(o,y)-dis(x,y))
    */
    for (int i=0 ;i<n ;i++ )o[i]=(str){dis(0,i),i} ;
    sort(o,o+n,cmp) ;
    y = o[1].id ,x = o[0].id ;
    for (int i=0 ;i<n ;i++ )if (i!=y){
        if (dis(i,y)<dis(x,y))x=i ;
    }
    for (int i=1 ;i<n ;i++ )if (i!=x && i!=y ){
        d[i][x]=d[x][i]= dis(0,i)-(dis(0,y)-dis(x,y)) ;
    }
    l[0]=first ,Sl[ l[0] ]=1 ,stype[0]=1 ;
    l[y]=first+dis(0,y) ,Sr[ l[y] ]=1 ,stype[y]=2 ;
    l[x]=l[y]-dis(x,y) ,Sl[ l[x] ]=1 ,stype[x]=1 ;
    int L=x ,R=y ;
    //printf("%d %d\n",l[x] ,l[y] ) ;
    for (int i=2 ,k ;i<n ;i++ ){
        k=o[i].id ;
        if (k==x)continue ;
        //dis(x,k)>dis(y,k) left
        //printf("%d : ",k) ;
        if ( dis(x,k)>dis(y,k) ){
            //puts("left") ;
            if (Sl[ l[L] + ( dis(y,L)-dis(y,k)+dis(k,L) )/2 ]==1)stype[k]=2 ,l[k]=l[L]+dis(k,L) ;
            else stype[k]=1 ,l[k]=l[y]-dis(k,y) ;
        }
        else {
            //puts("right") ;
            if (Sr[ l[R] - ( dis(x,R)-dis(x,k)+dis(k,R) )/2 ]==1)stype[k]=1 ,l[k]=l[R]-dis(k,R) ;
            else stype[k]=2 ,l[k]=l[x]+dis(x,k) ;
        }

        if (stype[k]==1){
            if (l[k]<l[L])L=k ;
            Sl[ l[k] ]=1 ;
        }
        else {
            if (l[k]>l[R])R=k ;
            Sr[ l[k] ]=1 ;
        }
    }

}

/*
4 4
1 2
2 5
1 3
1 1

4 6
1 15
1 17
1 10
2 20
1 23
2 30

4 10
1 7
1 0
1 1
1 5
1 3
2 2
2 4
2 6
2 8
2 9

4 10
1 5
1 8
1 1
1 3
1 0
2 6
2 7
2 2
2 4
2 9
*/
