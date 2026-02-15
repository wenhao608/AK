#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int main(){
	int n,m;
	cin >> n >> m;
	long long ans=0;
	for(int i=1;i<=m;++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		ans+=(v[i].size()*(v[i].size()-1)/2);
	}
	cout << ans;
	return 0;
} 
