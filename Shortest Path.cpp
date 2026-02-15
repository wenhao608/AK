#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
int vis[3010][3010],pre[1000010];
struct node{
	int a,b,c;
}a[1000010];
bool cmp(node a,node b){
	if(a.a!=b.a){
		return a.a<b.a;
	}
	if(a.b!=b.b){
		return a.b<b.b;
	}
	return a.c<b.c;
}
int b[3010][3010];

int n,m,k;
void bfs(){
	queue<array<int,3> > q;
	for(int i=0;i<v[1].size();++i){
		q.push({1,v[1][i],1});
	} 
	while(q.size()){
		auto nd=q.front();
		q.pop();
		int j=1;
		for(int i=0;i<v[nd[1]].size();++i){
			if(vis[nd[1]][v[nd[1]][i]]==1){
				continue;
			}
			while(nd[0]<a[j].a){
				j++;
			}
			if(nd[0]==a[j].a){
				while(nd[1]<a[j].b){
					j++;
				}
				if(nd[1]==a[j].b){
					while(v[nd[1]][i]<a[j].c){
						j++;
					}
				}
			}
			if(nd[0]==a[j].a&&nd[1]==a[j].b&&v[nd[1]][i]==a[j].c){
				continue;
			}
			if(b[nd[1]][v[nd[1]][i]]>nd[2]+1){
				vis[nd[1]][v[nd[1]][i]]=1;
				b[nd[1]][v[nd[1]][i]]=nd[2]+1;
				q.push({nd[1],v[nd[1]][i],nd[2]+1});
				pre[v[nd[1]][i]]=nd[1];
			}
			
		}
	}
}
void out(int x){
	if(x==1){
		cout << x << ' ';
		return ;
	}
	out(pre[x]);
}
int main(){
	cin >> n >> m >> k;
	for(int i=1;i<=m;++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=m;++i){
		sort(v[i].begin(),v[i].end());
	}
	for(int i=1;i<=k;++i){
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	sort(a+1,a+1+k,cmp);
	bfs();
	if(b[n]==0){
		cout << -1 << '\n';
	} 
	else{
		int ans=1e9;
		for(int i=1;i<n;++i){
			if(b[i][n]!=0){
				ans=min(ans,b[i][n]);
			}
		}
		cout << ans << '\n';
		out(n);
	}
	return 0;
}
