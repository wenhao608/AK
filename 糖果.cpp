#include <bits/stdc++.h>
using namespace std;
#define int long long
int dis[1000010];
int in[100010],cn[100010];
vector<pair<int,int> > v[100010];
signed main(){
	int n,k;
	cin >> n >> k;
	while(k--){
		int x,y,w;
		cin >> x >> y >> w;
		if(x==1){
			v[y].push_back({w,0});
			v[w].push_back({y,0});
		}
		if(x==2){
			v[y].push_back({w,1});
		}
		if(x==3){
			v[w].push_back({y,0});
		} 
		if(x==4){
			v[w].push_back({y,1});
		}
		if(x==5){
			v[y].push_back({w,0});
		}
	} 
	queue<int> q;
	for(int i=1;i<=n;++i){
		dis[i]=1;
		q.push(i);
		in[i]=1;
		cn[i]=1;
	}
	while(q.size()){
		int nd=q.front();
		q.pop();
		if(cn[nd]>=n){
			cout << -1;
			return 0;
		}
		in[nd]=0;
		for(int i=0;i<v[nd].size();++i){
			if(dis[v[nd][i].first]>=dis[nd]+v[nd][i].second){
				continue;
			}
			dis[v[nd][i].first]=dis[nd]+v[nd][i].second;
			if(in[v[nd][i].first]==0){
				q.push(v[nd][i].first);
				in[v[nd][i].first]=1;
				cn[v[nd][i].first]++;
				if(cn[v[nd][i].first]>n){
					cout << -1;
					return 0;
				}
			}
		}
	} 
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=dis[i];
	}
	cout << ans;
	return 0;
} 
