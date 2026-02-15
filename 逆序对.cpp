#include <bits/stdc++.h>
using namespace std;
int a[1000010],len=1e6,tr[1000010],b[1000010];
int lowbit(int x){
	return x&(-x);
}
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
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	len=unique(b+1,b+1+n)-1-b;
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans+=(sum(len)-sum(lower_bound(b+1,b+len+1,a[i])-b));
		add(lower_bound(b+1,b+len+1,a[i])-b,1);
	}
	cout << ans;
	return 0;
}
