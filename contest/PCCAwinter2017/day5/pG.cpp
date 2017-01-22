#include <cstdio>
using namespace std;
int main()
{
    int num[1005], n, q, a, b, T, ans;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i++) scanf("%d", &num[i]);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &a, &b);
            ans = num[a];
            for(int i = a+1 ; i <= b ; i++) if(num[i] > ans) ans = num[i];
            printf("%d\n", ans);
        }
    }
}
