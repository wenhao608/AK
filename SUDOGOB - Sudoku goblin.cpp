#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int an[15][15];
int b[15][15];
int lc[15][15];//行1-9状态
int rc[15][15];//列1-9状态
int z[15][15];//九宫格1-9状态
int jiu[15][15]={
	{},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9},
};//(i,j)在那个九宫格 
int ans=0;
void dfs(int x,int y){
	if(x==10){
		ans++;
		if(ans==1){
			for(int i=1;i<=9;++i){
				for(int j=1;j<=9;++j){
					an[i][j]=a[i][j];
				}
			}
		}
		return ;
	}
	if(y==10){
		dfs(x+1,1);
		return ;
	}
	if(b[x][y]==1){
		dfs(x,y+1);
		return ;
	}
	for(int i=1;i<=9;++i){
		if(z[jiu[x][y]][i]==1||lc[x][i]==1||rc[y][i]==1){
			continue;
		}
		z[jiu[x][y]][i]=1;
		lc[x][i]=1;
		rc[y][i]=1;
		a[x][y]=i;
		dfs(x,y+1);
		z[jiu[x][y]][i]=0;
		lc[x][i]=0;
		rc[y][i]=0;
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		ans=0;
		memset(z,0,sizeof(z));
		memset(rc,0,sizeof(z));
		memset(lc,0,sizeof(z));
		memset(b,0,sizeof(b));
		for(int i=1;i<=9;++i){
			for(int j=1;j<=9;++j){
				cin >> a[i][j];
				if(a[i][j]!=0){
					b[i][j]=1;
					z[jiu[i][j]][a[i][j]]=1;
					lc[i][a[i][j]]=1;
					rc[j][a[i][j]]=1;
				}
			}
		}
		dfs(1,1);
		cout << ans << '\n';
		if(ans==1){
			for(int i=1;i<=9;++i){
				for(int j=1;j<=9;++j){
					cout << an[i][j] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
} 
