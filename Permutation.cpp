#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[3010][3010];
int dp[3010][3010];
signed main(){
	int n;
	string s;
	cin >> n >> s;
	s=' '+s;
	f[1][1]=1;
	dp[1][1]=1;
	for(int i=2;i<=s.size();++i){
		for(int j=1;j<=i;++j){
			if(s[i-1]=='>'){
				f[i][j]=(dp[i-1][i-1]-dp[i-1][j-1]+1000000007)%1000000007;
			}
			else{
				f[i][j]=dp[i-1][j-1];
			}
		}
		for(int j=1;j<=i;++j){
			dp[i][j]=dp[i][j-1]+f[i][j];
			dp[i][j]%=1000000007;
		}
	}
	cout << dp[n][n]%1000000007;
	return 0;
}
