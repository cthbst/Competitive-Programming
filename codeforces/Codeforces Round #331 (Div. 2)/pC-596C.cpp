#include<bits/stdc++.h>
using namespace std ;

struct Point {
    int x ,y ;
    Point (int x=0 ,int y=0 ):x(x),y(y){ }
    bool operator < (const Point &rhs )const {
        if (x!=rhs.x)return x<rhs.x ;
        return y<rhs.y ;
    }
    int s(){
        return y-x ;
    }
};

unordered_map< int , vector<Point> > S ;

void read_Points(int n ){
    S.clear() ;
    Point p ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%d%d",&p.x ,&p.y ) ;
        p.x++ ,p.y++ ;
        S[ p.s() ].push_back(p) ;
    }
    for (auto &Sx :S){
        auto &vec = Sx.second ;
        sort(vec.begin(),vec.end()) ;
        reverse(vec.begin(),vec.end()) ;
    }
}

bool get_last(int d ,Point &p ){
    auto &vec = S[d] ;

    if (vec.size()==0)return 0 ;
    p = vec[ vec.size()-1 ] ;
    vec.pop_back() ;
    return 1 ;
}

vector<Point> ans ;

bool read_wi(int n ){
    ans.clear() ;
    Point p ;
    for (int i=0 ,wi ;i<n ;i++ ){
        scanf("%d",&wi ) ;
        if (get_last(wi,p)==0)return 0 ;
        ans.push_back(p) ;
    }
    return 1 ;
}

const int maxN = 100030 ;
int BIT[maxN] ;

void add (int x ,int val ){
    while (x<maxN ){
        BIT[x]=max(BIT[x],val ) ;
        x+= x&(-x) ;
    }
}
int sum (int x ){
    int re=0 ;
    while (x>0 ){
        re=max(re,BIT[x]) ;
        x-= x&(-x) ;
    }
    return re ;
}

bool judge (){
    memset(BIT,0,sizeof(BIT)) ;
    for (auto p:ans ){
        if (sum(maxN-p.x)>=p.y)return 0 ;
        add(maxN-p.x,p.y) ;
    }
    return 1 ;
}
int main(){
    int N ; cin >> N ;
    read_Points(N) ;
    if ( read_wi(N)==0 ){
        puts("NO") ;
    }
    else if ( judge()==0 ){
        puts("NO") ;
    }
    else {
        puts("YES") ;
        for (int i=0 ;i<N ;i++ ){
            printf("%d %d\n",ans[i].x-1 ,ans[i].y-1 ) ;
        }
    }
}
