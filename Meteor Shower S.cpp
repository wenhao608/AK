#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct node{
	int x,y,z;
}a[1000010];
int m;
int vis[1010][1010];
int bfs(int x,int y){
	queue<array<int,3> > q;
	q.push({x,y,0});
	while(q.size()){
		auto nd=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			if(nd[0]+dx[i]>=0&&nd[1]+dy[i]>=0){
				if(nd[2]+1<vis[nd[0]+dx[i]][nd[1]+dy[i]]){
					if(vis[nd[0]+dx[i]][nd[1]+dy[i]]==0x3f3f3f){
						return nd[2]+1;
					}
					vis[nd[0]+dx[i]][nd[1]+dy[i]]=-1;
					
					q.push({nd[0]+dx[i],nd[1]+dy[i],nd[2]+1});
				}
			}
			
		}
	}
	return -1; 
}
int main(){
	cin >> m;
	memset(vis,0x3f3f3f,sizeof(vis));
	for(int i=1;i<=m;++i){
		cin >> a[i].x >> a[i].y >> a[i].z;
		vis[a[i].x][a[i].y]=min(vis[a[i].x][a[i].y],a[i].z);
		for(int i=0;i<=3;++i){
			vis[a[i].x+dx[i]][a[i].y+dy[i]]=min(vis[a[i].x+dx[i]][a[i].y+dy[i]],a[i].z);
		}
	}
	cout << bfs(0,0);
	return 0;
}
