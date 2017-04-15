#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;

int N, P;
int R[MAXN];
int Q[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];
int it[MAXN];

void input(){
	cin >> N >> P;

	for(int i=0; i<N; i++){
		cin >> R[i];
	}

	for (int i=0;i<N; i++){
		for (int j=0; j<P; j++){
			cin >> Q[i][j];
		}
	}
}

void build_l_r(){
	for (int i=0; i<N; i++){
		sort(Q[i],Q[i]+P,greater<int>());
		//cout << endl; //debug
		for (int j=0; j<P; j++){
			l[i][j] = ceil ( (Q[i][j]*10.0) / ( R[i]*11.0 ) );
			r[i][j] = floor( (Q[i][j]*10.0) / ( R[i]* 9.0 ) );
			//printf("[%d,%d]", r[i][j], l[i][j]); //debug
		}
	}
	//cout << endl; // debug
}

void solve(){
	memset(it,0,sizeof(it));
	
	int ans=0;

	while (1){
		bool ok=1;
		for (int i=0; i<N; i++){
			while (it[i]<P && l[i][it[i]]>r[i][it[i]])it[i]++;
			if (it[i]>=P){
				ok = 0;
				break;
			}
		}

		if (!ok)break;

		int mir=0, mxl=0;
		for (int i=0; i<N; i++){
			if (r[i][ it[i] ]<r[mir][ it[mir] ])mir = i;
			if (l[i][ it[i] ]>l[mxl][ it[mxl] ])mxl = i;
		}
		//printf("\nmir=%d mxl=%d\n",mir,mxl);
		//for (int i=0; i<N; i++) cout << it[i] <<" " ; cout << endl;

		// rember ! l>r
		if (l[mxl][it[mxl]]<=r[mir][it[mir]]){
			ans++;
			for (int i=0; i<N; i++){
				it[i]++;
			}
		}
		else {
			it[mxl]++;
		}
	}

	cout << ans << endl;
}

int main(){
	int T; cin >> T;
	
	for (int t=1; t<=T; t++){
		input();
		build_l_r();
		printf("Case #%d: ",t);
		solve();
	}
}
