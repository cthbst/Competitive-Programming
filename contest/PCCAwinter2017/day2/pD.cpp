#include <bits/stdc++.h>
using namespace std;
vector <int> two;
int cth[6], n, l, tmp;
class Customer
{
public:
    bool two;
    int z[2];
}c[100005];
bool cmp(int i, int j) {return c[i].z[0] < c[j].z[0];}
void P(int n)
{
    if(!n) printf("S");
    else if(n == 1)printf("M");
    else if(n == 2)printf("L");
    else if(n == 3)printf("XL");
    else if(n == 4)printf("XXL");
    else if(n == 5)printf("XXXL");
    printf("\n");
}
int main()
{
    bool cmn;
    int ans = 0;
    char input[15];
    two.clear();
    for(int i = 0 ; i < 6 ; i++) scanf("%d", &cth[i]);
    scanf("%d", &n);
    cin.get();
    for(int i = 0 ; i < n ; i++)
    {
        c[i].two = 0;
        cin.getline(input, 15);
        l = strlen(input);
        for(int j = 0 ; j < l ; j++)
        {
            if(input[j] == 'S') tmp = 0;
            else if(input[j] == 'M') tmp = 1;
            else if(input[j] == 'L') tmp = 2;
            else if(input[j] == ',')
            {
                c[i].two = 1;
                c[i].z[0] = tmp;
            }
            else if(input[j] == 'X')
            {
                tmp = 2;
                while(input[j++] != 'L') tmp++;
                j--;
            }
        }
        if(c[i].two) {c[i].z[1] = tmp;two.push_back(i);}
        else
        {
            c[i].z[0] = tmp;
            cth[tmp]--;
            if(cth[tmp] < 0) ans = -1;
        }
    }
    if(ans == -1) printf("NO\n");
    else
    {
        sort(two.begin(), two.end(), cmp);
        for(int i = 0 ; i < two.size() ; i++)
        {
            int s = two[i];
            if(cth[c[s].z[0]]) cth[c[s].z[0]]--;
            else if(cth[c[s].z[1]]) {cth[c[s].z[1]]--;c[s].z[0] = -1;}
            else {ans = -1;break;}
        }
        if(ans == -1)printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i = 0 ; i < n ; i++)
            {
                if(c[i].z[0] != -1) P(c[i].z[0]);
                else P(c[i].z[1]);
            }
        }
    }
    return 0;
}
