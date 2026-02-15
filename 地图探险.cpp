#include <bits/stdc++.h>
using namespace std;
char c[1010][1010];
int vis[1010][1010];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

bool chk(int x,int y,int n,int m){
	if(x>n||x<1||y>m||y<1){
		return false;
	}
	if(c[x][y]=='x'){
		return false;
	}
	return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int n,m,k;
		cin >> n >> m >> k;
		int x,y,d;
		cin >> x >> y >> d;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin >> c[i][j];
			}
		}
		
		vis[x][y]=1;
		for(int i=1;i<=k;++i){
			int x_=x+dx[d],y_=y+dy[d];
			if(chk(x_,y_,n,m)){
				x=x_;
				y=y_;
				vis[x][y]=1;
				
			}
			else{
				d=(d+1)%4;
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				ans+=vis[i][j];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
