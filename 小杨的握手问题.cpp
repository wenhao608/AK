#include <bits/stdc++.h>
using namespace std;
#define int long long
int tr[10000010];
int lowbit(int x){
	return x&-x;
}
int n;
void modify(int p,int x=1){
	if(p>n){
		return ;
	}
	tr[p]+=x;
	modify(p+lowbit(p),x);
}
int pre(int p){
	if(p==0){
		return 0;
	}
	return tr[p]+pre(p-lowbit(p));
}
signed main(){
	cin >> n;
	int ans=0;
	for(int i=1;i<=n;++i){
		int x;
		cin >> x;
		x++;
		
		ans+=pre(x-1);
		modify(x);
	}
	cout << ans;
	return 0;
} 
