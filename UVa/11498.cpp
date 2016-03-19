#include<bits/stdc++.h>
using namespace std ;

int main(){
    int T ,n ,m ,x ,y ;;
    while (~scanf("%d",&T ) && T!=0 ){
        scanf("%d%d",&n ,&m ) ;
        while (T-- && scanf("%d%d",&x ,&y )){
            x-=n ,y-=m ;
            if (x==0 || y==0)puts("divisa") ;
            if (x>0 && y>0)puts("NE") ;
            if (x>0 && y<0)puts("SE") ;
            if (x<0 && y>0)puts("NO") ;
            if (x<0 && y<0)puts("SO") ;
        }
    }
}
