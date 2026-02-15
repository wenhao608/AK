#include<bits/stdc++.h>
using namespace std;
int l,n,k;
int a[10000010];
bool is_(int b){
	if(b==0){
		return false;
	}
	int ans=0;
	int mu=0;
	for(int i=1;i<n;++i){
		ans+=(a[i+1]-a[i]-1)/b;
		
	}
	return ans<=k;
}
int main(){
	cin >> l >> n >> k;
	int c=0;
	for(int i=1;i<=n;++i) {
		cin >> a[i];
		c=max(c,a[i]-a[i-1]);
	}
	int l=1,r=c,mid,ans=1e9;
	while(l<=r){
		mid=(l+r)/2;
		if(is_(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}
		else l=mid+1;
	}
	cout << ans;
	return 0;
} 
