#include <bits/stdc++.h>
using namespace std;
int f[1000010];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	for(int i=1;i<=m;++i){
		int x,y;
		cin >> x >> y;
		f[find(x)]=find(y);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(f[i]==i){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
