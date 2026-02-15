#include <bits/stdc++.h>
using namespace std;
int n,k,a[110],ans=0;
char b[110][110];
bool chk(int x,int y){
	for(int i=1;i<y;++i){
		if(a[i]==x){
			return false;
		}
	}
	return true;
}
void dfs(int x,int sum){
	if(x==n+1){
		if(sum==k){
			ans++;
		}
		
		return ;
	}
	dfs(x+1,sum);
	for(int i=1;i<=n;++i){
		if(b[x][i]=='#'&&chk(i,sum)){
			a[sum]=i;
			dfs(x+1,sum+1);
			a[sum]=0;
		}
	}
}
int main(){
	while(1){
		ans=0;
		cin >> n >> k;
		if(n==-1&&k==-1){
			break;
		}
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				cin >> b[i][j];
			}
		}
		dfs(1,0);
		cout << ans << '\n';
	}
	return 0;
}
