#include <bits/stdc++.h>
using namespace std;
int a,n;
int g[510][510],vis[1000010];
struct Cmp{
	bool operator()(array<int,2>x,array<int,2> y){
		return x[1]>y[1];
	}
};
int main(){
	cin >> a >> n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin >> g[i][j];
			g[i][j]=min(g[i][j],a);
			if(g[i][j]==0){
				g[i][j]=a;
			}
		}
	}
	priority_queue<array<int,2>,vector<array<int,2> > ,Cmp> q;
	q.push({1,a});
	int sum=0;
	while(q.size()){
		auto nd =q.top();
		q.pop();
		if(vis[nd[0]]){
			continue;
		}
		vis[nd[0]]=1;
		sum+=nd[1];
		for(int i=1;i<=n;++i){
			if(vis[i]){
				continue;
			}
			q.push({i,g[nd[0]][i]});
		}
	}
	cout << sum;
	return 0;
}
