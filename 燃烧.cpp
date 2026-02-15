#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int f[1000010];
vector<int> v[100010];
void dfs(int x,int fa){
	f[x]=1;
	for(int i=0;i<(int)v[x].size();++i){
		if(v[x][i]==fa){
			continue;
		}
		dfs(v[x][i],x);
		if(a[x]>a[v[x][i]]){
			f[x]+=f[v[x][i]];
		}
	}
}
void dfs2(int x,int fa){
	for(int i=0;i<(int)v[x].size();++i){
		if(v[x][i]==fa){
			continue;
		}
		if(a[x]<a[v[x][i]]){
			f[v[x][i]]+=f[x];
		}
		dfs2(v[x][i],x);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<n;++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	dfs2(1,0);
	int maxn=0;
	for(int i=1;i<=n;++i){
		maxn=max(maxn,f[i]);
	}
	cout << maxn;
}
