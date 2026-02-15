#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int f[1000010];
int main(){
	int n,x;
	cin >> n >> x;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=1;i<=x;++i){
		for(int j=1;j<=n;++j){
			if(i<a[j]){
				break;
			}
			f[i]+=f[i-a[j]];
			f[i]%=1000000007
;		}
	}
	cout << f[x];
	return 0;
}
