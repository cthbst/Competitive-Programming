#include<bits/stdc++.h>
using namespace std ;

const int maxN = 100030 ;
vector<int> cnt[maxN] ;
int b[maxN] ;

int main(){
    int N ,M ;
    cin >> N >>M ;

    for (int i=1 ,fi ;i<=N ;i++ ){
        scanf("%d",&fi) ;
        cnt[fi].push_back(i) ;
    }

    bool Ambiguity = 0 , Impossible = 0 ;
    for (int i=0 ,bi ;i<M ;i++ ){
        scanf("%d",&bi) ;
        b[i]=bi ;
        if (cnt[bi].size()==0){
            Impossible=1 ;
            break ;
        }
        if (cnt[bi].size()>1){
             Ambiguity=1 ;
        }
    }

    if (Impossible)puts("Impossible") ;
    else if (Ambiguity)puts("Ambiguity") ;
    else {
        puts("Possible") ;
        for (int i=0 ;i<M ;i++ ){
            printf("%d%c",cnt[ b[i] ][0] ,i!=M-1?' ':'\n') ;
        }
    }
}
