#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010];
int main(){
	string s;
	cin >> s;
	int n=s.size();
	s=' '+s;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;++i){
		dp[i][i]=1;
	}
	for(int len=1;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			if(i==j){
				dp[i][i]=1;
			}
			else if(s[i]==s[j]){
				dp[i][j]=dp[i][j-1];
			} 
			else{
				for(int k=i;k<j;++k){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
			
		}
	}
	cout << dp[1][n];
	return 0;
} 
