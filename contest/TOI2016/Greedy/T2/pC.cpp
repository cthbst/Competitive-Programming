#include<bits/stdc++.h>
using namespace std ;

vector<long long> a ,b ;
string s ;
void input(vector<long long> &v ){
    getline(cin,s) ;
    stringstream ss ; ss << s;
    v.clear() ;
    long long e ;
    while (ss>>e)v.push_back(e*e) ;
}

void solve(){
    input(a) ,input(b) ;
    int n = a.size() ;
    sort(a.begin(),a.end()) ;
    sort(b.begin(),b.end(),greater<long long>()) ;
    double ans=0.0 ;
    for (int i=0 ;i<n ;i++ ){
        ans += sqrt( (double) (a[i]+b[i]) ) ;
    }

    printf("%d\n",(int)ans) ;
}

int main(){
    int T ; scanf("%d",&T ) ;
    getline(cin,s) ;
    while (T--)solve() ;
}


