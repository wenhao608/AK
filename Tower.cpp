#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[100010];
struct node{
	int w,s,v;	
}a[100010];
bool cmp(node a,node b){
	return a.w+a.s<b.w+b.s;
}
signed main() {
	cin >> n;
	for(int i=1;i<=n;++i) {
		cin >> a[i].w >> a[i].s >> a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	memset(dp,-0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++) {
		for(int j=100000;j>=1;--j) {
			if(j>=a[i].w&&j-a[i].w<=a[i].s) {
				dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=100000;++i){
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}
