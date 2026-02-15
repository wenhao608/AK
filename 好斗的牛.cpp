#include <bits/stdc++.h>
using namespace std;
int n,ans=1e9;
struct node{
	int a,b;
}a[110];
int c[110],d[110];
void dfs(int x){
	if(x==n+1){
		int sum=n;
		for(int i=2;i<=n;++i){
			sum+=max(a[d[i]].a,a[d[i-1]].b);
		}
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;++i){
		if(!c[i]){
			c[i]=1;
			d[x]=i;
			dfs(x+1);
			c[i]=0;
			d[x]=0;
		}
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].a;
	}
	for(int i=1;i<=n;++i){
		cin >> a[i].b;
	}
	dfs(1);
	
	
	cout << ans;
	return 0;
} 
