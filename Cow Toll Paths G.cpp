#include <bits/stdc++.h>
using namespace std;
int a[1000010],dis[1010][1010],ans[1010][1010];
struct node{
	int id,val;
}p[1000010];
bool cmp(node a,node b){
	return a.val<b.val;
}
int main(){
	int n,m,q;
	cin >> n >> m >> q;
	for(int i=1;i<=n;++i){
		cin >> p[i].val;
		p[i].id=i;
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j){
				dis[i][j]=0;
			}
			else dis[i][j]=1e9;
			ans[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;++i){
		int a,b,l;
		cin >> a >> b >> l;
		dis[a][b]=min(l,dis[a][b]);
		dis[b][a]=dis[a][b];
	}
	sort(p+1,p+1+n,cmp);
	for(int u=1;u<=n;++u){
		for(int t=1;t<=n;++t){
			for(int v=1;v<=n;++v){
				int i=p[t].id;
				int j=p[v].id;
				int k=p[u].id;
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
				ans[i][j]=min(ans[i][j],dis[i][j]+max(p[u].val,max(p[t].val,p[v].val)));
			}
		}
	}
	while(q--){
		int s,t;
		cin >> s >> t;
		cout << ans[s][t] << '\n';
	}
	return 0;
}
