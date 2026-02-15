#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1000010];
int n,a,b,c;
int dfs(int x){
	if(x<=c) return 1;
	if(f[x]) return f[x];
	return f[x]=(dfs(x-a)%signed(1e9+7)+dfs(x-b)%signed(1e9+7))%signed(1e9+7);
}
signed main(){
	cin >> n >> a >> b >> c;
	cout << dfs(n);

	return 0;
}
