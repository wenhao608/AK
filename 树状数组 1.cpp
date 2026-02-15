#include <bits/stdc++.h>
using namespace std;
int tr[1000010];
int a[1000010];
int lowbit(int x){
	return x&(-x);
}
int n,m;
void add(int i,int x){//modify
	if(i>n){
		return ;
	}
	tr[i]+=x;
	add(i+lowbit(i),x);
}
long long sum(int x){//pre
	if(x==0){
		return 0;
	}
	return tr[x]+sum(x-lowbit(x));
}
int main(){
	
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		add(i,a[i]);
	} 
	while(m--){
		int k;
		cin >> k;
		if(k==1){
			int x,h;
			cin >> x >> h;
			add(x,h);
		}
		else{
			int x,h;
			cin >> x >> h;
			cout << sum(h)-sum(x-1) << '\n';
		}
	}
	return 0;
}
