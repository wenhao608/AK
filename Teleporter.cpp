#include <bits/stdc++.h>
using namespace std;
int a[100010],vis[100010];
vector<int> v[100010];
int n,k,ans=0;
int dfs(int x){
	int res=0;
	for(int i=0;i<v[x].size();++i){
		res=max(res,dfs(v[x][i]));
	}
	res+=1;
	if(res==k&&x!=1&&a[x]!=1){
		ans++;
		return 0;
	}
	return res;
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(i!=1){
			v[a[i]].push_back(i);
		} 
	}
	if(a[1]!=1){
		ans++;
	}
	dfs(1);
	cout << ans;
	return 0;
} 
