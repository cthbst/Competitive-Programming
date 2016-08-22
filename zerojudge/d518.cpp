#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std ;

struct str{int son[26] ;};

struct Trie{
    //member ----------------
    vector<str> ch ;
    vector<int> val ;
    str OO ;
    int num ;
    //init ------------------
    Trie (){
        memset(OO.son ,0 ,sizeof(OO.son )) ;
    }
    void init (){
        ch.clear() ;
        ch.push_back(OO) ;
        val.clear() ;
        val.push_back(0) ;
        num=1 ;
    }
    //insert ----------------
    void insert(char *s ){
        int len=strlen(s) ,w=0 ;

        for (int i=0 ;i<len ;i++ ){
            int c =s[i]-'a' ;

            if (ch[w].son[c]==0){
                ch[w].son[c]=ch.size() ;
                ch.push_back(OO) ;
                val.push_back(0) ;
            }

            w=ch[w].son[c] ;
        }

        if (val[w]==0){
            printf("New! %d\n",num) ;
            val[w]=num++ ;
        }
        else {
            printf("Old! %d\n",val[w]) ;
        }
    }

} ;

Trie trie ;
int main(){
    int N ;
    char in[30] ;
    while (~scanf("%d",&N ) ){
        trie.init() ;

        for (int i=0 ;i<N ;i++ ){
            scanf("%s",&in) ;
            trie.insert(in) ;
        }
    }
}
