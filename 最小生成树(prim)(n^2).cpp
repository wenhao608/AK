#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> > v[200010];
int n,m,dis[1000010],vis[1000010];
signed main(){
	
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin >>x  >> y >> z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	int sum=0;
	for(int i=1;i<=n;++i){
		int u=-1;//隶属最近的点
		for(int j=1;j<=n;++j){
			if(vis[j]){
				continue;
			}
			if(dis[j]>4e18){
				continue;
			}
			if(u==-1){
				u=j;
			}
			if(dis[j]<dis[u]){
				u=j;
			}
		} 
		if(u==-1){
			cout << "orz";
			return 0;
		}
		sum+=dis[u];
		vis[u]=1;
		for(int j=0;j<(int)v[u].size();++j){
			auto&vt=v[u];
			if(vis[vt[j].first]){
				continue;
			}
			dis[vt[j].first]=min(v[u][j].second,dis[vt[j].first]);
		}
	}
	cout << sum;
	return 0;
}
