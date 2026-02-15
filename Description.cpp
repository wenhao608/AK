#include <bits/stdc++.h>
using namespace std;
int a[1000010],arr[1000010],d[1000010],e[1000010];
struct node{
	int a,b;
}b[1000010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i*2-1] >> a[i*2];
		b[i].a=a[i*2-1];
		b[i].b=a[i*2];
	} 
	sort(a+1,a+1+n*2);
	int cnt=unique(a+1,a+1+n*2)-(a+1);
	for(int i=1;i<=n;++i){
		b[i].a=lower_bound(a+1,a+1+cnt,b[i].a)-a;
        b[i].b=lower_bound(a+1,a+1+cnt,b[i].b)-a;
        d[b[i].a]++;
        d[b[i].b+1]--;
	}
	int maxn=0;
	for(int i=1;i<=cnt+1;++i){
		e[i]=d[i]+e[i-1];
		maxn=max(maxn,e[i]);
	}
	cout << maxn;
	return 0;
} 
