#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MAXN = 10004;
const int INF = 1<<29;

int N,cap;
vector<int> G[MAXN];

void input(){
    cap=INF;

    scanf("%d",&N);
    for (int i=0, l, r; i<N; i++){
        scanf("%d %d", &l, &r);
        r--;
        cap=min(cap,r-l+1);
        G[l].push_back(r);
    }
}

bool ok(int t){
    if (t==0)return 1;

    priority_queue< pii, vector<pii>, greater<pii> > que;
    for (int i=0; i<MAXN; i++){
        for (int r:G[i]){
            que.push( pii(r-t,t) );
        }
        if (que.empty())continue;
        pii ele = que.top(); que.pop();
        ele.first++;
        ele.second--;
        if (i>ele.first)return 0;

        if (ele.second>0)que.push(ele);
    }
    return 1;
}

int main(){
    input();
    int l=0, r=cap+1;
    while (l!=r){
        int mid=(l+r)>>1;
        if ( ok(mid) )l=mid+1;
        else r=mid;
    }
    printf("%d\n",(r-1)*N);
}
