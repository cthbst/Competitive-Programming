#include <bits/stdc++.h>
using namespace std;
int card[105], n, m, tmp;
bool c[105];
vector <int> def, atk;
int cal1()
{
    int s = 0, ans = 0;
    for(int i = 0 ; i < m ; i++)
    {
        if(s == def.size()) break;
        if(card[i] > def[s])
        {
            c[i] = 1;
            s++;
        }
    }
    if(s != def.size()) return 0;
    s =  atk.size()-1;
    for(int i = m-1 ; i > -1 ; i--)
    {
        if(s > -1 && card[i] >= atk[s] && !c[i]) {ans += card[i]-atk[s];s--;c[i] = 1;}
    }
    if(s == -1) for(int i = 0 ; i < m ; i++) if(!c[i]) ans += card[i];
    return ans;
}
int cal2()
{
    int s = 0 , ans = 0;
    for(int i = m-1 ; i > -1 ; i--)
    {
        if(s == atk.size()) break;
        if(card[i] >= atk[s])
        {
            ans += card[i] - atk[s];
            s++;
        }
    }
    return ans;
}
int main()
{
    char s[5];
    scanf("%d %d", &n, &m);
    memset(c, 0, sizeof(c));
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s %d", s, &tmp);
        if(!strcmp(s, "ATK")) atk.push_back(tmp);
        else def.push_back(tmp);
    }
    for(int i = 0 ; i < m ; i++) scanf("%d", &card[i]);
    sort(card, card+m);
    sort(def.begin(), def.end());
    sort(atk.begin(), atk.end());
    printf("%d\n", max(cal1(),cal2()));
    return 0;
}
