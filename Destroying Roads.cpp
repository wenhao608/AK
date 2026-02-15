#include <bits/stdc++.h>
using namespace std;
int n,m,s1,t1,l1,s2,t2,l2;
vector<int> v[3010];
int dis[3010][3010],vis[3010];
void dfs(int x){
	queue<int> q;
	q.push(x);
	memset(vis,0,sizeof(vis));
	vis[x]=1;
	dis[x][x]=0;
	while(q.size()){
		int nd=q.front();
		q.pop();
		for(int i=0;i<v[nd].size();++i){
			if(vis[v[nd][i]]){
				continue;
			}
			vis[v[nd][i]]=1;
			q.push(v[nd][i]);
			dis[x][v[nd][i]]=dis[x][nd]+1;
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	for(int i=1;i<=n;++i){
		dfs(i);
	}
	int ans=2e9;
	if(l1>=dis[s1][t1]&&l2>=dis[s2][t2]){
		ans=dis[s1][t1]+dis[s2][t2];
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(dis[s1][i]+dis[i][j]+dis[j][t1]>l1) continue;
			if(dis[s2][i]+dis[i][j]+dis[j][t2]>l2) continue;
			ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
		}
	}
	swap(t2,s2);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(dis[s1][i]+dis[i][j]+dis[j][t1]>l1) continue;
			if(dis[s2][i]+dis[i][j]+dis[j][t2]>l2) continue;
			ans=min(ans,dis[s1][i]+dis[i][j]+dis[j][t1]+dis[s2][i]+dis[j][t2]);
		}
	}
	if(ans>m) {
		cout << -1;
		return 0;
	}
	cout << m-ans;
	return 0;
}
