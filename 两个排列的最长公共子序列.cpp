#include <bits/stdc++.h>
using namespace std;
map<int,int> ma;
int a[100010];
int ans[100010],cnt=0;
int f[100010];
int find(int x){ 
	if(a[x]>ans[cnt]){
		return cnt+1;
	}
	if(cnt==0||ans[1]<a[x]){
		return 1;
	}
	int l=1,r=cnt,sum=1e9;
	while(l<=r){
		int mid=(l+r)/2;
		if(ans[mid]<=a[x]){
			l=mid+1;
		}
		else{
			sum=mid;
			r=mid-1;
		}
	}
	return sum;
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		int b;
		cin >> b;
		ma[b]=i;
	}
	for(int i=1;i<=n;++i){
		int b;
		cin >> b;
		a[i]=ma[b];
	}
	for(int i=1;i<=n;++i){
		int x=find(i);
		f[i]=max(f[x-1]+1,1);
		if(x>cnt){
			cnt++;
			ans[cnt]=a[i];
		}
		else ans[x]=min(ans[x],a[i]);
	}
	cout << cnt;
	return 0;
}
