#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std ;

int main(){
    priority_queue<int ,vector<int> ,greater<int> > que ;

    int N ,M ;
    scanf("%d%d",&N ,&M ) ;
    for  (int i=0 ;i<M ;i++ )que.push(0) ;

    int ans=0 ;
    for (int i=0 ,wi ;i<N ;i++ ){
        scanf("%d",&wi ) ;
        wi+=que.top() ;
        que.pop() ;
        ans=max(ans,wi) ;
        que.push(wi) ;
    }
    printf("%d\n",ans) ;
}
