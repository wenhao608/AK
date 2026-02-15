#include <bits/stdc++.h>
using namespace std;
double a[100010],f[3010][3010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i]; 
	}
	f[0][0]=1;
	f[0][1]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=i;++j){
			f[i][j]=f[i-1][j]*(1-a[i])+f[i-1][j-1]*a[i];
		}
	}
	double ans=0;
	for(int i=(n+1)/2;i<=n;++i){
		ans+=f[n][i];
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
} 
