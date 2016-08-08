// by cthbst
#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(int deep,char* S,char* out){
	if (deep==n){
		out[deep]=0;
		puts(out);
		return ;
	}
	for (int i=0; i<n; i++)if (S[i]!=0){
		out[deep]=S[i];
		S[i]=0;
		dfs(deep+1,S,out);
		S[i]='A'+i;
	}
}

int main(){
	cin >> n;
	char S[100],out[100];
	for (int i=0; i<n; i++)S[i]='A'+i;
	dfs(0,S,out);
}
