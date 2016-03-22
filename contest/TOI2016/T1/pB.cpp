#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
const int maxn = 100030 ;
int W ,H ,n ;
LL ans=0 ;
vector< pair<int,int> > IN[maxn] ,OUT[maxn] ;

int cnt=0 ;
LL BIT[2][maxn] ;
void add (LL b[] ,int pos ,int val ){
    while (pos<H+10){
        b[pos]+=(LL)val ;
        pos+=(pos&(-pos)) ;
    }
}
LL sum(LL b[] ,int pos ){
    LL re=0 ;
    while (pos>0){
        re+=b[pos] ;
        pos-=(pos&(-pos)) ;
    }
    return re ;
}
LL query(LL b[],int l ,int r){
    return sum(b,r)-sum(b,l-1) ;
}
int main(){
    scanf("%d%d%d",&W ,&H ,&n ) ;
    for (int x ,y ,X ,Y ,i=0 ;i<n ;i++ ){
        scanf("%d%d%d%d",&x ,&y ,&X ,&Y ) ;
        x ,y++ ,X ,Y ;
        IN [x].push_back(make_pair(y,Y)) ;
        OUT[X].push_back(make_pair(y,Y)) ;
    }
    ans = 0 ;
    for (int i=0 ;i<W ;i++ ){
        for (auto r:OUT[i]){
            int y = r.first ,Y = r.second ;
            add(BIT[0],y,-1) ,add(BIT[1],Y,-1) ;
            cnt-- ;
        }
        for (auto r:IN[i]){
            int y = r.first ,Y = r.second ;
            ans+=cnt-query(BIT[1],0,y-1)-query(BIT[0],Y+1,H+1) ;
            add(BIT[0],y,1) ,add(BIT[1],Y,1) ;
            cnt++ ;
        }
    }
    cout << ans <<endl ;
}
/*
6 4
3
0 0 2 2
1 3 5 4
4 1 6 3

6 4
3
0 0 2 2
1 3 5 4
4 1 6 4
*/
