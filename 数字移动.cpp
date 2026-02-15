#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n;
bool chk(int x){
	vector<int> v;
	for(int i=1;i<=n;++i){
		if(a[i]>x){
			v.push_back(a[i]);
		}
	}
	for(int i=0;i<(int)v.size();i+=2){
		if(v[i]!=v[i+1]){
			return false;
		}
	}
	return true;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int l=1,r=n,ans=1e9;
	while(l<=r){
		int mid=(l+r)/2;
		if(chk(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout << ans;
	return 0;
} 
