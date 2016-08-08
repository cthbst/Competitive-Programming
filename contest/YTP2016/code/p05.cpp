// by 張凱傑
#include<cstdio>
#define MAXN 110
int N,num[MAXN],awake[MAXN];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
        awake[i]=1;
    }
    int nownum=0,tag=0,left=N;
    while(left>1){
        nownum++;
        //check
        for(int i=0;i<N;i++){
            if(i==tag)continue;
            if(!awake[i])continue;
            if(nownum%num[i]==0){
                //printf("del %d [%d]\n",i,num[i]);
                awake[i]=0;
                left--;
            }
        }
        //move tag
        bool arrive=0;
        while(!arrive){
            tag++;
            if(tag>=N)tag=0;
            if(awake[tag])arrive=1;
        }
    }
    for(int i=0;i<N;i++){
        if(awake[i]){printf("%d\n",i+1);break;}
    }
    return 0;
}
