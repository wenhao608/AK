#include <bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[1000010];
bool cmp(node a,node b){
	return a.z<b.z;
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
	int n,m,s,t;
	cin >> n >> m >>s >> t;
	for(int i=1;i<=m;++i){
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	for(int i=1;i<=m;++i){
		if(find(a[i].y)==find(a[i].x)){
			continue;
		}
		merge(a[i].x,a[i].y);
		if(find(s)==find(t)){
			cout << a[i].z << '\n';
			return 0;
		}
	}
	return 0;
}
