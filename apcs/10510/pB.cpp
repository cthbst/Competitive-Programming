#include <bits/stdc++.h>
using namespace std;

const int MAXN = 22;
int n, m; // n row, m column
int t[MAXN]; // t[i] 第 i 個 row 的最大值
int S; // S: t[i] 的總和

int main(){
    // 輸入 n x m 的矩陣
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> t[i];
        for (int j=1; j<m; j++){
            int x;
            cin >> x;
            // 找到更大的數字時更新 t[i]
            if (x>t[i]) t[i]=x;
        }
    }
    
    // 計算 t[i] 的總和　S 並輸出
    S=0;
    for (int i=0; i<n; i++){
        S += t[i];
    }
    cout << S << '\n';
    
    // 計算可以被 S 整除的　t[i] 個數，如果不等於　n 就是無解
    int cnt=0;
    for (int i=0; i<n; i++){
        if ( S%t[i]==0 ){
            cnt++;
        }
    }
    if (cnt==0){
        cout << -1 << '\n';
    }
    else {　// 有解，輸出　t[i] 
        for (int i=0; i<n; i++){
            if ( S%t[i]==0 ){
                cnt--;
                cout << t[i] << (cnt>0?' ':'\n');
            }
        }
    }
}
