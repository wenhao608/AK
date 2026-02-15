#include <bits/stdc++.h>
using namespace std;
string s[100010];
bool cmp(string a,string b){
	return a+b<b+a;
} 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string ans;
		for(int i=1;i<=n;++i){
			cin >> s[i];
		}
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;++i){
			cout << s[i];
		}
		cout << '\n';
	}
	return 0;
}
