#include <bits/stdc++.h>
using namespace std;
int n,k[1000010],f[1000010];
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> k[i];
	}
	sort(k+1,k+n+1);
	for(int i=1;i<=n;++i){
		f[i]=max(f[i-1],k[i]-f[i-1]);
	}
	cout << f[n];
	return 0;
}
