#include <bits/stdc++.h>
using namespace std;
int n,Log[50010];
string a[50010],f[50010][30];
string Max(string x,string y){
	string c,d;
	for(int i=0;i<(int)x.size();++i){
		c+=tolower(x[i]);
	}
	for(int i=0;i<(int)y.size();++i){
		d+=tolower(y[i]);
	}
	if(c>d){
		return x;
	}return y;
}
string sum(int l,int r){
	int len=r-l+1;
	int loG=Log[len];
	return Max(f[l][loG],f[r-(1<<loG)+1][loG]);
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
			f[i][j]=Max(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		cout << sum(l,r) << '\n';
	}
	return 0;
}

