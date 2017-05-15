#include <bits/stdc++.h>
#include <message.h>
#include "todd_and_steven.h"
using namespace std;

const int MOD = 1e9+7;

int main(){
	int my = MyNodeId();
	int n = GetToddLength();
	int m = GetStevenLength();
	int N = NumberOfNodes();

	int al = (long long)my*n/N, ar = (long long)(my+1)*n/N;
	int ans=0;
	if (al!=ar){
		int bl, br;	
		if (al!=0){
			int l=0, r=m;
			while (l!=r){
				int mid = (l+r)>>1;
				if ( GetStevenValue(mid) >= GetToddValue(al) )r=mid;
				else l=mid+1;
			}
			bl=l;
		}
		else bl=0;

		if (ar!=n){
			int l=0, r=m;
			while (l!=r){
				int mid = (l+r)>>1;
				if ( GetStevenValue(mid) >= GetToddValue(ar) )r=mid;
				else l=mid+1;
			}
			br=r;
		}
		else br=m;
		int pa=al, pb=bl, pos=al+bl;
		while (pa<ar && pb<br){
			if ( GetToddValue(pa) < GetStevenValue(pb) ){
				ans += GetToddValue(pa++)^(pos++);
			}
			else {
				ans += GetStevenValue(pb++)^(pos++);
			}
			ans %= MOD;
		}
		while (pa<ar){
			ans += GetToddValue(pa++)^(pos++);
			ans %= MOD;
		}
		while (pb<br){
			ans += GetStevenValue(pb++)^(pos++);
			ans %= MOD;
		}
	}

	// merge ------------------------------------------
	if (my == 0){
		for (int i=1; i<N; i++){
			Receive(i);
			ans = (ans+GetInt(i))%MOD;
		}
		cout << ans << endl;
	}
	else {
		PutInt(0,ans);
		Send(0);
	}
}

