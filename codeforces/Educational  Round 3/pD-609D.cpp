#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;

typedef pair<int,int> PII ;
#define x first
#define y second
#define mk make_pair
const int maxn = 200000 ;
int n ,m ,k ,s ;
int a[maxn] ,b[maxn] ;
int cntd=0 ,cntp=0 ;
PII d[maxn] ,p[maxn] ;
vector<PII> ans ;
bool check(int cd ,int cp ){ // cost d , cost p
    LL sum=0 ;
    for (int i=0 ,l=0 ,r=0 ;i<k ;i++ ){
        if (l<cntd && r<cntp && (LL)d[l].x*cd<(LL)p[r].x*cp || l<cntd && r==cntp )
            sum+=(LL)d[l++].x*cd ;
        else
            sum+=(LL)p[r++].x*cp ;
    }
    return sum<=(LL)s ;
}

int main(){
    //input -----------------
    cin >> n >> m >> k >>s ;
    for (int i=0 ;i<n ;i++ )scanf("%d",a+i) ;
    for (int i=0 ;i<n ;i++ )scanf("%d",b+i) ;
    for (int i=1 ;i<n ;i++ ){
        a[i]=min(a[i],a[i-1]) ;
        b[i]=min(b[i],b[i-1]) ;
    }
    for (int i=0 ,ti ,ci ;i<m ;i++ ){
        scanf("%d%d",&ti ,&ci ) ;
        if (ti==1)d[cntd++]=mk(ci,i) ;
        if (ti==2)p[cntp++]=mk(ci,i) ;
    }
    sort(d,d+cntd) ,sort(p,p+cntp) ;

    if (check(a[n-1],b[n-1])==0){
        puts("-1") ;
        return 0 ;
    }
    //solve -----------------
    int L=0 ,R=n-1 ;
    while (L!=R){
        int M=(L+R)>>1 ;
        if (check(a[M],b[M])==1)R=M ;
        else L=M+1 ;
    }

    //output ----------------
    printf("%d\n",L+1 ) ;
    int dayd=0 ,dayp=0 ;
    while (a[dayd]>a[L])dayd++ ;
    while (b[dayp]>b[L])dayp++ ;

    int cd=a[dayd] ,cp=b[dayp] ;
    ans.clear() ;
    for (int i=0 ,l=0 ,r=0 ;i<k ;i++ ){
        if (l<cntd && r<cntp && (LL)d[l].x*cd<(LL)p[r].x*cp || l<cntd && r==cntp )
            ans.push_back( mk(d[l++].y+1 ,dayd+1) ) ;
        else
            ans.push_back( mk(p[r++].y+1 ,dayp+1) ) ;
    }
    sort(ans.begin(),ans.end()) ;
    for (int i=0 ;i<k ;i++ ){
        printf("%d %d\n",ans[i].x ,ans[i].y ) ;
    }
}
