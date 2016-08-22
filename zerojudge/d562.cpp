#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;
vector<int> a ;

int main(){
    int n ;
    while (~scanf("%d",&n)){
		a.resize(n) ;
		for (int &x:a)scanf("%d",&x) ;
		for (int i=0 ;i<n ;i++ ){
			for (int x:a)printf("%d ",x) ;
			puts("") ;
			reverse(a.begin(),a.end()) ;
			a.pop_back() ;
		}
		puts("") ;
    }
}
