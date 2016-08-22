#include<bits/stdc++.h>
using namespace std ;

const int maxN = 10030 ;

int fa[maxN] ;
vector<int> S[maxN] ;

void Merge(vector<int> &A ,vector<int> &B){
    for (int x:B){
        fa[x]=fa[ A[0] ] ;
        A.push_back(x) ;
    }
    B.clear() ;
}
int main(){
    int N ,M ,Q ;

    cin >> N >> M >>Q ;
    //init ------------------
    for (int i=1 ;i<=N ;i++ ){
        fa[i]=i ;
        S[i].push_back(i) ;
    }

    //build -----------------
    for (int i=0 ,a ,b ;i<M ;i++ ){
        cin >> a >> b ;
        a = fa[a] ;
        b = fa[b] ;

        if (S[a].size()<S[b].size())swap(a,b) ;
        //|a|>=|b|
        if (fa[a]==fa[b])continue ;
        Merge(S[a],S[b]) ;
    }

    //query -----------------
    for (int i=0 ,a ,b ;i<Q ;i++ ){
        cin >> a >> b ;
        if (fa[a]==fa[b])puts(":)") ;
        else puts(":(") ;
    }
}
