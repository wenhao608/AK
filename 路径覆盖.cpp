#include <bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int c[100010];
int dfs(int x){
	if(v[x].size()==0){
		return c[x];
	}
	int ans=0;
	for(int i=0;i<(int)v[x].size();++i){
		ans+=dfs(v[x][i]);
	} 
	return min(ans,c[x]);
}
int main(){
	int n;
	cin >> n;
	for(int i=2;i<=n;++i){
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	for(int i=1;i<=n;++i){
		cin >> c[i];
	}
	cout << dfs(1);
	return 0;
}
