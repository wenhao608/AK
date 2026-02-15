#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
int ans[1000010],b[1000010];
struct node{
	int dis,x;
	bool operator<(const node b) const{
		return dis>b.dis;
	}
};
int n,m;
bool chk[1000010];
void bfs(){
	memset(b,0x3f,sizeof(b));
	memset(chk,false,sizeof(chk));
	priority_queue<node> q;
	q.push({0,1});
	ans[1]=1;
	while(q.size()){
		int y=q.top().x,u=q.top().dis;
		q.pop();
		if(chk[y]){
			continue;
		}
		chk[y]=true;
		for(int i=0;i<v[y].size();++i){
			if(u+1<b[v[y][i]]){
				ans[v[y][i]]=ans[y];
				b[v[y][i]]=u+1;
				q.push({u+1,v[y][i]});
			}
			else if(u+1==b[v[y][i]]){
				ans[v[y][i]]=(ans[v[y][i]]+ans[y])%100003;
			}
		}
	}
}
int main(){
	
	cin >> n >> m;
	while(m--){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs(); 
	ans[1]=1;
	for(int i=1;i<=n;++i){
		cout << ans[i]%100003 << '\n';
	}
	return 0;
}
