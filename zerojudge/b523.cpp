#include<bits/stdc++.h>
using namespace std ;

unordered_map<string,bool> S ;

int main(){
    string s ;
    while (getline(cin,s)){
        auto &p = S[s] ;
        puts(p!=1?"NO":"YES") ;
        p=1 ;
    }
}
