#include <bits/stdc++.h>
#include <message.h>
#include "weird_editor.h"
using namespace std;

const int MOD = 1e9+7;

int POW(int a, int n){
	int re=1;
	while (n>0){
		if (n&1)re = (long long)re*a%MOD;
		a = (long long)a*a%MOD;
		n>>=1;
	}
	return re;
}

int k1(int n){
	int re=0;
	int a=1, t=10; // a:1111... t:1000...
	while (n>0){
		if (n&1){
			re = ((long long)re*t+a)%MOD;
		}
		a = ((long long)a*t+a)%MOD;
		t = (long long)t*t%MOD;
		n>>=1;
	}
	return re;
}

int main(){
	int my = MyNodeId();
	int n = GetNumberLength();
	int N = NumberOfNodes();

	int l = (long long)my*n/N, r = (long long)(my+1)*n/N;
	int cnt[10];
	memset(cnt,0,sizeof(cnt));

	for (int i=l; i<r; i++){
		int dig = GetDigit(i);
		for (int j=0; j<dig; j++)cnt[j]=0;
		cnt[dig]++;
	}

	if (my == 0){
		for (int i=1; i<N; i++){
			Receive(i);
			int R[10];
			for (int j=0; j<10; j++)R[j] = GetInt(i);
			for (int j=9; j>0; j--)if (R[j]>0){
				cnt[j] += R[j];
				for (int k=0; k<j; k++)cnt[k] = R[k];
				break;
			}
		}

		cnt[0] = GetNumberLength();
		for (int i=1; i<10; i++)cnt[0]-=cnt[i];
		
		int out=0;
		for (int i=9; i>=0; i--){
			out = (long long) out * POW(10,cnt[i]) %MOD;
			out = ( (long long)out + (long long)k1(cnt[i])*i )%MOD;
		}
		cout << out << endl;
	}
	else {
		for (int i=0; i<10; i++)PutInt(0,cnt[i]);
		Send(0);
	}
}

