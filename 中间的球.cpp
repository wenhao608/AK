#include <bits/stdc++.h>
using namespace std;
int dis[1010][1010];
int c[1010],d[1010];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >>n >> m;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=0;
			}
		}
		for(int i=1;i<=m;++i){
			int a,b;
			cin >> a >> b;
			dis[a][b]=1;
			dis[b][a]=-1;
		}
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(dis[i][k]==1&&dis[k][j]==1){
						dis[i][j]=1;
						dis[j][i]=-1;
					}
					if(dis[i][k]==-1&&dis[k][j]==-1){
						dis[i][j]=-1;
						dis[j][i]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis[i][j]==1){
					c[i]++;
				}d
				if(dis[i][j]==-1){
					d[i]++;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(c[i]>n/2||d[i]>n/2){
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
