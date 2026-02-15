#include <bits/stdc++.h>
using namespace std;
int a[1000010],n,len[1000010],cnt=0,q[1000010];
int main(){
	cin >> n;
	int l=1,r=n,mid;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	q[0]=-2e9;
	for(int i=1;i<=n;++i){
		r=cnt;
		l=0;
		while(l<r){
			mid=(1+l+r)/2;
			if(a[i]>=q[mid]){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		if(q[l]!=a[i]){
			len[++cnt]=1;
			q[cnt]=a[i]+1;
		} 
		else {
			len[l]++;
			q[l]++;
		}
	}
	int ans=1e9;
	for(int i=1;i<=cnt;i++) {
		ans=min(ans,len[i]);
	}
	cout << ans;
	return 0;
}
