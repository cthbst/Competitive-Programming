#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;
const int MAXN = 1003;
const int MAXC = 1003;
const int MAXM = 1003;

int N, C, M;
vector< pair<int,int> > a;
int G[MAXM][MAXN];
int used[MAXN][MAXN];
int min_round=0, min_cost=0, ok=1;

void input(){
	cin >> N >> C >> M;

	a.resize(M);
	
	int Pi, Bi;
	for (int i=0; i<M; i++){
		cin >> Pi >> Bi;
		a[i] = {Pi,Bi}; 
	}
}

void find_pos(int Pi, int Bi){
	for (int i=0; i<min_round; i++){
		if (used[i][Bi]==0 && G[i][Pi]==0){
			used[i][Bi]=1;
			G[i][Pi]=Bi;
			return;
		}
	}
	for (int i=0; i<min_round; i++)
	for (int j=1; j<Pi; j++)
	{
			if (used[i][Bi]==0 && G[i][j]==0){
			used[i][Bi]=1;
			G[i][j]=Bi;
			min_cost++;
			return;
			}
	}
	ok=0;
}

bool check(int round){
	memset(G,0,sizeof(G));
	memset(used,0,sizeof(used));	
	ok=1;
	min_round=round;
	min_cost=0;
	for (int i=0; i<M; i++){
		find_pos(a[i].first,a[i].second);
		if (ok==0)return 0;
	}
	return ok;
}

void solve(){
	sort(a.begin(),a.end());
	int l=0, r=M;
	while (l!=r){
		int mid = (l+r)>>1;	
		if ( check(mid) )r=mid;
		else l=mid+1;
	}
	check(r);
	cout << min_round << " " << min_cost << endl;
}

int main(){
	int T; cin >>T;
	
	for (int t=1; t<=T; t++){
		printf("Case #%d: ",t);
		input();
		solve();
	}
}
