#include <bits/stdc++.h>
using namespace std;
long long lose[1000010],win[1000010],use[1000010],dp[1000010];
int main(){
	int n,x;
	cin >> n >> x;
	for(int i=1;i<=n;++i){
		cin >> lose[i] >> win[i] >> use[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=x;j>=use[i];j--){
			dp[j]=max(dp[j]+lose[i],dp[j-use[i]]+win[i]);
		}
        for(int j=use[i]-1;j>=0;j--){
        	dp[j]+=lose[i];
		}
	}
	cout << 5*dp[x];
	return 0;
} 
