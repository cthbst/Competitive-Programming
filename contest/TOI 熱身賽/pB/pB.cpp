#include<bits/stdc++.h>
using namespace std ;

const int base=8 ;
const int D = 100000000 ;

struct Big_number{
    vector<int> a ;
    Big_number (int x=0){
        a.resize(0) ;
        a.push_back(x) ;
    }
    Big_number operator + (const Big_number &B )const {
        Big_number re(0) ;
        re.a.resize(max(a.size() ,B.a.size())+1) ;
        fill (re.a.begin(),re.a.end(),0) ;
        for (int i=a.size()-1 ;i>=0 ;i-- )
            re.a[i]+=a[i] ;
        for (int i=B.a.size()-1 ;i>=0 ;i-- )
            re.a[i]+=B.a[i] ;
        int sz = re.a.size() ;
        for (int i=0 ;i<sz-1 ;i++ )
            if (re.a[i]>=D)re.a[i+1]++ ,re.a[i]-=D ;
        if (re.a[sz-1]==0)re.a.pop_back() ;
        return re ;
    }
    string output(){
        char s[10000] ;
        int sz = a.size()-1 ;
        sprintf(s,"%d",a[sz--]) ;
        while (sz>=0)sprintf(s,"%s%08d",s,a[sz--]) ;
        return (string)s ;
    }
}a[3];

int n ;


int main(){
    int T ;cin >> T ;

    while (T-- && cin >> n ){
        if (n<2){
            puts("1") ;
            continue ;
        }
        a[0]=a[1]=Big_number(1) ;
        for (int i=0 ,j=1 ,k=2 ;k<=n ;k++ ,i=(i+1)%3,j=(j+1)%3){
            a[k%3]=a[i]+a[j] ;
        }
        cout << a[n%3].output() <<endl ;
    }
}

