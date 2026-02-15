#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<pair<signed,long long> > v[1000010];
int vis[1000010],b[1000010];
void bfs(int x){
	memset(vis,0,sizeof(vis));
	memset(b,0,sizeof(b));
	queue<signed> q;
	b[x]=0;
	q.push(x);
	while(q.size()){
		signed n=q.front();
		q.pop();
		for(int i=0;i<v[n].size();++i){
			if(vis[v[n][i].first]==0){
				vis[v[n][i].first]=1;
				b[v[n][i].first]=b[n]+v[n][i].second;
				q.push(v[n][i].first);
			}
		}
	}
}
signed main(){
	int n;
	cin >> n;
	for(int i=1;i<n;++i){
		int x,y,z;
		cin >> x >> y >> z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	bfs(1);
	int x=1,y=b[1];
	for(int i=2;i<=n;++i){
		if(b[i]>y){
			y=b[i];
			x=i;
		}
	}
	bfs(x);
	y=b[1];
	for(int i=2;i<=n;++i){
		y=max(y,b[i]);
	}
	cout << y;
	return 0;
} 
