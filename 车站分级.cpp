#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010];
int vis[10010];
int dis[1010][1010];
int de[100010];
int level[1000010];
int ans=1;
int main(){
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int b;
		cin >> b;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=b;++i){
			cin >> a[i];
			vis[a[i]]=1;
		} 
		for(int i=a[1];i<=a[b];++i){
			if(vis[i]){
				continue;
			}
			for(int j=1;j<=b;++j){
				if(!dis[i][a[j]]){
					dis[i][a[j]]=1;
					de[a[j]]++;
				}
			}
		}
	}
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(de[i]==0){
			level[i]=1;
			q.push(i);
		}
	}
	while(q.size()){
		int nd=q.front();
		q.pop();
		ans=max(ans,level[nd]); 
		for(int i=1;i<=n;++i){
			if(dis[nd][i]){
				de[i]--;
				level[i]=max(level[i],level[nd]+1);
				if(de[i]==0){
					q.push(i);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
