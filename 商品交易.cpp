#include <bits/stdc++.h>
using namespace std;
int u[200010];
int dis[200010];
vector<int> v[200010];
int main(){
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	for(int i=0;i<n;++i){
		cin >> u[i];
		dis[i]=1e9;
	}
	for(int i=1;i<=m;++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	int ans=u[b]-u[a];
	queue<pair<int,int> > q;
	q.push({a,0});
	while(q.size()){
		auto nd=q.front();
		q.pop();
		if(dis[nd.first]!=1e9){
			continue;
		}
		dis[nd.first]=nd.second;
		for(int i=0;i<(int)v[nd.first].size();++i){
			q.push({v[nd.first][i],nd.second+1});
		}
	}
	if(dis[b]==1e9){
		cout << "No solution";
	}
	else{
		cout << ans+dis[b];
	}
	return 0;
} 
