#include <bits/stdc++.h>
using namespace std;
int dp[1<<12][12],n,m;
struct node{
	int u,v,l;
}a[100010];
int g[20][20];
int vis[1010],dist[1<<12][15];
int main(){
	cin >> n >> m;
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;++i){
		cin >> a[i].u >> a[i].v >> a[i].l;
		a[i].u--;
		a[i].v--;
		g[a[i].u][a[i].v]=min(g[a[i].u][a[i].v],a[i].l);
		g[a[i].v][a[i].u]=g[a[i].u][a[i].v];
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=(1<<n)-1;++i){
		for(int v=0;v<n;++v){
			if((i>>v)&1){
				continue;
			}
			for(int u=0;u<n;++u){
				if((i>>u)&1){
					dist[i][v]=min(dist[i][v],g[v][u]);
				}
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;++i){
		dp[(1<<i)][0]=0;
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=(1<<n)-1;++j){
			for(int pre=j;pre>0;pre=(pre-1)&j){
				if(dp[pre][i-1]==0x3f3f3f3f){
					continue;
				}
				int sum=pre^j;
				int cost=0;
				bool chk=true;
				for(int z=0;z<n;++z){
					if((sum>>z)&1){
						if(dist[pre][z]==0x3f3f3f3f){
							chk=false;
							break;
						}
						cost+=dist[pre][z];
					}
				}
				if(chk==false){
					continue;
				}
				dp[j][i]=min(dp[j][i],dp[pre][i-1]+i*cost);
			}
		}
	}
	int ans=2e9;
	for(int i=0;i<n;++i){
		ans=min(ans,dp[(1<<n)-1][i]);
	}
	cout << ans;
	return 0;
}
