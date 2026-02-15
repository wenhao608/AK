#include <bits/stdc++.h>
using namespace std;
int n,m,a[21];
string s;
int calc(int p){
	int cnt=0;
	for(int i=p;i-2>=1;i-=3){
		if(s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a'){
			cnt++;
			if(cnt==n){
				return n; 
			}
		}
		else{
			break;
		}
	}
	return cnt;
}
int dp[1000010];
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	cin >> m;
	cin >> s;
	s=' '+s;
	for(int i=1;i<=m;++i){
		int num=calc(i);
		dp[i]=dp[i-1];
		for(int j=1;j<=num;++j){
			dp[i]=max(dp[i],dp[i-3*j]+a[j]);
		}
	}
	cout << dp[m];
	return 0;
}
