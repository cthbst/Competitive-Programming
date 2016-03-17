#include<bits/stdc++.h>
using namespace std ;

#define debug 0
const int maxn = 500000+5 ;
int N ,Q ,M ;

struct str{ int r ,h ,cnt ; };
struct Point { int a ,b ;
    bool operator < (const Point B)const{
        return a!=B.a?a<B.a:b<B.b ;
    }
}p[maxn];

struct SEG{ int sz ; SEG *lc ,*rc ;
    SEG ():sz(0),lc(nullptr),rc(nullptr){}
}*root[maxn] ;
void build(SEG* &o ,int l=1 ,int r=N ){
    o = new SEG() ;
    if (l==r)return ;
    int m=(l+r)>>1 ;
    build(o->lc,l,m) ;
    build(o->rc,m+1,r) ;
}
void update(SEG* &a ,SEG* &b ,int x ,int l=1 ,int r=N ){
    b=new SEG() ;
    if (l==r){
        b->sz=a->sz+1 ;
        return ;
    }
    b->lc=a->lc,b->rc=a->rc ;
    int m = (l+r)>>1 ;
    if (x<=m)update(a->lc,b->lc,x,l,m) ;
    else update(a->rc,b->rc,x,m+1,r) ;
    b->sz=b->lc->sz+b->rc->sz ;
}
inline int lower_bound(int pos ){
    int l=0 ,r=N+1 ;
    while (l!=r){
        int m=(l+r)>>1 ;
        p[m].a<pos?l=m+1:r=m ;
    }
    return l-1 ;
}
int query(SEG *s ,SEG *t ,int L ,int R ,int l=1 ,int r=N ){
    if (L<=l && r<=R )return t->sz-s->sz;
    int m = (l+r)>>1 ,re=0 ;
    if (L<=m)re+=query(s->lc,t->lc,L,R,l,m) ;
    if (m< R)re+=query(s->rc,t->rc,L,R,m+1,r) ;
    return re ;
}
inline int query(int x ,int X ,int y=1 ,int Y=N ){
    if (x>X || y>Y )return 0 ;
    x=lower_bound(x) ,X=lower_bound(X+1) ;
    return query(root[x],root[X],y,Y) ;
}
int kth(SEG *s ,SEG *t ,int k ,int l=1 ,int r=N ){
    if (l==r)return l ;
    int m = (l+r)>>1 ,cnt = t->lc->sz-s->lc->sz ;
    if (k<=cnt)return kth(s->lc,t->lc,k,l,m) ;
    return kth(s->rc,t->rc,k-cnt,m+1,r) ;
}
inline int kth (int x ,int X ,int k){
    if (x>X)swap(x,X) ;
    x=lower_bound(x) ,X=lower_bound(X+1) ;
    return kth(root[x],root[X],k) ;
}

int qnt=0 ;
map<int,int> Ks ;
inline bool solveQ(){
    //input -----------------
    Ks.clear() ;
    scanf("%d",&M) ;
    int Ksum=0 ;
    for (int i=0 ,ki ;i<M ;i++ ){
        scanf("%d",&ki) ;
        Ks[ki]+=ki ;
        Ksum+=ki ;
    }
    if (Ksum>N)return 0 ;
    //if (qnt!=75)return 0 ;
    //stack -----------------
    stack<str> sta ;
    sta.push((str){0,N+1,0}) ;

    for (auto Ke:Ks){
        #if debug
        printf("%d*%d ",Ke.first ,Ke.second/Ke.first ) ;
        #endif
        int H=Ke.first ,R=Ke.first ,sz=Ke.second ;
        while (sta.top().h<H)sta.pop() ;
        while (sta.size()>1){
            int delta = query(sta.top().r+1,R,H,sta.top().h-1) ;
            if (delta>=sz)break ;
            str t = sta.top() ; sta.pop() ;
            sz+= t.cnt-query(sta.top().r+1,t.r,1,t.h-1)-delta ;
            H=t.h ;
        }
        if (sta.size()==1 && query(1,R,H,N)<sz)return 0 ;

        str Add{R,0,0} ;
        int r = sta.top().r+1 ;
        //printf("sz=%d\n",sz ) ;
        Add.cnt = query(r,R,1,H-1)+sz ;
        Add.h = kth(r,R,Add.cnt) ;
        if (query(r,R,0,Add.h)<Add.cnt)return 0 ;
        #if debug
        printf("(l=%d,R=%d)cnt=%d h=%d\n",sta.top().r+1,R,Add.cnt ,Add.h) ;
        #endif
        sta.push(Add) ;
    }
    #if debug
        puts("") ;
    #endif // debug
    return 1 ;
}


#if debug
void show(SEG* a ,int l ,int r ){ int mid = (l+r)>>1 ; if (l==r) printf("%d",a->sz) ; else show(a->lc,l,mid) ,show(a->rc,mid+1,r ) ; }
void show(SEG *a){ show(a,1,N) ; puts("") ; }
#endif

void solve(){
    //input -----------------
    scanf("%d",&N ) ;
    p[0].a=0 ,p[N+1].a=N+1 ;
    for (int i=1 ;i<=N ;i++ )scanf("%d%d",&p[i].a ,&p[i].b) ;

    //build segment tree ----
    sort(p+1,p+N+1) ;
    build(root[0]) ;
    for (int i=1 ;i<=N ;i++ ){
        update(root[i-1],root[i],p[i].b) ;
    }

    #if debug
    puts("input -----------------------") ;
    map< pair<int,int> ,int > cnt ;
    for (int i=1 ;i<=N ;i++ )cnt[ make_pair(p[i].a,p[i].b) ]++ ;
    //for (int i=1 ;i<=N ;i++ )printf("p[%3d] ( %2d , %2d )\n",i ,p[i].a ,p[i].b ) ;
    for (auto x:cnt){
        printf("[%2d,%2d] * %2d\n",x.first.first,x.first.second,x.second) ;
    }
    puts("roots -----------------------") ;
    //for (int i=0 ;i<=N ;i++ )printf("root[%d] :",i ) ,show(root[i]) ;
    //puts("test query ------------------") ;
    //printf("%d\n",query(root[0],root[4],1,N)) ;
    //printf("%d\n",query(1,N,1,N/2)) ;
    //puts("test kth --------------------") ;
    //for (int i=1 ;i<=N ;i++ )printf("%dth = %d\n",i ,kth(1,N,i)) ;
    #endif // debug

    //query -----------------
    scanf("%d",&Q ) ;
    while (Q--)printf("%d\n",solveQ()) ;
    //while (Q-- && ++qnt )printf("%d %d\n",qnt ,solveQ()) ;
    /*
    while (Q-- && ++qnt){
        int reans=solveQ() ;
        if (qnt!=75)continue ;
        printf("%d\n",reans) ;
    }
    */
}

int main(){
    //freopen("C:\\Users\\user\\Desktop\\teams\\tests\\13","r",stdin) ;
    //freopen("pC_in.txt","r",stdin) ;
    //freopen("out.txt","w",stdout) ;
    solve() ;
}
