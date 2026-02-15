#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		if(s.size()!=t.size()){
			cout << "NO\n";
			continue;
		}
		sort(s.begin(),s,end());
		sort(t.begin(),t.end());
		if(s==t){
			cout << "YES\n";
		}
		else{
			cout <<"NO\n";
		}
	}
	return 0;
}
