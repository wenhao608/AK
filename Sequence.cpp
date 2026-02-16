#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5010],b[5010];
int dp[10][5010],m[10][5010];
signed main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;++i){
		m[1][0]=1e18;
		for(int j=1;j<=n;++j){
			dp[1][j]=m[0][j]+abs(b[j]-a[i]);
			m[1][j]=min(m[1][j-1],dp[1][j]);
		}
		for(int j=1;j<=n;j++) m[0][j]=m[1][j];
	}
	int ans=1e18;
	for(int i=1;i<=n;++i){
		ans=min(ans,dp[1][i]);
	}
	cout << ans;
	return 0;
} 
