#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b;
}a[10000010];
int f[10000010];
signed main(){
	int t,m;
	cin >> t >> m;
	for(int i=1;i<=m;++i){
		cin >> a[i].a >> a[i].b;
	}
	for(int i=1;i<=m;++i){
		for(int j=a[i].a;j<=t;++j){
			f[j]=max(f[j],f[j-a[i].a]+a[i].b);
		}
	}
	cout << f[t];
	return 0;
}
