#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[1000010];
int f[1000010];
bool cmp(node a,node b){
	return a.c>b.c;
}
int b[1000010];
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
}
void ad(int x,int y){
	x=find(x);
	y=find(y);
	f[x]=y;
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	for(int i=1;i<=m;++i){
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(find(a[i].a)==find(a[i].b)){
			cout << a[i].c;
			return 0;
		}
		if(!b[a[i].a]){
			b[a[i].a]=a[i].b;
		}
		else{
			ad(b[a[i].a],a[i].b);
		}
		if(!b[a[i].b]){
			b[a[i].b]=a[i].a;
		}
		else{
			ad(b[a[i].b],a[i].a);
		}
	}
	cout << 0;
	return 0;
} 
