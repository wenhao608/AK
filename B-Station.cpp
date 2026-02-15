#include <bits/stdc++.h>
using namespace std;
int w[1000010],l[1000010],p[1000010],sum[1000010];
int n;
int chk(int mid){
	int ans=0;
	for(int i=mid;i<=n;++i){
		if(sum[i]-sum[mid-1]<=l[i]){
			ans+=p[i];
		}
	}
	return ans;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> w[i] >> l[i] >> p[i];
		sum[i]=sum[i-1]+w[i];
	}
	int ans=1e9,ans1=0;
	for(int i=1;i<=n;++i){
		int t=chk(i);
		if(t<ans){
			ans=t;
			ans1=i;
		}
	}
	for(int i=ans1;i<=n;++i){
		if(sum[i]-sum[ans1-1]<=l[i]){
			cout << i << '\n';
		}
	}
	return 0;
}
