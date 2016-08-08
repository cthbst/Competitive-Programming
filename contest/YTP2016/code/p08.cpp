// by 張凱傑
#include<cstdio>
int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    for(int a=1;a<1000;a++){
        if(2*a*x+2*y+2*z/a==a*a){
            printf("%d %d %d\n",a*a,a,1);
            break;
        }
    }
    return 0;
}
