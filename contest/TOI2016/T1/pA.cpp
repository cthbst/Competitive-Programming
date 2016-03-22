#include<bits/stdc++.h>
using namespace std ;

typedef long long LL ;
const int maxn = 100 ;
const int maxm = 100030 ;
const LL bound = 10000 ;
int n ,m ,mm ;
struct ele{
    string s ; int sum ;
    ele():sum(0){  }
    bool operator > (const ele& B)const {
        return sum>B.sum ;
    }
    bool operator < (const ele& B)const {
        return s<B.s ;
    }
    ele operator + (const ele& B)const{
        ele re ;
        re.sum=sum+B.sum ;
        re.s=s+B.s ;
        return re ;
    }
    void reset(){
        int len= s.size() ;
        for (int i=0 ;i<len ;i++ ){
            for (int j=i+1 ;j<len  ;j++ ){
                if (s[i]>s[j])swap(s[i],s[j]) ;
            }
        }
    }
}a[maxn] ;
string aph(int x){
    char c = x<26?x+'A':x-26+'a' ;
    char ss[4] ;sprintf(ss,"%c",c) ;
    return (string)ss ;
}
bool ok=1 ;
struct str{
    LL cnt ;
    vector<ele> S ;
    str():cnt(0){ S.clear(); }
}dp[maxm],Ans ;

int main(){
    ele ZERO ; ZERO.sum=0 ,ZERO.s=(string)"" ;
    cin >> n >> m ;
    for (int i=0 ;i<n ;i++ ){
        scanf("%d",&a[i].sum ) ;
        a[i].sum=a[i].sum*m/100 ;
        mm+=a[i].sum ;
        a[i].s=aph(i) ;
    } m=mm ;
    sort(a,a+n,greater<ele>()) ;

    dp[0].cnt=1 ,dp[0].S.push_back(ZERO) ;
    for (int i=0 ;i<n ;i++ )if (a[i].sum!=0){
        int ai = a[i].sum ;

        for (int j=m/2 ;j>=0 ;j-- ){
            if ((j+ai)*2>m){
                Ans.cnt+=dp[j].cnt ;
                if (ok && Ans.cnt<=bound){
                    for (auto e:dp[j].S){
                        Ans.S.push_back(e+a[i]) ;
                    }
                }
                else Ans.S.clear() ;
            }
            else {
                dp[j+ai].cnt+=dp[j].cnt ;
                if (ok && dp[j+ai].cnt<=bound){
                    for (auto e:dp[j].S){
                        dp[j+ai].S.push_back(e+a[i]) ;
                    }
                }
                else { dp[j+ai].S.clear() ; }
            }
        }
        if (ok && Ans.cnt>bound){
            ok=0 ;
            Ans.S.clear() ;
            for (int j=m/2 ;j>=0 ;j-- )dp[j].S.clear() ;
        }
    }
    printf("%lld\n",Ans.cnt ) ;
    if (!ok)return 0 ;
    for (auto &e:Ans.S)e.reset() ;
    sort(Ans.S.begin(),Ans.S.end()) ;
    for (auto e:Ans.S){
        printf("%s %d\n",e.s.c_str() ,e.sum ) ;
    }
}
