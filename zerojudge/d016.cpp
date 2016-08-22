#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<sstream>
#include<stack>
using namespace std ;

stack<string> sta ;

int to_int(const char *a){
    int re ;
    sscanf(a,"%d",&re) ;
    return re ;
}
int dfs(){
	string w = sta.top() ;sta.pop() ;
    if ( '0'<=w[0] && w[0]<='9' ){
		return to_int(w.c_str()) ;
    }
    else {
        int b= dfs() ;
        int a= dfs() ;
        if (w[0]=='+')return a+b ;
        if (w[0]=='-')return a-b ;
        if (w[0]=='*')return a*b ;
        if (w[0]=='/')return a/b ;
        if (w[0]=='%')return a%b ;
    }
}

char in[10000] ;
int main(){
    while (cin.getline(in,sizeof(in))){
        stringstream s ;
        s<<in ;
        string e ;
        while (s>>e)sta.push(e) ;
        printf("%d\n",dfs()) ;
    }
}
