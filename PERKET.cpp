#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],ans=1e9;
void dfs(int x,int sum,int y,int chk){
	if(x==n+1){
		if(!chk){
			return ;
		}
		ans=min(ans,abs(sum-y));
		
		return ;
	}
	dfs(x+1,sum,y,chk);
	dfs(x+1,sum*a[x],y+b[x],chk+1);
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> b[i];
	}
	dfs(1,1,0,0);
	cout << ans;
	return 0;
} 
