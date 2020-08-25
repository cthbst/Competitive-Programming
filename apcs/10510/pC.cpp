#include <bits/stdc++.h>
using namespace std;

// 計算 x % m, 但 m % m = m
int mod(int x, int m){
    x%=m;
    if (x<=0) x+=m;
    return x;
}

int main(){
    int n ,m ,k;
    cin >> n >> m >> k;
    
    int w=1;
    for (int i=n-k+1; i<=n; i++){
        w = mod(m+w,i); // 到下一層的 index 
    }

    cout << w << '\n';
}
