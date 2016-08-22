#include<stdio.h>
#include<vector>
using namespace std ;

typedef long long int LL ;

LL g(LL z ){
    if (z<=2)return z*z-1 ;
    else return 2 ;
}

vector<LL>H ;
LL h(LL y ){
    if (y<2 )return -1 ;

    for (int i=H.size() ;i<=y ;i++ ){
        H.push_back(0) ;
        H[i]=2+H[i-1]-H[i-2] ;
    }
    return H[y] ;
}
LL f(LL x ){
    if (x>h(x))return f(x-1)-h(x) ;
    else if (x<h(x))return f(g(x))-g(x) ;
    else return 1 ;
}


int main(){
    H.push_back(-1) ;//H[0]
    H.push_back(-1) ;//H[1]

    int N ;
    while (~scanf("%d",&N )){
        printf("%d\n",f(N)) ;
    }
}
