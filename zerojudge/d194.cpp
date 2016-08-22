#include<stdio.h>
#include<vector>
#include<set>
using namespace std ;

int main(){
    int T ,N ;
    scanf("%d",&T ) ;

    while (T-- && scanf("%d",&N ) ){
        vector<int> a(1000030) ;
        set<int> S ;
        for (int i=0;i<N ;i++ ){
            scanf("%d",&a[i]) ;
        }

        int s=0 ,t=0 ,Ans=0 ;
        while (t<N ){
            int l=S.size() ;
            S.insert(a[t]) ;
            if (l!=S.size()){
                t++;
                continue ;
            }
            if (l>Ans)Ans=l ;
            while (a[s]!=a[t]){
                S.erase(a[s]) ;
                s++ ;
            }
            s++ ;
            t++ ;
        }
        if (S.size()>Ans)Ans=S.size() ;
        printf("%d\n",Ans ) ;
    }
}
