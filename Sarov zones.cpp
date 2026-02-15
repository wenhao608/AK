#include<bits/stdc++.h>
using namespace std;
struct node{
	int w,q,id,ans;
}a[1000010];
struct node2{
	int level,peo,id;
}b[1000010];
bool cmp(node a,node b){
	return a.w>b.w;
}
bool pmc(node2 c,node2 d){
	return c.level<d.level;
}
bool cpm(node a,node b){
	return a.id<b.id;
} 
int main(){
//	multiset<int>s;
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> b[i].peo;
	}
	for(int i=1;i<=n;++i){
		cin >> b[i].level;
		b[i].id=i;
	}
	for(int i=1;i<=n;++i){
		a[i].id=i;
		cin >> a[i].q;
	}
	for(int i=1;i<=n;++i){
		cin >> a[i].w;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,pmc);
	for(int i=1;i<=n;++i){
	//	cout << a[i].id << ' ';
		if(a[i].q<b[1].level){
			for(int j=n;j>=1;--j){
				if(b[j].peo){
					b[j].peo--;
					a[i].ans=b[j].id;
					// << j << ' ';
					break;
				}
			}
			continue;
		}
		for(int j=n;j>=1;--j){
			if(b[j].peo&&a[i].q>b[j].level){
				a[i].ans=b[j].id;/// << j << ' ';
				b[j].peo--;
			}
		}
	} 
	sort(a+1,a+1+n,cpm);
	for(int i=1;i<=n;++i){
		cout << a[i].ans << ' ';
	}
	return 0;
} 
