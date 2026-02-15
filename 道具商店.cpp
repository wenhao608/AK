#include <bits/stdc++.h>
using namespace std;
int a[510],b[510];
int n,m;
int f[1000010];
int main(){
	memset(f,0x3f,sizeof(f));
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> b[i];
	}
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=250000;j>=a[i];--j){
			f[j]=min(f[j],f[j-a[i]]+b[i]);
		}
	}
	for(int i=250000;i>=1;--i){
		if(f[i]<=m){
			cout << i;
			return 0;
		}
	}
	return 0;
}
