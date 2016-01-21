#include<bits/stdc++.h>
using namespace std ;

typedef long long int LL ;

const int maxn = 1000 ;
struct { int x ,X ,y ,Y ; } rac[maxn] ;
set<int> Xs ,Ys ;
map<int,int> Tx ,Ty ;
vector<int> xT ,yT ;

int G[maxn*4][maxn*4] ;
int XX=-1 ,YY=-1 ;

void update(int x ,int X ,int y ,int Y ){
    for (int i=x*2 ;i<X*2 ;i++ )
        G[i][y*2]++ ,G[i][Y*2]-- ;
    XX = max(XX,X) ,YY =max(YY,Y) ;
}

int main(){
    int n ; cin >> n ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%d%d%d%d",&rac[i].x ,&rac[i].y ,&rac[i].X ,&rac[i].Y) ;
        if (rac[i].x>rac[i].X)swap(rac[i].x,rac[i].X) ;
        if (rac[i].y>rac[i].Y)swap(rac[i].y,rac[i].Y) ;
        Xs.insert(rac[i].x) ,Xs.insert(rac[i].X) ;
        Ys.insert(rac[i].y) ,Ys.insert(rac[i].Y) ;
    }

    {   //Â÷´²¤Æ
        int i=0 ,j=0 ;
        xT.resize(Xs.size()) ,yT.resize(Ys.size()) ;
        for (int x:Xs)Tx[x]=i ,xT[i]=x ,i++ ;
        for (int y:Ys)Ty[y]=j ,yT[j]=y ,j++ ;
        Xs.clear() ,Ys.clear() ;
    }
    //update ----------------
    memset(G,0,sizeof(G)) ;
    for (int i=0 ;i<n ;i++ )
        update(Tx[rac[i].x],Tx[rac[i].X],Ty[rac[i].y],Ty[rac[i].Y]) ;
    //count -----------------
    LL ans=0 ;
    XX*=2 ,YY*=2 ;
    for (int i=0 ;i<=XX ;i++ ){
        for (int j=1 ;j<=YY ;j++ )G[i][j]+=G[i][j-1] ;
        for (int j=0 ;j<=YY ;j++ ){
            if (G[i][j]==0)continue ;
            int dx= (i&1)==0?1:xT[(i>>1)+1]-xT[i>>1]-1 ;
            int dy= (j&1)==0?1:yT[(j>>1)+1]-yT[j>>1]-1 ;
            ans+=(LL)dx*dy ;
            if ((j>>1)+1>=yT.size())break ;
        }
        if ((i>>1)+1>=xT.size())break ;
    }
    //output ----------------
    cout << ans <<endl ;
}
