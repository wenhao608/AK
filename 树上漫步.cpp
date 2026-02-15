#include <bits/stdc++.h>
using namespace std;
int vis[200010],n,sum[200010];
struct node{
	vector<int> v;
}b[200010];
void dfs(int x,int cnt){
	if(cnt%2==0){
		sum[2]++;
		vis[x]=2;
	}
	else{
		sum[1]++;
		vis[x]=1;
	}
	 for(int i=0;i<b[x].v.size();i++) {
        if(vis[b[x].v[i]]==0){
        	dfs(b[x].v[i],cnt+1);
		}
    }
}
int main(){
	cin >> n;
	for(int i=1;i<n;++i){
		int u,t;
		cin >> u >> t;
		b[u].v.push_back(t);
		b[t].v.push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i){
		cout << sum[vis[i]] << ' ';
	}
	return 0;
}
