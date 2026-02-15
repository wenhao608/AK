#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,t;
}a[1000010];
int ans=0;
int b[1000010];
int cnt=0;
bool cmp(node a,node b){
	if(a.t!=b.t) return a.t<b.t;
	return a.x<b.x;
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		int x,t;
		cin >> x >> t;
		if(x>t){
			continue;
		}
		a[++cnt].x=x;
		a[cnt].t=t;
	}
	memset(b,0x3f,sizeof(b));
	b[ans]=0;
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		int l=0,r=ans,ri=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(b[mid]<=a[i].t-a[i].x){
				r=mid-1;
				ri=mid;
			}
			else{
				l=mid+1;
				
			}
		}
		if(ri==-1){
			continue;
		}b[ri+1]=min(b[ri+1],a[i].t-a[i].x);
		ans=max(ans,ri+1);
	}
	cout << ans;
	return 0;
}
