#include <bits/stdc++.h>
using namespace std;
int n,m;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int a[510][510],vis[510][510];
string dfs(int x,int y){
	vis[x][y]=1;
	string ans="";
	for(int i=0;i<4;++i){
		if(x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=m&&!vis[x+dx[i]][y+dy[i]]&&(a[x][y]==a[x+dx[i]][y+dy[i]])){
			char c=i+'0';
			ans=ans+c;
			ans=ans+dfs(x+dx[i],y+dy[i]);
		}
	}
	return ans+' ';
}
int main(){
	set<string> s;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(!vis[i][j]){
				s.insert(dfs(i,j));
			}
		}
	}
	cout << s.size();
	return 0;
} 
