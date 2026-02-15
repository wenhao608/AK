#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int dp[100010],w[100010],v[100010];
signed main(){
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	cin >> n >> m;
	int x=0;
	for(int i=1;i<=n;++i){
		cin >> w[i] >> v[i];
		x+=v[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=x;j>=v[i];--j){
			dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	int ans=0;
	for(int i=x;i>=0;--i){
		if(dp[i]<=m){
			ans=i;
			break;
		}
	}
	cout << ans;
	return 0;
}
