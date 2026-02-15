#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[100010];
long long ans=0;
int vis[100010];
long long dfs(int x,long long sum){
	bool chk=false;
	long long minn=0;
	for(int i=0;i<v[x].size();++i){
		int t=v[x][i].first;
		if(vis[t]==0){
			vis[t]=1;
			chk=true;
			
			minn=max(dfs(t,sum+v[x][i].second),minn);
		}
	} 
	if(chk==false){
		return sum;
	}
	return minn;
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<n;++i){
		int t,u,l;
		cin >> t >> u >> l;
		v[t].push_back({u,l});
		v[u].push_back({t,l});
		ans+=2*l;
	}
	vis[1]=1;
	
	cout << ans-dfs(1,0);
	return 0;
}
