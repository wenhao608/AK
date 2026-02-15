#include <iostream>
#include <algorithm>
using namespace std;
int n,m,ans;
int a[1010][1010],b[1010][1010];
int dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,1,-1,1,-1,1,-1};
void dfs(int x,int y,int sum){
	if(x==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(y==m+1){
		dfs(x+1,1,sum);
		return ;
	}
	dfs(x,y+1,sum);
	if(b[x][y]==0){
		b[x][y]=1;
		for(int i=0;i<=7;++i){
			b[x+dx[i]][y+dy[i]]++;
		}
		dfs(x,y+1,sum+a[x][y]);
		for(int i=0;i<=7;++i){
			b[x+dx[i]][y+dy[i]]--;
		}
		b[x][y]=0;
	} 
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin >> a[i][j];
				b[i][j]=0;
			}
		}
		ans=0;
		dfs(1,1,0);
		cout << ans << '\n';
	}
	return 0;
}
