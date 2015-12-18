#include<bits/stdc++.h>
using namespace std ;

struct str{
    int u ,v ,id ;
    str (int u=0,int v=0 ,int id=0 ):u(u),v(v),id(id){}
};
bool cmp1(str a ,str b){
    if (a.u!=b.u)return a.u<b.u ;
    if (a.v!=b.v)return a.v>b.v ;
    return a.id<b.id ;
}

vector< str > edge ;
vector< pair<int,int> > ans ;
queue< pair<int,int> > can_use ;

int main(){
    //input -----------------
    int n ,m ;
    cin >> n >> m ;

    edge.resize(m) ;
    ans.resize(m) ;
    for (int i=0 ;i<m ;i++ ){
        auto &e = edge[i] ;
        scanf("%d%d",&e.u ,&e.v ) ;
        e.id = i ;
    }

    //build -----------------
    sort(edge.begin(),edge.end(),cmp1) ;

    bool ok=1 ;
    int cnt=1 ;
    for (auto e:edge){
        if (e.v==1){
            ans[ e.id ]=make_pair(cnt,cnt+1) ;
            //ans.push_back(make_pair(cnt,cnt+1)) ;
            cnt++ ;
            for (int i=cnt-2 ;i>=1 && can_use.size()<m;i-- ){
                can_use.push(make_pair(i,cnt)) ;
            }
        }
        else {
            if (can_use.empty()){
                ok=0 ;
                break ;
            }
            ans[ e.id ]=can_use.front() ;
            can_use.pop() ;
        }
    }
    //output ----------------
    if (!ok)puts("-1") ;
    else {
        for (auto e:ans ){
            printf("%d %d\n",e.first ,e.second ) ;
        }
    }
}
