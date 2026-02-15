#include <bits/stdc++.h>
using namespace std;
int n,m,t,stx,sty,edx,edy;
int a[1010][1010],ans=0;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool chk(int x,int y){
	if(x<1||y<1||x>n||y>m){
		return false;
	}
	return !a[x][y];
}
void dfs(int x,int y){
	if(x==edx&&y==edy){
		ans++;
		return ;
	}
	for(int i=0;i<=3;++i){
		int x_=x+dx[i],y_=y+dy[i];
		if(chk(x_,y_)){
			a[x_][y_]=1;
			dfs(x_,y_);
			a[x_][y_]=0;
		}
	}
}
int main(){
	cin >> n >> m >> t;
	cin >> stx >> sty >> edx >> edy;
	while(t--){
		int x,y;
		cin >> x >> y;
		a[x][y]=1;
	}
	a[stx][sty]=1;
	dfs(stx,sty);
	cout << ans;
	return 0; 
}
