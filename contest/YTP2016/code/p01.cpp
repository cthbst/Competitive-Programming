// by 張凱傑
#include<cstdio>
int main(){
    int N1,N2,N3;
    scanf("%d%d%d",&N1,&N2,&N3);
    if(N1==N2){puts("None");return 0;}
    int ans=N1*N2*N3/(N1-N2);
    if(ans<0)puts("None");
    else printf("%d\n",ans);

    return 0;
}
