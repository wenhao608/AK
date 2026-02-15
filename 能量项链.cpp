#include<bits/stdc++.h>
using namespace std;
int a[410];
int f[410][410];
int n;
int main(){
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> a[i];
		a[i+n]=a[i];
		f[i][1]=0;
	}
	for(int j=2;j<=n;++j){
		for(int i=0;i<n;++i){
			for(int k=1;k<j;++k){
				f[i][j]=max(f[i][j],f[i][k]+f[(i+k)%n][j-k]+a[j+i]*a[k+i]*a[i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;++i){
		ans=max(ans,f[i][n]);
	}
	cout << ans;
	return 0;
}
