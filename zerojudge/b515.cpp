#include<bits/stdc++.h>
using namespace std ;

string S[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
map<string,char> lib ;

string ins ;
int main(){
    for (int i=0 ;i<26 ;i++ )
        lib[ S[i] ]='A'+i ;
    int T ;cin >>T ;
    getline(cin,ins) ;
    while (T-- && getline(cin,ins) ){
        stringstream ss ;
        ss <<ins ;
        string c ;
        while (ss>>c){
            cout <<lib[c] ;
        }
        cout <<endl ;
    }
}
