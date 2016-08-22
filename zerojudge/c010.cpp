#include<stdio.h>
#include<queue>
using namespace std;

priority_queue<int> large ,small ;

int main(){
    int n ,cnt=0 ;
    while (~scanf("%d",&n)){
        cnt++ ;
        if ((cnt%2)==1)large.push(-n) ;
        else small.push(n) ;
        while (!large.empty() && !small.empty() && -large.top()<small.top() ){
            int a= -large.top() ,b=small.top() ;
            large.pop() ;
            small.pop() ;
            large.push(-b) ;
            small.push(a) ;
        }
        if ((cnt&1)==1){
            printf("%d\n",-large.top()) ;
        }
        else {
            printf("%d\n",(small.top()-large.top())/2 ) ;
        }
    }
}
