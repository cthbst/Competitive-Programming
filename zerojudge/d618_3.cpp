#include<stdio.h>

char G[30][30] ;
int dx[]={1,0,-1,0} ,dy[]={0,1,0,-1} ;

bool is_aph(char a){
    if ('A'<=a && a<='Z')return 1 ;
    return 0 ;
}

int main(){
    int T ,R ,C ,Q ;scanf("%d",&T ) ;

    while (T-- && scanf("%d%d",&R ,&C )){
        for (int i=0 ;i<R ;i++ )scanf("%s",G[i]) ;

        //solve -------------
        scanf("%d",&Q ) ;
        char in[2] ,S ;

        while (Q-- && scanf("%s",in )){
            S=in[0] ;
            //find start ----
            int x , y ;
            for (int i=0 ;i<R ;i++ ){
                for (int j=0 ;j<C ;j++ ){
                    if (G[i][j]==S)x=i ,y=j ;
                }
            }

            int lx=x ,ly=y ,a ,b ;
            if      (x+1<R  && (G[x+1][y]=='|' || G[x+1][y]=='#' || G[x+1][y]=='+'))x=x+1,y=y ;
            else if (0<=x-1 && (G[x-1][y]=='|' || G[x-1][y]=='#' || G[x-1][y]=='+'))x=x-1,y=y ;
            else if (y+1<C  && (G[x][y+1]=='-' || G[x][y+1]=='#' || G[x][y+1]=='+'))x=x,y=y+1 ;
            else if (0<=y-1 && (G[x][y-1]=='-' || G[x][y-1]=='#' || G[x][y-1]=='+'))x=x,y=y-1 ;

            //walk ----------
            int nx ,ny ;
            while (!is_aph(G[x][y])){
                if (G[x][y]=='#'||G[x][y]=='|'||G[x][y]=='-'){
                    nx=x*2-lx ;ny=y*2-ly ;
                }
                //+ ---------
                else {
                    if      (lx==x && x+1 <R && ((is_aph(G[x+1][y]) && G[x+1][y]!=S) || G[x+1][y]=='+' || G[x+1][y]=='#' || G[x+1][y]=='|'))nx=x+1 ,ny=y ;
                    else if (lx==x && 0<=x-1 && ((is_aph(G[x-1][y]) && G[x-1][y]!=S) || G[x-1][y]=='+' || G[x-1][y]=='#' || G[x-1][y]=='|'))nx=x-1 ,ny=y ;
                    else if (ly==y && y+1 <C && ((is_aph(G[x][y+1]) && G[x][y+1]!=S) || G[x][y+1]=='+' || G[x][y+1]=='#' || G[x][y+1]=='-'))nx=x ,ny=y+1 ;
                    else if (ly==y && 0<=y-1 && ((is_aph(G[x][y-1]) && G[x][y-1]!=S) || G[x][y-1]=='+' || G[x][y-1]=='#' || G[x][y-1]=='-'))nx=x ,ny=y-1 ;
                }
                lx=x,ly=y ;
                x=nx,y=ny ;
            }
            //output --------
            printf("%c->%c\n",S ,G[x][y] ) ;
        }
        puts("") ;
    }

}
