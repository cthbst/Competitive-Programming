#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std ;

struct Object{
    string s ; int val ;
    int pri ,t ;

    bool operator > (const Object &B )const {
        if (pri!=B.pri)return pri>B.pri ;
        return t>B.t ;
    }
};

priority_queue< Object ,vector<Object> ,greater<Object> > que ;

int main(){
    int time=0 ;
    char cmd[10] ;

    while (~scanf("%s",cmd)){
        if (strcmp(cmd,"PUT")==0){
            string s ; int val ,pri ;
            cin >> s >> val >> pri ;
            que.push( Object{s,val,pri,time++} ) ;
        }
        else {
            if (que.size()==0){
                puts("EMPTY QUEUE!") ;
                continue ;
            }
            Object u = que.top() ; que.pop() ;
            cout << u.s <<" " << u.val <<endl ;
        }
    }
}
