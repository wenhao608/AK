#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,l;
}a[1000010];
bool cmp(node a,node b){
	return a.l<b.l;
}
int f[1000010];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
int main(){
	int n,m,k;
	cin >>n  >> m >> k;
	for(int i=1;i<=m;++i){
		cin >>a[i].x >> a[i].y >> a[i].l;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	int t=n,ans=0;
	for(int i=1;i<=m;++i){
		if(t==k){
			cout << ans;
			return 0;
		}
		if(find(a[i].y)==find(a[i].x)){
			continue;
		}
		merge(a[i].x,a[i].y);
		t--;
		ans+=a[i].l;
		
	}
	cout << "No Answer";
	return 0;
} 
