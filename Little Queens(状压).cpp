#include <bits/stdc++.h>
using namespace std;
int n,k,ans=0;
void dfs(int id,int row,int l,int r,int sum){
	if(sum==k){
		ans++;
		return ;
	}
	if(id==n+1){
		return ;
	}
	dfs(id+1,row,l>>1,r<<1,sum);
	if(row!=(1<<n)-1){
		int pos=((1<<n)-1)&(~(row|l|r));
		while(pos!=0){
			int p=pos&(-pos);
			pos-=p;
			dfs(id+1,row|p,(l|p)>>1,(r|p)<<1,sum+1);
		}
	}
}
int main(){	
	cin >> n >> k;
	dfs(1,0,0,0,0);
	cout << ans;
	return 0;
} 
