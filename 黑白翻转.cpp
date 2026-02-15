#include <bits/stdc++.h>
using namespace std;
int a[1000010],n,ans=0,vis[1000010];
vector<int> v[100010];
bool dfs(int x){
	vis[x]=1;
	bool chk=false;
	for(int i=0;i<(int)v[x].size();++i){
		if(!vis[v[x][i]]){
			if(dfs(v[x][i])){
				chk=true;
			}
		}
	}
	if(chk&&a[x]==0){
		ans++;
	}
	return (a[x]==1||chk);
}
int main(){
	int u=1;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		if(a[i]==1){
			u=i;
		}
	}
	for(int i=1;i<n;++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(u);
	cout << ans;
	return 0;
} 
