#include <bits/stdc++.h>
using namespace std;

int n, P;
int cnt[5];

void input(){
	memset(cnt,0,sizeof(cnt));
	cin >> n >> P;
	for (int i=0, ai; i<n; i++){
		cin >> ai;
		cnt[ ai%P ]++;
	}
}

void solve(){
	if (P==2){
		cout << cnt[0] + (cnt[1]+1)/2 << endl;
		return ;
	}
	else if (P==3){
		static int dp[130][130];
		memset(dp,-1,sizeof(dp));
		dp[ cnt[1] ][ cnt[2] ]=0;
		
		int ans = 0;
		int add[3][2]=	{
							{3,0},
							{1,1},
							{0,3}	};

		for (int i=cnt[1]; i>=0; i--){
			for (int j=cnt[2]; j>=0; j--){
				for (int r=0; r<3; r++){
					int ss = dp[ i+add[r][0] ][ j+add[r][1] ];
					if (ss!=-1)dp[i][j]=max(dp[i][j],ss+1);
				}
				if (i==0 && j==0)ans = max(ans,dp[i][j]);
				else ans = max(ans,dp[i][j]+1);
			}
		}
		cout << ans+cnt[0] << endl;
	}
	else if (P==4){
		static int dp[130][130][130];
		memset(dp,0,sizeof(dp));
		dp[ cnt[1] ][ cnt[2] ][ cnt[3] ]=0;

		int ans = 0;
		int add[][3]=	{
							{4,0,0},
							{2,1,0},
							{0,2,0},
							{1,0,1},
							{0,1,2}	};
		
		for (int i=cnt[1]; i>=0; i--){
			for (int j=cnt[2]; j>=0; j--){
				for (int k=cnt[3]; k>=0; k--){
					for (int r=0; r<5; r++){
						int ss = dp[ i+add[r][0] ][ j+add[r][1] ][ k+add[r][2] ];
						if (ss!=-1)dp[i][j][k]=max(dp[i][j][j],ss+1);
					}
					if (i==0 && j==0 && k==0)ans = max(ans,dp[i][j][k]);
					else ans = max(ans,dp[i][j][k]+1);
				}
			}
		}
		cout << ans+cnt[0] << endl;
	}
}

int main(){
	int T; cin >>T;
	
	for (int t=1; t<=T; t++){
		printf("Case #%d: ",t);
		input();
		solve();
	}
}
