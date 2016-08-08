// by 張凱傑
#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    while(n>9){
        int next=0;
        while(n){
            next+=n%10;
            n/=10;
        }
        n=next;
    }
    printf("%d\n",n);
    return 0;
}
