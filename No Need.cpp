#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int f[5010],sum[5010][5010],g[5010][5010];
int main(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	g[n+1][0]=1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<k;++j){
			g[i][j]=g[i+1][j];
			if(j>=a[i]&&g[i+1][j-a[i]]){
				g[i][j]=1;
			}
		}
	}
	for(int i=0;i<=n+1;++i){
		for(int j=0;j<k;++j){
			sum[i][j]=sum[i][max(0,j-1)]+g[i][j];
		}
	}
	int ans=0;
	f[0]=1;
	for(int i=1;i<=n;++i){
		if(a[i]>=k){
			ans++;
			continue;
		}
		for(int w=0;w<k;++w){
			if(f[w]){
				int l=max(0,k-a[i]-w);
				int r=k-1-w;
				if(sum[i+1][r]-(l==0?0:sum[i+1][l-1])){
					ans++;
					break;
				}
			}
		}
		for(int j=k-1;j>=a[i];--j){
			f[j]=f[j]|f[j-a[i]];
		}
	}
	cout << n-ans;
	return 0;
}
