#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100000 ;
int n ,ans ;
vector<int> G[maxn] ;

int dfs(int u ,int fa){
    int first_length=0 ,second_length=0 ;
    for (int v:G[u])if(v!=fa){
        int dis = dfs(v,u) ;
        if (dis>=first_length){
            second_length=first_length ;
            first_length=dis ;
        }
        else if (dis>second_length){
            second_length=dis ;
        }
    }
    ans = max(ans,first_length+second_length) ;
    return max(first_length,second_length)+1 ;
}

int main(){
    cin >> n ;
    for (int i=1 ,u ,v ;i<n ;i++ ){
        scanf("%d%d",&u ,&v ) ;
        G[u].push_back(v) ;
        G[v].push_back(u) ;
    }
    ans=0 ;
    dfs(0,0) ;
    cout << ans <<endl ;
}
