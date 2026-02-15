#include <bits/stdc++.h>
using namespace std;
int n,f[1000010][30],a[1000010],Log[1000010];
int gcd(int x,int y){
	if(y==0){
		return x;
	}
	return gcd(y,x%y);
}
long long sum(int l,int r){
	int len=r-l+1;
	int log=Log[len];
	return gcd(f[l][log],f[r-(1<<log)+1][log]);
}

int main(){
	int m;
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
			f[i][j]=gcd(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		cout << sum(l,r) << '\n';
	}
	return 0;
}

