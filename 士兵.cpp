#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[1000010];
bool cmp(node a,node b){
	return a.x<b.x;
}
bool pmc(node a,node b){
	return a.y<b.y;
}
int main(){
	int n,ans=0;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].x >> a[i].y;
	}
	int mid;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		a[i].x-=i;
	}
	mid=a[n/2+1].x;
	for(int i=1;i<=n;++i){
		ans+=abs(a[i].x-mid); 
	}
	sort(a+1,a+1+n,pmc);
	mid=a[n/2+1].y;
	for(int i=1;i<=n;++i){
		ans+=abs(a[i].y-mid); 
	}
	cout << ans;
	return 0;
}
