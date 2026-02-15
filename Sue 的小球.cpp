#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y,v;
}a[1010];
int dp[1010][1010][3],sum[1010];
bool cmp(node a,node b){
	return a.x<b.x;
}
signed main(){
	memset(dp,-0x3f,sizeof(dp));
	int n,x0;
	cin >> n >> x0;
	for(int i=1;i<=n;++i){
		cin >> a[i].x;
	}
	for(int i=1;i<=n;++i){
		cin >> a[i].y;
	}
	for(int i=1;i<=n;++i){
		cin >> a[i].v;
	}
	a[++n].x=x0;
	a[n].v=a[n].y=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].x==x0&&a[i].y==0&&a[i].v==0){
			dp[i][i][0]=dp[i][i][1]=0;
		}
	}
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i].v;
	}
	for(int len=2;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			dp[i][j][0]=max(dp[i+1][j][0]-(a[i+1].x-a[i].x)*(sum[i]+sum[n]-sum[j]),dp[i+1][j][1]-(a[j].x-a[i].x)*(sum[i]+sum[n]-sum[j]))+a[i].y;
			dp[i][j][1]=max(dp[i][j-1][0]-(a[j].x-a[i].x)*(sum[i-1]+sum[n]-sum[j-1]),dp[i][j-1][1]-(a[j].x-a[j-1].x)*(sum[i-1]+sum[n]-sum[j-1]))+a[j].y;
		}
	}
	double ans=max(dp[1][n][0],dp[1][n][1])/1000.0;
	printf("%.3lf",ans);
	return 0; 
}
