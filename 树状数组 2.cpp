#include <bits/stdc++.h>
using namespace std;
int tr[1000010],a[1000010];
int n,m;
long long lowbit(int x){
	return x&(-x);
}
void add(int i,int x){//modify
	if(i>n){
		return ;
	}
	tr[i]+=x;
	add(i+lowbit(i),x);
}
long long pre(int x){
	if(x==0){
		return 0;
	}
	return tr[x]+pre(x-lowbit(x));
}
int main(){
	
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=m;++i){
		int t;
		cin >> t;
		if(t==1){
			int x,y,k;
			cin >> x >> y >> k;
			add(x,k);
			add(y+1,-k);
		}
		else{
			int x;
			cin >> x;
			cout << pre(x)+a[x] << '\n';
		}
	}
	return 0;
} 
