#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std ;

map<string,int>A_time ,P_time ;
int A_size ,P_size ;
string A_name[1030] ,P_name[1030] ;

struct str{int num ,A ,P ;};
bool cmp(str a ,str b){
    if (a.P!=b.P)return a.P<b.P ;
    return a.A <b.A ;
}
str S[1030] ;

int main(){
    int N ;
    while (~scanf("%d",&N)){
        //init --------------
        A_time.clear() ;A_size=0 ;
        P_time.clear() ;P_size=0 ;
        //input -------------
        char animal[30] ,place[30] ;
        for (int i=0 ;i<N ;i++ ){
            scanf("%s%d%s",animal,&S[i].num ,place ) ;
            if (A_time[ (string)animal ]==0 ){
                A_time[(string)animal]=++A_size ;
                A_name[A_size]=(string)animal ;
            }
            if (P_time[ (string)place ]==0 ){
                P_time[(string)place ]=++P_size ;
                P_name[P_size]=(string)place ;
            }
            S[i].A= A_time[(string)animal] ;
            S[i].P= P_time[(string)place] ;
        }
        sort(S,S+N,cmp) ;
        //output ------------
        int P=1 ,c ,t ,i=0 ;

        while (P<=P_size){
            printf("%s :",P_name[P++].c_str()) ;
            do{
                printf(" %s ",A_name[ S[i].A ].c_str()) ;
                c=0 ;
                t=i ;
                while (i<N && S[i].P==S[t].P && S[i].A==S[t].A ){
                    c+=S[i].num ;
                    i++ ;
                }
                printf("%d",c ) ;
                if (i==N || S[i].P!=S[i-1].P )printf("\n") ;
                else printf(",") ;
            }while(i<N && S[i].P<P) ;
        }
    }
}
