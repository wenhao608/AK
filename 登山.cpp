#include <bits/stdc++.h>
using namespace std;
int a[1010],f[1010],b[1010],c[1010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	f[1]=1;
	for(int i=2;i<=n;++i){
		f[i]=1;
		for(int j=1;j<i;++j){
			if(a[i]>a[j]){
				f[i]=max(f[i],f[j]+1); 
			}
		}
	}
	int maxn=0;
	for(int i=1;i<=n;++i){
		maxn=max(maxn,f[i]);
		b[i]=maxn;
	}
	f[1]=1;
	for(int i=2;i<=n;++i){
		f[i]=1;
		for(int j=1;j<i;++j){
			if(a[i]<a[j]){
				f[i]=max(f[i],f[j]+1); 
			}
		}
	}
	maxn=0;
	for(int i=1;i<=n;++i){
		maxn=1;
		for(int j=i+1;i<=n;++i){
			if(a[j-1]<a[j]){
				maxn++;
			}
		}
		f[i]=maxn;
	}
	maxn=0;
	for(int i=n;i>=1;--i){
		maxn=max(maxn,f[i]);
		c[i]=maxn;
	}
	for(int i=1;i<=n;++i){
		maxn=max(b[i]+c[i+1],maxn);
	}
	cout << maxn;
	return 0;
}
