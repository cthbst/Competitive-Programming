#include<iostream>
#include<string.h>
#include<sstream>
#include<stack>
using namespace std ;

typedef long long int LL ;
stack<char> opt ;
stack< LL > val ;

bool is_int(char *s){
    return '0' <= s[0] && s[0] <= '9' ;
}
int  get_int(char *s){
    int re=0 ;
    for (int i=0 ;s[i];i++)re=10*re+s[i]-'0' ;
    return re ;
}
void do_opt(){
    char o = opt.top() ; opt.pop() ;
    if (o=='(' || o==')'){
        puts("do_opt() error") ;
        return ;
    }
    LL b = val.top() ; val.pop() ;
    LL a = val.top() ; val.pop() ;
    if (o=='+')val.push(a+b) ;
    else if (o=='-')val.push(a-b) ;
    else if (o=='*')val.push(a*b) ;
    else if (o=='/')val.push(a/b) ;
    else if (o=='%')val.push(a%b) ;
}

int main(){
    int pri[256] ;
    pri['*']=pri['/']=pri['%']=1 ;
    pri['+']=pri['-']=2 ;
    pri['(']=pri[')']=3 ;

    char input_line[10000] ;
    stringstream ss ;

    while (cin.getline(input_line,sizeof(input_line))){
        if (strlen(input_line)==0)continue ;
        ss.clear() ;
        ss <<"( " << input_line <<" )" ;
        char e[20] ;
        while (ss>>e){
            if (is_int(e)){
                val.push(get_int(e)) ;
            }
            else {
                char o = e[0] ;
                if (o=='('){
                    opt.push(o) ;
                }
                else if (o==')'){
                    while (opt.top()!='(')do_opt() ;
                    opt.pop() ;
                }
                else {
                    while (pri[opt.top()]<=pri[o])do_opt() ;
                    opt.push(o) ;
                }
            }
        }
        cout <<val.top()<< endl ;
        val.pop() ;
        if (!opt.empty())puts("opt not empty!") ;
        if (!val.empty())puts("val not empty!") ;
    }
}
