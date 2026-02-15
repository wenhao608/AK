#include <bits/stdc++.h>
using namespace std;
int n,m,vis[100010];
vector<int> v[100010];
int cnt=0,cnt2=0;
void dfs(int x,bool h){
	vis[x]=1;
	if(h==0){
		cnt++;
	}
	else{
		cnt2++;
	}
	
	for(int i=0;i<(int)v[x].size();++i){
		if(vis[v[x][i]]==0) dfs(v[x][i],!h);
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
	int minn=0,maxn=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			cnt=0;
			cnt2=0;
			dfs(i,0);
			minn+=min(cnt,cnt2);
			maxn+=max(cnt,cnt2);
		}
	}
	cout << minn << ' ' << maxn;
	return 0;
} 
