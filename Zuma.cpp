#include <bits/stdc++.h>
using namespace std;
int a[510],dp[510][510];
int main(){
	int n;
	cin >> n;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;++i){
		cin >> a[i];
		dp[i][i]=1;
	}
	for(int i=1;i<n;i++) dp[i][i+1]=1+(a[i]!=a[i+1]);
	for(int len=3;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=len+i-1;
			if(a[i]==a[j]){
				dp[i][j]=dp[i+1][j-1];
			}
			for(int k=i;k<j;++k){
				dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
} 
