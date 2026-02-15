#include <bits/stdc++.h>
using namespace std;
#define int long long
char c[1010][1010];
int a[1010][1010];
int n,m;
signed main(){
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin >> c[i][j];
		}
	}
	a[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1&&j==1){
				continue;
			}
			a[i][j]=a[i-1][j]+a[i][j-1];
			if(c[i][j]=='#'){
				a[i][j]=0;
			}
		}
	}
	cout << a[n][m];
} 
