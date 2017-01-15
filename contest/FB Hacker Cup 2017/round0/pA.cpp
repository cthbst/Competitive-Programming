#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926535897932;

bool ok(){
    double percent, x, y;
    cin >> percent >> x >> y;

    x-=50;
    y-=50;
    swap(x,y);

    double myPercent = atan2(y,x)/(2.0*PI)*100.0;
    if (myPercent<0.0) myPercent += 100.0;

    if (myPercent<0.0 || myPercent>percent)return 0;
    if ( x*x+y*y>50.0*50.0 )return 0;
    return 1;
}

int main(){
    //freopen("progress_pie.txt","r",stdin);
    //freopen("pA.out","w",stdout);
    int T;
    scanf("%d",&T);

    for (int t=1; t<=T; t++){
        printf("Case #%d: %s\n", t, ok()?"black":"white");
    }
}
