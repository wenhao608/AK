#include <bits/stdc++.h>
using namespace std;
vector<int> v[10010],v2[10010];
int n,m;
int vis[10010];
bool chk;
void bfs(){
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(q.size()){
		int nd=q.front();
		q.pop();
		for(int i=0;i<v[nd].size();++i){
			int o=v[nd][i];
			if(vis[o]==0){
				vis[o]=1;
				q.push(o);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(vis[i]==)
	}
}
int main(){
	cin >> n >> m;
	while(true){
		int a,b;
		cin >> a >> b;
		if(a==0&&b==0){
			break; 
		}
		v[a].push_back(b);
		v2[b].push_back(a);
	}
	bfs();
	if(!chk){
		cout << "No";
		return 0; 
	}
	bfs2();
	if(!chk){
		cout << "No";
	}
	else{
		cout << "Yes";
	}
	return 0;
} 
