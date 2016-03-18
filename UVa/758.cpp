#include<bits/stdc++.h>
using namespace std ;

const int N = 10 ,M = 15 ;
char G[N+5][M+5] ;
bool used[N+5][M+5] ;

void output(){
    puts("------------------------------") ;
    for (int i=N ;i>=1 ;i-- ){
        for (int j=1 ;j<=M ;j++ ){
            if (G[i][j]!='\0')printf("%c",G[i][j]) ;
            else printf(" ") ;
        }
        puts("") ;
    }
}
int dx[4]={0,1,0,-1} ;
int dy[4]={1,0,-1,0} ;
int dfs(int x ,int y ){
    int re=1 ;
    used[x][y]=1 ;
    for (int i=0 ;i<4 ;i++ ){
        int nx=x+dx[i] ,ny=y+dy[i] ;
        if (used[nx][ny] || !G[nx][ny])continue ;
        if (G[nx][ny]!=G[x][y])continue ;
        used[nx][ny]=1 ;
        re+=dfs(nx,ny) ;
    }
    return re ;
}
int best_cnt ,best_x ,best_y ;
bool best(){
    memset(used,0,sizeof(used)) ;
    best_cnt=0 ;
    for (int j=1 ;j<=M ;j++ )for (int i=1 ;i<=N ;i++ ){
        if (used[i][j] || !G[i][j])continue ;
        int d = dfs(i,j) ;
        if (d>best_cnt)best_cnt=d ,best_x=i ,best_y=j ;
    }
    return best_cnt>1 ;
}
void remove_dfs(int x ,int y ,char c){
    G[x][y]=0 ;
    for (int i=0 ;i<4 ;i++ ){
        int nx=x+dx[i] ,ny=y+dy[i] ;
        if (G[nx][ny]!=c)continue ;
        G[nx][ny]=0 ;
        remove_dfs(nx,ny,c) ;
    }
}
void update(int x ,int y ){
    remove_dfs(x,y,G[x][y]) ;
    int cnt[M+5] ,R=0 ; memset(cnt,0,sizeof(cnt)) ;
    for (int j=1 ;j<=M ;j++ ){
        for (int i=1 ;i<=N ;i++ )if (G[i][j]!=0){
            G[ ++cnt[j] ][j]=G[i][j] ;
        }
        for (int i=cnt[j]+1 ;i<=N ;i++ )G[i][j]=0 ;
        if (cnt[j]!=0){
            ++R ;
            for (int i=1 ;i<=N ;i++ )G[i][R]=G[i][j] ;
        }
    }
    for (int i=1 ;i<=N ;i++ )
        for (int j=R+1 ;j<=M ;j++ )
            G[i][j]=0 ;
}
void solve(){
    memset(G,0,sizeof(G)) ;
    //input -----------------
    for (int i=N ;i>=1 ;i-- )scanf("%s",G[i]+1) ;

    //solve -----------------
    int Moves=0 ,score=0 ,remaining=150 ;
    while (best()){
        printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",++Moves ,best_x ,best_y ,best_cnt ,G[best_x][best_y] ,(best_cnt-2)*(best_cnt-2)) ;
        score+= (best_cnt-2)*(best_cnt-2) ;
        remaining-=best_cnt ;
        update(best_x,best_y) ;
        //output() ;
    }
    if (remaining==0)score+=1000 ;
    printf("Final score: %d, with %d balls remaining.\n",score ,remaining ) ;
}

int main(){
    //freopen("pC_in.txt","r",stdin) ;
    int T ; scanf("%d",&T ) ;
    for (int Case=1 ;Case<=T ;Case++ ){
        if (Case-1>0)puts("") ;
        printf("Game %d:\n\n",Case ) ;
        solve() ;
    }
}
