#include<bits/stdc++.h>
using namespace std ;

const int maxn = 100000 ;
int n ,a[maxn] ;

int main(){
    cin >> n ;
    int sum=0 ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%d",a+i) ;
        sum+=a[i] ;
    }
    int l = sum/n ,r = sum/n + (sum%n==0,0,1);
    int sl=0 ,sr=0 ;
    for (int i=0 ;i<n ;i++ ){
        if (a[i]<l)sl+=l-a[i] ,a[i]=l ;
        if (a[i]>r)sr+=a[i]-r ,a[i]=r ;
    }
    cout << max(sl,sr) <<endl ;
}
