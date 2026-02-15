#include <iostream>
#include <calgorithm>
#include <cstring>
using namespace std;
int n,c,ans=-1e9;
int s[15][15];
int dx[6]={-1,-1,0,0,1,1},dy[6]={-1,0,-1,1,0,1},vis[20][20];
/*
x
z z
z y z
x z z x 
*/
int cnt(int x,int y,int st){
	vis[x][y]=1;
	int r=0;
	for(int i=0;i<6;++i){
		
		if(s[x+dx[i]][y+dy[i]]==st&&vis[x+dx[i]][y+dy[i]]==0){
			int t=cnt(x+dx[i],y+dy[i],st);
			if(t==0){
				return 0;
			}
			else{
				r+=t;
			}
		}
		if(s[x+dx[i]][y+dy[i]]==0){
			return 0;
		}
	}
	return r+1;
}

int dfs(int x,int y){
	int sum=0;
	for(int i=0;i<6;++i){
		int x_=x+dx[i],y_=y+dy[i];
		if(s[x_][y_]!=0&&s[x_][y_]!=c&&vis[x_][y_]==0&&s[x_][y_]!=-1){
			sum+=cnt(x_,y_,s[x_][y_]);
		}
	}
	return sum-cnt(x,y,c);
}
int main(){
	while(cin >> n >> c){
		if(n==0&&c==0){
			break;
		}
		memset(s,-1,sizeof(s));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				cin >> s[i][j];
				vis[i][j]=0;
			}
		}
		ans=-1e9;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=i;++j){
				if(s[i][j]==0){
					s[i][j]=c;
					ans=max(ans,dfs(i,j));
					s[i][j]=0;
					memset(vis,0,sizeof(vis));
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
