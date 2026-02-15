#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
int w[110],v[110];
signed main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> w[i] >> v[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=w[i];--j){
			a[j]=max(a[j],a[j-w[i]]+v[i]);
		}
	}
	cout << a[m];
	return 0;
} 
