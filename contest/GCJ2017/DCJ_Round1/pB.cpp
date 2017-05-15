#include <bits/stdc++.h>
#include <message.h>
#include "pancakes.h"
using namespace std;

int main(){
	int my = MyNodeId();
	int n = GetStackSize();
	int N = NumberOfNodes();

	int l = (long long)my*n/N, r = (long long)(my+1)*n/N;
	int ansi=0;
	for (int i=l; i<r; i++)if (i+1<n){
		ansi += (GetStackItem(i)>GetStackItem(i+1));
	}

	if ( (my+1)*2 <= N ){
		int d = (my+1)*2-1;
		Receive(d);
		ansi += GetInt(d);
	}
	if ( (my+1)*2+1 <= N ){
		int d = (my+1)*2+1-1;
		Receive(d);
		ansi += GetInt(d);
	}

	if (my == 0){
		cout << ansi+1 << endl;
	}
	else {
		int d = (my+1)/2-1;
		PutInt(d,ansi);
		Send(d);
	}
}

