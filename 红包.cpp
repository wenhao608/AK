#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,ans=0;
	cin >> n;
	for(int i=1;i<=n;++i){
		string name;
		int x;
		cin >> name >> x;
		if(name=="Q"){
			ans+=x;
		}
	}
	cout << ans;
	return 0;
}
