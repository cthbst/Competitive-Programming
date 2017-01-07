#include <bits/stdc++.h>
using namespace std;

void solve(){
    static int n;
    static vector<int> a;

    cin >> n;
    a.resize(n);
    for (auto &e:a)cin >> e;
    sort(a.begin(),a.end());

    int ans=0;
    for (int i=0, j=n-1; i<j; j--){
        int cnt=1;
        while (i<j && cnt*a[j]<50){
            i++;
            cnt++;
        }
        if (cnt*a[j]>=50)ans++;
    }
    cout << ans;
}

int main(){
    freopen("lazy_loading.txt","r",stdin);
    freopen("pB.out","w",stdout);
    int T;
    scanf("%d",&T);

    for (int t=1; t<=T; t++){
        printf("Case #%d: ", t);
        solve();
        printf("\n");
    }
}
