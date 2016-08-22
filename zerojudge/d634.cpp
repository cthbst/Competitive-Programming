#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int Trie[1000000][63] ,cnt=1 ;
int tag[1000000] ;
int trans[128] ;
char detrans[63] ;

char now[100] ;
void output(int x ,int floor){
    while (tag[x]--)puts(now) ;
    for (int i=0 ;i<63 ;i++ )if (Trie[x][i]!=-1){
        now[floor]=detrans[i] ;
        output(Trie[x][i],floor+1) ;
    }
    now[floor]=0 ;
}

int main(){
    //set trans -------------
    {
        int c=0 ;
        detrans[c]=' ' ,trans[' ']=c++ ;
        for (int i=0 ;i<10 ;i++ )detrans[c]='0'+i ,trans['0'+i]=c++ ;
        for (int i=0 ;i<26 ;i++ )detrans[c]='A'+i ,trans['A'+i]=c++ ;
        for (int i=0 ;i<26 ;i++ )detrans[c]='a'+i ,trans['a'+i]=c++ ;
    }
    //solve -----------------
    memset(Trie,-1,sizeof(Trie)) ;
    memset(tag,0,sizeof(tag)) ;

    int N ;
    scanf("%d",&N ) ;
    char s[20] ;
    cin.getline(s,20);
    for (int i=0 ;i<N ;i++ ){
        cin.getline(s,20);
        int w=0 ;
        for (int j=0 ,len=strlen(s);j<len ;j++ ){
            if (Trie[w][trans[s[j]]]==-1)
                Trie[w][trans[s[j]]]=cnt++ ;
            w=Trie[w][trans[s[j]]] ;
        }
        tag[w]++ ;
    }
    //output ----------------
    memset(now,0,sizeof(now)) ;
    output(0,0) ;
}
