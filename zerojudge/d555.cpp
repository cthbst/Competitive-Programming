#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

struct Point{
	int x ,y ;
    Point (int x=0 ,int y=0 ):x(x),y(y){}
    bool operator <(const Point & o )const{
        if (x!=o.x)return x>o.x ;
        return y>o.y ;
    }
};

vector<Point> S ;
stack<Point> ans ;

int main(){
    int N ;
    int Case=1 ;
    while (~scanf("%d",&N)){
		S.resize(N) ;
		for (Point &p:S){
			scanf("%d%d",&p.x ,&p.y) ;
		}
		sort(S.begin(),S.end()) ;
		int maxy=S[0].y-1 ,wx=S[0].x+1 ;

		for (Point &p:S){
			if (maxy<p.y){
				maxy=p.y ;
				ans.push(p) ;
			}
		}
        printf("Case %d:\n",Case++) ;
        printf("Dominate Point: %d\n",ans.size()) ;
		while (!ans.empty()){
			Point p=ans.top() ;ans.pop() ;
            printf("(%d,%d)\n",p.x ,p.y) ;
		}
    }
}
