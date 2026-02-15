#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
int b[1000010],vis[1000010],chk[1000010];
int n,m,s,t;
struct node{
	int x,y;
}a[1000010];
bool bfs(){
	queue<int> q;
	q.push(s);
	while(q.size()){
		int d=q.front();
		q.pop();
		for(int i=0;i<v[d].size();++i){
			if(vis[v[d][i]]==0){
				vis[v[d][i]]=1;
				b[v[d][i]]=b[d]+1;
				q.push(v[d][i]);
			}
		}
	}
	return b[t]==0;
}
int main(){
	
	cin >> n >> m >> s >> t;
	for(int i=1;i<=m;++i){
		int x,y;
		cin >> x >> y;
		a[i].x=x;a[i].y=y;
		v[x].push_back(y);
		v[y].push_back(x);
	} 
	if(bfs()){
		cout << m;
		for(int i=1;i<=m;++i){
			cout << 1 << ' ' << m << '\n';
		}
		return 0;
	}
	cout << b[t] << '\n';
	for(int i=1;i<b[t];++i){
		int sum=0;
		for(int j=1;j<=m;++j){
			if(b[a[j].x]==i&&b[a[j].y]==i+1){
				sum++;
			}
		}
		cout << sum << ' ';
		for(int j=1;j<=m;++j){
			if(b[a[j].x]==i&&b[a[j].y]==i+1){
				chk[j]=1;
				cout << j << ' ';
			}
		}
		cout << '\n';
	}
	int sum=0;
	for(int i=1;i<=m;++i){
		if(chk[i]==0){
			sum++;
		}
	}
	cout << sum << ' ';
	for(int i=1;i<=m;++i){
		if(chk[i]==0){
			cout << i << ' ';
		}
	}
	return 0;
} 
