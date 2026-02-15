#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],b[100010];
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	b[1]=0;
	b[2]=abs(b[2]-b[1]);
	for(int i=3;i<=n;++i){
		b[i]=min(b[i-1]+abs(a[i]-a[i-1]),b[i-2]+abs(a[i]-a[i-2]));
	} 
	cout << b[2];
	return 0;
}
