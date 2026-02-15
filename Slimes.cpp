#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010],sum[410];
int f[410][410];
signed main(){
	memset(f,0x3f,sizeof(f));
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		sum[i]=sum[i-1]+a[i];
		f[i][i]=0;
	}
	for(int len=2;len<=n;++len){
		for(int i=1;i<=n-len+1;++i){
			int j=len+i-1;
			for(int k=i;k<j;++k){
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	cout << f[1][n];
	return 0;
}
