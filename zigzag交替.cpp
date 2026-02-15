#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int ans=2;
	for(int i=2;i<n;++i){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			ans++;
		}
		if(a[i]<a[i-1]&&a[i]<a[i+1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
