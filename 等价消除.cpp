#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[200010];
signed main(){
	map<int,int> ma;
	int n;
	cin >> n;
	string s;
	cin >> s;
	s=' '+s;
	int sum=0,ans=0;
	ma[0]=1;
	for(int i=1;i<=n;++i){
		sum^=(1<<(s[i]-'a'));
		ans+=ma[sum];
		ma[sum]++;
	}
	cout << ans;
	return 0;
}
