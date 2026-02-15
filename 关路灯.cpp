#include <bits/stdc++.h>
using namespace std;
int n,c;
struct node{
	int id,w;
}a[100010];
int sum[100010];
int dp[1010][1010][3];//0¡û1¡ú
int main(){
	memset(dp,0x3f,sizeof(dp)); 
	cin >> n >> c;
	for(int i=1;i<=n;++i){
		cin >> a[i].id >> a[i].w;
		sum[i]=sum[i-1]+a[i].w;
	}
	dp[c][c][0]=dp[c][c][1]=0;
	for(int j=c;j<=n;++j){
		for(int i=j-1;i>=1;--i){
			dp[i][j][0]=min(dp[i+1][j][0]+(sum[i]+sum[n]-sum[j])*(a[i+1].id-a[i].id),dp[i+1][j][1]+(sum[i]+sum[n]-sum[j])*(a[j].id-a[i].id));
			dp[i][j][1]=min(dp[i][j-1][0]+(sum[i-1]+sum[n]-sum[j-1])*(a[j].id-a[i].id),dp[i][j-1][1]+(sum[i-1]+sum[n]-sum[j-1])*(a[j].id-a[j-1].id));
		}
	}
	cout << min(dp[1][n][0],dp[1][n][1]);
	return 0;
}
