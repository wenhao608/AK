#include <bits/stdc++.h>
using namespace std;
vector<int> v[510];
set<pair<int,int> >s;
int f[510][30];
int k;
int vis[510];
void dfs(int fa,int x,int id){
	if(id>k){
		return ;
	} 
	if(s.count({x,id})){
		return ;
	}
	s.insert({x,id});
	f[fa][id]+=1;
	for(int i=0;i<(int)v[x].size();++i){
		dfs(fa,v[x][i],id+1);
	}
}
int main(){
	int n,m;
	cin >> n >> m >> k;
	for(int i=1;i<=m;++i){
		int x,y;
		cin >>x  >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		s.clear();
		dfs(i,i,0);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			cout << f[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
