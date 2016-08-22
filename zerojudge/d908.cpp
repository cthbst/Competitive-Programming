#include<stdio.h>
#include<string.h>

int main(){
    int d[26][26] ;
    memset(d,0,sizeof(d)) ;
    
    //start--------------------------------------
    char start[2] ;
    int s ,N ;
    scanf("%s%d",&start,&N) ;
    s=start[0]-'A' ;
    
    //input--------------------------------------
    char a[2] ,b[2] ;
    int w ;
    for (int i=0 ;i<N ;i++ ){
        scanf("%s%s%d",&a ,&b ,&w) ;
        if (w>d[a[0]-'A'][b[0]-'A'])
        d[a[0]-'A'][b[0]-'A']=w ;
    }
        
    //Floyd--------------------------------------
    for (int k=0 ; k<26 ;k++ )
        for (int i=0 ; i<26 ;i++ )
            for (int j=0 ; j<26 ;j++ )
                if ( (d[i][j]==0 || d[i][j]<d[i][k]+d[k][j] ) && d[i][k]!=0 && d[k][j]!=0 )
                   d[i][j]=d[i][k]+d[k][j] ;
    //output-------------------------------------
    int ans=0 ;
    for (int i=0 ;i<26 ;i++ )if (d[s][i]>ans)ans=d[s][i] ;
    printf("%d",ans) ;
    
}
