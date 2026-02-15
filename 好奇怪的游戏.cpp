#include <bits/stdc++.h>
using namespace std;
int dx[12]={1,1,2,2,2,2,-1,-1,-2,-2,-2,-2};
int dy[12]={-2,2,-2,-1,1,2,-2,2,-1,1,-2,2};
int vis[30][30];
int bfs(int x,int y){
	memset(vis,0,sizeof(vis));
	queue<array<int,3> > q;
	q.push({x,y,0});
	while(q.size()){
		auto nd=q.front();
		q.pop();
		if(nd[0]==1&&nd[1]==1){
			return nd[2];
		}
		for(int i=0;i<12;++i){
			int x_=nd[0]+dx[i],y_=nd[1]+dy[i];
			if(x_>=1&&x_<=25&&y_>=1&&y_<=25&&vis[x_][y_]==0){
				vis[x_][y_]=1;
				q.push({x_,y_,nd[2]+1});
			}
		}
	}
}
int main(){
	int x,y,x_,y_;
	cin >> x >> y >> x_ >> y_;
	cout << bfs(x,y) << '\n';
	cout << bfs(x_,y_);
	return 0;
} 
