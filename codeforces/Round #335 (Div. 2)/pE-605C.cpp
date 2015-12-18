#include<bits/stdc++.h>
using namespace std ;

struct Point {
    double x ,y ;
    Point (double x=0 ,double y=0 ):x(x),y(y){ }
    Point operator + (const Point &p )const{
        return Point (x+p.x,y+p.y) ;
    }
    Point operator - (const Point &p )const{
        return Point (x-p.x,y-p.y) ;
    }
    Point operator * (const double &d )const{
        return Point (x*d,y*d) ;
    }
    bool operator < (const Point &p )const {
        if (x!=p.x)return x<p.x ;
        return y>p.y ;
    }
};
double cross(const Point &a ,const Point &b ){
    return a.x*b.y-a.y*b.x ;
}

const double EPS = 1E-8 ;
void cover_hall(vector<Point> &S ){
    vector<Point> re ; int sz=0 ;
    sort(S.begin(),S.end()) ;
    int n = S.size() ;

    for (int i=0 ;i<n ;i++ ){
        while (sz>=2 && cross(re[sz-1]-re[sz-2],S[i]-re[sz-1])+EPS >=0){
            re.pop_back() ; sz-- ;
        }
        re.push_back(S[i]) ;sz++ ;
    }
    S.clear() ;
    for (auto p:re)S.push_back(p) ;
}

vector<Point> S ;

int main(){
    //input -----------------
    int n ,p ,q ;
    cin >> n >> p >> q ;

    S.resize(n) ;
    double mx=0 ,my=0 ;
    for (auto &p:S){
        scanf("%lf%lf",&p.x ,&p.y ) ;
        mx=max(mx,p.x) ;
        my=max(my,p.y) ;
    }
    S.push_back(Point(0,my)) ;
    S.push_back(Point(mx,0)) ;

    //find ------------------
    cover_hall(S) ;
    Point P(p,q) ;

    Point vl = S[0] ,vr = S[S.size()-1];
    for (int i=0 ;cross(S[i],P)-EPS<=0 ;i++ )vl=S[i] ;
    for (int i=S.size()-1 ;cross(S[i],P)+EPS>=0 ;i-- )vr=S[i] ;

    //output ----------------
    for (int i=0 ;i<200 ;i++ ){
        Point vm = (vl+vr)*0.5 ;
        if (cross(vm,P)+EPS<=0)vl=vm ;
        else vr=vm ;
    }
    printf("%f\n",P.x/vl.x) ;
}
