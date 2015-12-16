#include<bits/stdc++.h>
using namespace std ;


typedef pair<int,int> PII ;
priority_queue< PII ,vector<PII> ,greater<PII> > pq ;

#define l first
#define r second

int main(){
    int n ,m ;
    cin >> n >> m  ;

	//input -----------------
    for (int i=0 ,l ,r ;i<m ;i++ ){
		scanf("%d%d",&l ,&r ) ;
		pq.push( make_pair(l,r) ) ;
    }

    //solve -----------------
    int ans = 0 ;

    while (pq.size()>1){
        auto a = pq.top() ; pq.pop() ;
        auto b = pq.top() ; pq.pop() ;
        if ( a.r<b.l ){ //a.l<=a.r<b.l<=b.r
			ans += a.r-a.l+1 ;
			pq.push(b) ;
        }
        else if (b.l<=a.r && a.r<=b.r ){ 	//a.l<=b.l<=a.r<=b.r
            ans += b.l-a.l ;
            if (a.r+1<=b.r)pq.push(make_pair(a.r+1,b.r)) ;
        }
        else { // a.l<=b.l<=b.r<a.r
			ans += b.l-a.l ;
            pq.push(make_pair(b.r+1,a.r)) ;
        }
    }

	if (!pq.empty()){
		auto a = pq.top() ; pq.pop() ;
		ans += a.r-a.l+1 ;
	}

    //output ----------------
    cout << n - ans <<endl ;
}
