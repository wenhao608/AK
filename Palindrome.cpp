#include <bits/stdc++.h>
using namespace std;
int dp[5010][5010];
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string s1=s;
	reverse(s.begin(),s.end());
	s=' '+s;
	s1=' '+s1;
	for(int i=1;i<s.size();++i){
		for(int j=1;j<s1.size();++j){
			if(s[i]==s1[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout << n-dp[s.size()-1][s1.size()-1];
	return 0;
}
