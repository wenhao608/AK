#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],b[100010],c[100010];
int f[10010][3];
signed main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> b[i] >> c[i];
	}
	f[1][1]=a[1];
	f[1][2]=b[1];
	f[1][2]=c[1];
	for(int i=2;i<=n;++i){
		f[i][1]=max(f[i-1][2],f[i-1][3])+a[i];
		f[i][2]=max(f[i-1][1],f[i-1][3])+b[i];
		f[i][3]=max(f[i-1][1],f[i-1][2])+c[i];
	}
	cout << max(f[n][1],max(f[n][2],f[n][3]));
	return 0;
}
