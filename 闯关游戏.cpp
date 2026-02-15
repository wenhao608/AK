#include <bits/stdc++.h>
using namespace std;

int n,m,a[110],b[100010],mx[1000010];
int main(){
	cin >>n >> m;
	for(int i=0;i<m;++i){
		cin >> a[i];
	}
	for(int i=0;i<n;++i){
		cin >> b[i];
		mx[i]=-1e9;
	}
	mx[n]=-1e9;
	mx[0]=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			int ed=min(n,i+a[j]);
			mx[ed]=max(mx[ed],mx[i]+b[i]);
		}
	}
	cout << mx[n];
	return 0;
}
