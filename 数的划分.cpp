#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
void dfs(int id,int x,int sum){
	if(id==k+1){
		if(sum==n) ans++;
		return ;
	}
	if((n-sum)/(k-id+1)<x){
		return ;
	}
	for(int i=x;i<=n-sum;++i){
		dfs(id+1,i,sum+i);
	} 
}
int main(){
	cin >> n >>k;
	dfs(1,1,0);
	cout << ans;
	return 0;
} 
