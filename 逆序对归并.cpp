#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010],b[1000010];
int merge(int l,int r){
	if(l==r) return 0;
	int mid=(l+r)/2;
	int ans=0;
	ans+=merge(l,mid);
	ans+=merge(mid+1,r);
	
	int i=mid,j=r,k=0;
	while(i>=l&&j>=mid+1){
		if(a[i]>a[j]){
			b[++k]=a[i--];
			ans+=j-mid;
		}
		else{
			b[++k]=a[j--];
		}
	}
	while(i>=l){
		b[++k]=a[i--];
	}
	while(j>=mid+1){
		b[++k]=a[j--];
	}
	i=l;
	j=k;
	while(i<=r){
		a[i++]=b[j--];
	}
	return ans;
}
signed main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	
	cout << merge(1,n);

	return 0;
}
