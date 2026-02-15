#include <bits/stdc++.h>
using namespace std;
int n,m,vis[1000010],cnt,ans=0;
vector<int> q[1000010];
struct node{
	pair<int,int> a;
	int c;
}a[1000010];
vector<int> v[1000010],v1[1000010];
void bfs(int x,pair<int,int> a,int y){
	v[cnt].push_back(a.first);
	v[cnt].push_back(a.second);
	queue<int> q;
	q.push(a.first);
	q.push(a.second);
	while(q.size()){
		int d=q.front();
		q.pop();
		for(int i=0;i<v1[d].size();++i){
			for(int j=1;j<=m;++j){
				if(a[j].c==x&&[j].a.first==d&&a[j].a.second==v1[d][i]){
					q.push(v1[d][i]);
					v[cnt].push_back(v1[d][i]);
				}
			}
		}
	}
}
void bfs1(){
	queue<array<int,2> > q;
	q.push({1,1});
	while(q.size77()){
		auto nd=q.front();
		q.pop(); 
		if(q[0]==n){
			ans=q[1];
			return ;
		}
	}
	for(int i=0;i<v[nd[0]].size();++i){
		
	}
}
int main(){
	cin >> n >> m;
	if(n==1){
		cout << 0;
		return 0;
	}
	cnt=m;
	for(int i=1;i<=m;++i){
		int p,q,c;
		v1[p].push_back(q);
		v1[q].push_back(p);
		a[i].a={p,q};
		a[i].c=c;
	} 
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			cnt++;
			bfs(a[i].c,a[i].a);
		}
	}
	bfs1();
	if(ans==0){
		cout << -1;
	} 
	else cout << ans/2;
	return 0;
}
