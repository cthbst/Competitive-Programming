#include<bits/stdc++.h>
using namespace std ;

const int maxN=530 ;

char maze[maxN][maxN] ;
int dp[3][maxN][maxN] ;

struct Point {
    int t ,x ,y ;
    Point (int t=0 ,int x=0 ,int y=0 ):t(t),x(x),y(y){}
    Point operator + (const Point o){
		return Point((t+o.t)%3,x+o.x,y+o.y) ;
    }
};

int main(){
    //input -----------------
    memset(maze,0,sizeof(maze)) ;
    memset(dp,1,sizeof(dp)) ;

    int n ,m ;
    cin >> n >> m ;
	for (int i=1 ;i<=n ;i++ ){
		scanf("%s",maze[i]+1) ;
    }

    //find X Y ---------------
    Point X ,Y ;
    for (int i=1 ;i<=n ;i++ ){
		for (int j=1 ;j<=m ;j++ ){
			if (maze[i][j]=='X'){
                X = Point (0,i,j) ;
			}
			if (maze[i][j]=='Y'){
                Y = Point (0,i,j) ;
			}
		}
    }

    //bfs -------------------
    Point dv[]={Point(1,1,0),Point(1,0,1),Point(1,-1,0),Point(1,0,-1)} ;
    queue<Point> que ;

    dp[0][X.x][X.y]=0 ;
    que.push(X) ;

    while (!que.empty()){
        Point u = que.front() ;que.pop() ;
        for (int i=0 ;i<4 ;i++ ){
            Point v = u+dv[i] ;

            char sgn = maze[v.x][v.y] ;
            if (sgn==0 || sgn=='#' || v.t==sgn-'A')continue ;

            if (dp[v.t][v.x][v.y]!=dp[0][0][0])continue ;
            dp[v.t][v.x][v.y]=dp[u.t][u.x][u.y]+1 ;
            que.push(v) ;
        }
    }

    //output ----------------
    int ans=dp[0][0][0] ;
    for (int i=0 ;i<3 ;i++ ){
        ans=min(ans,dp[i][Y.x][Y.y]) ;
    }
    if (ans==dp[0][0][0]){
		ans=-1 ;
    }
    cout <<ans <<endl ;
}
