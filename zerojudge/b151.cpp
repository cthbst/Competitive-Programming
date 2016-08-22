#include<stdio.h>
#include<queue>
using namespace std ;

int main(){
    int n ;
    while (~scanf("%d",&n )){
          priority_queue<int,vector<int>,greater<int> > que ;
          int sum=0 ;
          //input------------------------------------------
          for (int i=0,input ;i<n ;i++ ){
              scanf("%d",&input) ;
              que.push( input ) ;
          }
          //cooking----------------------------------------
          int ans=0 ,s ;
          while (que.size()>1 ){
                s=que.top() ; que.pop() ;
                s+=que.top() ;que.pop() ;
                que.push(s) ;
                ans+=s ;
          }
          //output-----------------------------------------
          printf("%d\n",ans ) ;
    }
}
