#include <bits/stdc++.h>
using namespace std;
int dis[1000010];
int n,m,w1,cnt=0;
struct  node{
	int u,v,w;
}a[1000010];
bool chk(){
	for(int i=1;i<n;++i){
		for(int j=1;j<=cnt;++j){
			dis[a[j].v]=min(dis[a[j].v],dis[a[j].u]+a[j].w); 
		}
	}
	for(int i=1;i<=cnt;++i){
		if(dis[a[i].v]>dis[a[i].u]+a[i].w){
			return true;
		}
	}
	return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cnt=0;
		cin >> n >> m >> w1;
		for (int i=1;i<=n;++i) {
            dis[i]=2e9;
            
        }
		for(int i=1;i<=m;++i){
			int u,v,w;
			cin >> u >> v >> w;
			a[++cnt].u=u;
			a[cnt].v=v;
			a[cnt].w=w;
			a[++cnt].u=v;
			a[cnt].v=u;
			a[cnt].w=w;
	
		}
		for(int i=1;i<=w1;++i){
			int u,v,w;
			cin >> u >> v >> w;
			a[++cnt].u=u;
			a[cnt].v=v;
			a[cnt].w=-w;
		}
		if(chk()){
			cout << "YES\n";
		}
		else{ 
			cout << "NO\n";
		}
	}
	return 0;
}
