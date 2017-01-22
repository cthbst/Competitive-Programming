#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    long long value;
    int l;
    bool walk;
    vector<int> v;
}N[10005];
long long point, ans;
int dfs(int s)
{
    int n = 1;
    N[s].walk = 0;
    point += N[s].value;
    for(int i = 0 ; i < N[s].v.size() ; i++)
    {
        int m = N[s].v[i];
        if(N[m].value && N[m].walk) n += dfs(m);
    }
    return n;
}
int main()
{
    queue <int> q;
    int T, n, e, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &e);
        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%lld", &N[i].value);
            N[i].v.clear();
            N[i].walk = 1;
        }
        while(e--)
        {
            scanf("%d %d", &a, &b);
            if(a == b) continue;
            N[a].v.push_back(b);
            N[b].v.push_back(a);
        }
        while(!q.empty()) q.pop();
        for(int i = 1 ; i <= n ; i++)
        {
            N[i].l = N[i].v.size();
            if(N[i].l < 2) q.push(i);
        }
        while(!q.empty())
        {
            a = q.front();
            q.pop();
            N[a].value = 0;
            for(int i  = 0 ; i < N[a].v.size() ; i++)
            {
                b = N[a].v[i];
                N[b].l--;
                if(N[b].l < 2 && N[b].value) q.push(b);
            }
        }
        ans = 0;
        for(int i = 1 ; i <= n ; i++) if(N[i].value && N[i].walk){point = 0; if(dfs(i)%2) ans += point;}
        printf("%lld\n", ans);
    }
    return 0;
}
