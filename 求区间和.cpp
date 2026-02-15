#include <bits/stdc++.h>
using namespace std;
int sum[1000010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		int x;
		cin >> x;
		sum[i]=sum[i-1]+x;
	}
	int m;
	cin >> m;
	while(m--){
		int l,r;
		cin >>  l >> r;
		cout << sum[r]-sum[l-1] << '\n';
	}
	return 0;
} 
