#include<bits/stdc++.h>
using namespace std ;

typedef unsigned long long LLU ;

vector<LLU> ans ;

int main(){
    LLU X ; cin >> X ;

    for (LLU i=1 ;i*(i+1)*(2*i+1)<=6*X ;i++ ){
        if (X*6%(i*i+i)!=0)continue ;
        if ((X*6/(i*i+i)+i-1)%3==0){
            ans.push_back(i) ;
        }
    }
    int last = ans.size()-1 ;

    while (last>=0){
        LLU i = ans[last--] ;
        LLU j =(X*6/i/(i+1)+i-1)/3 ;
        if (i!=j)ans.push_back(j) ;
    }
    printf("%d\n",ans.size()) ;
    for (int i=0 ,sz=ans.size()-1 ;i<=sz ;i++ ){
        cout << ans[i] <<" "<<ans[sz-i] <<endl ;
    }
}
