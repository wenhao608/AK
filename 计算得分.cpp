#include <bits/stdc++.h>
using namespace std;
int a[1000010],dp[1000010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=33334;++j){
			dp[j]=max(dp[j],dp[j-i]+a[i]);
		}
	}
	int m;
	string s;
	cin >> m >> s;
	s+=' '; 
	int sum=0,cnt=0;
	int i=0;
	while(i<=m){
		if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
			cnt++;
			i+=3;
			continue;
		}
		i++;
		sum+=dp[cnt];
		cnt=0;
	}
	cout << sum;
	return 0;
}
