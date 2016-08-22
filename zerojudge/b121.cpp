#include<stdio.h>
#include<set>
#include<string>
using namespace std ;

int d[][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}} ;

int check_win(char *s ){
    int re=0 ;
    for (int i=0 ;i<8 ;i++ )
        if (s[ d[i][0] ]=='O' && s[ d[i][1] ]=='O' && s[ d[i][2] ]=='O')
            re++ ;
    for (int i=0 ;i<8 ;i++ )
        if (s[ d[i][0] ]=='X' && s[ d[i][1] ]=='X' && s[ d[i][2] ]=='X')
            re-- ;
    if (re>0)return 1 ;
    if (re==0)return 0 ;
    if (re<0)return -1 ;
}

set<string> U ;
int W ,L ,E ;
void DFS(char *s ,char c ,char nc ){
    bool ok =0;
    for (int i=0 ;i<9 && !ok ;i++ )if (s[i]=='-')ok=1 ;

    if (ok==0 || check_win(s)!=0 ){
        int l=U.size() ;
        U.insert((string)s) ;
        if (l==U.size())return ;
        int val=check_win(s) ;
        if (val==1)W++ ;
        if (val==0)E++ ;
        if (val==-1)L++ ;
    }
    else {
        for (int i=0 ;i<9 ;i++ )if (s[i]=='-'){
            ok=1 ;
            s[i]=c ;
            DFS(s,nc,c) ;
            s[i]='-' ;
        }
    }
}

int main(){
    char s[10] ;

    while (~scanf("%s",s )){
        U.clear() ;
        W=L=E=0 ;

        int d=0 ;
        for (int i=0 ;i<9 ;i++ ){
            if (s[i]=='O')d++ ;
            if (s[i]=='X')d-- ;
        }
        if (d==1)DFS(s,'X','O') ;
        else DFS(s,'O','X') ;

        printf("%d %d %d %d\n",W+L+E ,W ,L ,E ) ;
    }
}
