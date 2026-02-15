#include <bits/stdc++.h>
using namespace std;
int a[110],f[2000010];
int main(){
	int n,x;
	cin >> n >> x;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	f[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=x;++j){
			f[j+a[i]]+=f[j];
			f[j+a[i]]%=1000000007;
		}
	}
	cout << f[x];
	return 0;
} 
