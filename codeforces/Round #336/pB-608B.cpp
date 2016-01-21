#include<bits/stdc++.h>
using namespace std ;

const int maxn = 200030 ;
char a[maxn] ,b[maxn] ;

int main(){
    scanf("%s%s",a,b) ;
    int la = strlen(a) ,lb=strlen(b) ;

    long long ans=0 ,sum=0 ;
    for (int i=0 ;i<=lb-la ;i++ )sum+=b[i]-'0' ;
    for (int i=0 ;i<la ;i++ ){
        if (a[i]=='0')ans+=sum ;
        else ans+=lb-la+1-sum ;
        sum+=b[lb-la+i+1]-'0' ;
        sum-=b[i]-'0' ;
    }
    cout << ans <<endl ;
}
