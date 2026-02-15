#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}a[1000010];
int f[1000010];
int main(){
	int n,m;
	cin >> m >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].a >> a[i].b;
		a[i].b*=a[i].a;
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=a[i].a;--j){
			f[j]=max(f[j],f[j-a[i].a]+a[i].b);
		}
	}
	int maxn=0;
	for(int i=1;i<=m;++i){
		maxn=max(maxn,f[i]);
	}
	cout << maxn;
	return 0;
}
