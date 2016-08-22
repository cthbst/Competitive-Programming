#include<stdio.h>
#include<set>
#include<queue>
using namespace std ;

int main(){
    int T ,N ;
    scanf("%d",&T ) ;
    while (T-- && scanf("%d",&N ) ){
          priority_queue<int> que ;
          for (int i=0 ,in;i<N ;i++ ){
              scanf("%d",&in) ;
              que.push(in) ;
          }
          
          set<int> S ;
          while (!que.empty() ){
                int t =que.top() ,l=S.size() ;
                que.pop() ;
                S.insert(t*2) ;
                if (S.size()==l )S.insert(t) ;               
          }
          
          printf("%d\n",S.size() ) ;
    }
}
