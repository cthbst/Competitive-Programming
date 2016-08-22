#include<stdio.h>
#include<algorithm>
/*
    \magic/ \magic/ \magic/
    algorithm :
        std::next_permutation
        std::next_permutation
        std::next_permutation
        std::next_permutation
        std::next_permutation
        std::next_permutation
        std::next_permutation
*/
using namespace std ;

int main(){
    vector<int> ans[100] ;
    //build all permutation -----------
    {
        int s[10]={0,1,2,3,4,5,6,7,8,9} ;

        do {
            int b=0 ; for (int i=0 ;i<5  ;i++ )b=10*b+s[i] ;
            int a=0 ; for (int i=5 ;i<10 ;i++ )a=10*a+s[i] ;

            if (b%a==0) ans[b/a].push_back(a) ;
        } while( next_permutation(s,s+10) ) ;
    }

    for (int i=0 ;i<100 ;i++ ){
        sort(ans[i].begin(),ans[i].end()) ;
    }

    //query -----------------
    bool output_flag=0 ;
    int n ;
    while (scanf("%d",&n) && n!=0 ){
        if (output_flag)printf("\n") ;

        if (n<0 || n>=100 || ans[n].size()==0 )
            printf("There are no solutions for %d.\n",n) ;
        else
            for (int y:ans[n])printf("%05d / %05d = %d\n",y*n,y,n) ;
        output_flag=1 ;
    }
}
