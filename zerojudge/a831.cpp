#include<stdio.h>
#include<math.h>

int main(){
    long long int N ,M ,A ;
    while (~scanf("%lld%lld%lld",&N ,&M ,&A)){
        N=(long long int )ceil((double)N/A) ;
        M=(long long int )ceil((double)M/A) ;
        printf("%lld\n",N*M) ;
    }
}
