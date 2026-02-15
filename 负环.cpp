#include <bits/stdc++.h>
using namespace std;
int dist[1000010];
struct node{
	int u,v,w;
}a[1000010];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		int cnt=0;
		for(int i=1;i<=n;++i){
			dist[i]=2e9;
		}
		dist[1]=0;
		for(int i=1;i<=m;++i){
			int u,v,w;
			cin >> u >> v >> w;
			a[++cnt].u=u;
			a[cnt].v=v;
			a[cnt].w=w;
			if(w>=0){
				a[++cnt].u=v;
				a[cnt].v=u;
				a[cnt].w=w;
			}
		}
		for(int i=1;i<n;++i){
			for(int j=1;j<=cnt;++j){
				if(dist[a[j].u]!=2e9){
					dist[a[j].v]=min(dist[a[j].v],dist[a[j].u]+a[j].w);
				}
			}
		}
		bool chk=false;
		for(int i=1;i<=cnt;++i){
			if(dist[a[i].u]!=2e9&&dist[a[i].u]+a[i].w<dist[a[i].v]){
				chk=true;
				break;
			}
		}
		if(chk){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
