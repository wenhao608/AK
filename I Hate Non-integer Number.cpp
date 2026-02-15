#include <bits/stdc++.h>
using namespace std;
int n,a[110],f[110][110][110][110];
int main() {
	cin >> n; 
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) f[0][i][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for (int k=0;k<=j;k++)
				for (int l=0;l<j;l++) {
					f[i][j][k][l]+=f[i-1][j][k][l];
					f[i][j][k][l]%=998244353;
					f[i][j][k+1][(l+a[i])%j]+=f[i-1][j][k][l];
					f[i][j][k+1][(l+a[i])%j]%=998244353;
				}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=f[n][i][i][0];
		ans%998244353;
	}
	cout << ans;
	return 0;
}

