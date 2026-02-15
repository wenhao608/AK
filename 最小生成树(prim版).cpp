#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> > v[200010];
int n,m,dis[1000010],vis[1000010];
struct Cmp{
	bool operator()(array<int,2>x,array<int,2>y) {
	    return x[1] > y[1];
	}
};
signed main(){
	
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin >>x  >> y >> z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	priority_queue<array<int,2>,vector<array<int,2> > ,Cmp> q;
	q.push({1,0});
	int sum=0;
	while(q.size()){
		auto nd=q.top();
		q.pop();
		if(vis[nd[0]]){
			continue;
		}
		vis[nd[0]]=1;
		sum+=nd[1];
		int u=nd[0];
		for(int j=0;j<(int)v[u].size();++j){
			q.push({v[u][j].first,v[u][j].second});
		}
	}
	for(int i=1;i<=n;++i){
		if(vis[i]==0){
			cout << "orz\n";
			return 0;
		}
	}
	cout << sum;
	return 0;
}
