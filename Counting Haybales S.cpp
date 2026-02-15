#include <bits/stdc++.h>
using namespace std;
int tr[1000010];
int a[3000010],b[3000010],len;
int lowbit(int x){
	return x&(-x);
}
int n,q;
void add(int i,int x){
	if(i>len){
		return ;
	}
	tr[i]+=x;
	add(i+lowbit(i),x);
}
long long sum(int x){
	if(x==0){
		return 0;
	}
	return tr[x]+sum(x-lowbit(x));
}
int main(){
	cin >> n >> q;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=q;++i){
		cin >> a[n+i*2-1] >> a[n+i*2];
		a[n+i*2-1]-=1;
		b[n+i*2-1]=a[n+i*2-1];
		b[n+i*2]=a[n+i*2];
	}
	sort(b+1,b+1+n+q*2);
	len=unique(b+1,b+1+n+q*2)-1-b;
	for(int i=1;i<=n;++i){
		add(lower_bound(b+1,b+len+1,a[i])-b,1);
	}
	for(int i=1;i<=q;++i){
		cout << sum(lower_bound(b+1,b+len+1,a[i*2+n])-b)-sum(lower_bound(b+1,b+len+1,a[n+i*2-1])-b) << '\n';
	}
	return 0;
}
