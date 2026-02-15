#include <iostream>
using namespace std;
char a[1010][1010];
int ans=0,b[1000100];
int n,k;
bool chk(int x,int y){
	for(int i=1;i<x;++i){
		if(b[i]==y){
			return false;
		}
	}
	return true;
}
void dfs(int id,int x){
	if(x==k+1){
		ans++;
		return ;
	}
	if(id==n+1){
		return ;
	}
	dfs(id+1,x);
	for(int i=1;i<=n;++i){
		if(a[id][i]=='#'&&chk(id,i)){
			b[id]=i;
			dfs(id+1,x+1);
			b[id]=0;
		}
	}
}
int main(){
	
	while(cin >> n >> k){
		if(n==-1&&k==-1){
			return 0;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				cin >> a[i][j];
			}
		}
		ans=0;
		dfs(1,1);
		cout << ans << '\n';
	}
	return 0;
}
