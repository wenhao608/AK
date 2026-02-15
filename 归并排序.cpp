#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010];
void merge(int l,int r){
	if(l==r) return ;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	int i=l,j=mid+1,k=0;
	while(i<=mid&&j<=r){
		if(a[i]<=a[j]){
			b[++k]=a[i++];
		}
		else{
			b[++k]=a[j++];
		}
	}
	while(i<=mid){
		b[++k]=a[i++];
	}
	while(j<=r){
		b[++k]=a[j++];
	}
	i=l;
	j=1;
	while(j<=k){
		a[i++]=b[j++];
	}
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	
	merge(1,n);
	for(int i=1;i<=n;++i){
		cout << a[i] << ' ';
	} 
	return 0;
}
