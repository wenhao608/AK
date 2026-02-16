#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5010],b[5010],c[5010],u[5010],v[5010];
int lst[5010];
int dp[5010][5010];
pair<int,int> ve[5010];
signed main(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> b[i] >> c[i];
		lst[i]=i;
	}
	for(int i=1;i<=m;++i){
		int u,v;
		cin >>u >> v;
		lst[v]=max(u,lst[v]);
	}
	int x=0;
	for(int i=1;i<=n;i++) ve[++x]={lst[i],c[i]};
	sort(ve+1,ve+n+1);
	int cnt=1;
	for(int i=0;i<=5000;++i){
		for(int j=0;j<=5000;++j){
			dp[i][j]=-2e18;
		}
	}
	dp[0][k]=0;
	for(int i=1;i<=n;++i){
		for(int j=b[i];j<=5000;++j){
			if(dp[i-1][j-b[i]]==-2e18){
				continue;
			}
			if(j-b[i]<a[i]){
				continue;
			} 
			dp[i][j]=dp[i-1][j-b[i]];
		}
		while (cnt<=n&&ve[cnt].first==i){
			for(int j=0;j<5000;j++){
				if(dp[i][j+1]==-2e18){
					continue;
				}
        		dp[i][j]=max(dp[i][j],dp[i][j+1]+ve[cnt].second);
			}
    		cnt++;
    	}
	}
	int ans=-1;
	for(int i=0;i<=5000;i++) ans=max(ans,dp[n][i]);
	cout << ans;
	return 0;
}
