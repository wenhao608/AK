#include <bits/stdc++.h>
using namespace std;
int f[2000010][25],a[2000010],Log[2000010];
long long sum(int l,int r){
	int len=r-l+1;
	int log=Log[len];
	return min(f[l][log],f[r-(1<<log)+1][log]);
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		f[i][0]=a[i];
	}
	Log[1]=0;
	for(int i=2;i<=n;++i){
		Log[i]=Log[i/2]+1;
	}
	for(int j=1;j<=Log[n];++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	cout << 0 << '\n';
	for(int i=2;i<=n;++i){
		cout << sum(i-m,i-1) << '\n';
	}
	return 0;
}
