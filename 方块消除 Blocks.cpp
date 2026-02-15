#include <bits/stdc++.h>
using namespace std;
int a[100010];
int dp[210][210][210],nxt[210],lst[210];
int dfs(int l,int r,int m){
	if(l>r){
		return 0;
	}
	if(dp[l][r][m]){
		return dp[l][r][m];
	}
	dp[l][r][m]=max(dp[l][r][m],dfs(l,r-1,0)+(m+1)*(m+1));
	for(int i=nxt[r];i>=l;i=nxt[i]){
		dp[l][r][m]=max(dp[l][r][m],dfs(l,i,m+1)+dfs(i+1,r-1,0));
	}
	return dp[l][r][m];
}
int main(){
	int t;
	cin >> t;
	int pl=t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(nxt,0,sizeof(nxt));
		memset(lst,0,sizeof(lst));
	
		int n;
		cin >> n;
		for(int i=1;i<=n;++i){
			cin >> a[i];
			nxt[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		cout << "Case " << pl-t << ": ";
		cout << dfs(1,n,0) << '\n';
	}
	return 0;
}
