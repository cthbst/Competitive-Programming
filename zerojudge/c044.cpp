#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

struct str { int c ,count ; } ;
str S[30] ;

bool cmp(str a ,str b){ 
	if (a.count != b.count )return a.count >b.count ;
	return a.c<b.c ;
} 

int main(){
	int N ;
	char in[1030] ;

	while (~scanf("%d",&N ) ){
		gets(in) ;
		//init --------------
		for (int i=0 ;i<26 ;i++ ){
			S[i].c=i ;
			S[i].count=0 ;
		}
		//input -------------
		for (int i=0 ;i<N ;i++ ){
			gets(in) ;
			for (int j=0 ;j<strlen(in);j++ ){
				if ('A'<=in[j] && in[j]<='Z')
					S[in[j]-'A'].count++ ;
				else if ('a'<=in[j] && in[j]<='z')
					S[in[j]-'a'].count++ ;
			}
		}
		//output ------------
		sort(S,S+26,cmp) ;
		for (int i=0 ;i<26 && S[i].count>0 ;i++ ){
			printf("%c %d\n",'A'+S[i].c ,S[i].count) ;
		}
	}
}
