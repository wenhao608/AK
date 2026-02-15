#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int n,k;
int chk(int x){
	if(x<1e-5) return true;
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[i]/x;
	}
	
	return ans;
}
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		double x;
		cin >> x;
		a[i]=(int)(x*100);
	}
	int l=0,r=100000,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(chk(mid)>=k){
			ans=max(ans,mid);
			l=mid+1;
		}
		else{
			r=mid-1; 
		}
	}
	cout << ans/100.0;
	return 0;
} 
