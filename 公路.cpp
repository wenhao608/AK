#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int dis,pri;
}a[1000010];
signed main(){
	int n,d;
	cin >> n >> d;
	a[1].dis=0;
	for(int i=2;i<=n;++i){
		cin >> a[i].dis;
		a[i].dis=a[i-1].dis+a[i].dis;
	}
	for(int i=1;i<=n;++i){
		cin >> a[i].pri;
	}
	int sum=0,minn=a[1].pri,ans=0;
	for(int i=2;i<=n;++i){
		if(sum<a[i].dis){
			ans+=(a[i].dis-sum+d-1)/d*minn;
			sum=sum+(a[i].dis-sum+d-1)/d*d;
			
		}
		minn=min(minn,a[i].pri);
	}
	cout << ans;
	return 0;
} 
