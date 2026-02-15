#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct node{
	int l,r,sum,add;
}b[400010];
int a[100010];
void push_up(int p){
	b[p].sum=b[p*2].sum+b[p*2+1].sum;
}
void build(int p,int l,int r){
	b[p]={l,r,a[l],0};
	if(l==r){
		return ;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
  	b[p].sum=b[p*2].sum+b[p*2+1].sum;
}
void pushdown(int p){
	if(b[p].add){
		int l=p*2;
		b[l].sum+=b[p].add*(b[l].r-b[l].l+1);
		b[l+1].sum+=b[p].add*(b[l+1].r-b[l+1].l+1);
		b[l].add+=b[p].add;
		b[l+1].add+=b[p].add;
		b[p].add=0;
	}
}
void update(int p,int l,int r,int k){
	if(b[p].l>=l&&b[p].r<=r){
		b[p].sum+=(b[p].r-b[p].l+1)*k;
		b[p].add+=k;
		return ;
	}
	int mid=(b[p].l+b[p].r)/2;
	pushdown(p);
	if(l<=mid){
		update(p*2,l,r,k);
	}
	if(r>mid){
		update(p*2+1,l,r,k);
	}
	push_up(p);
}
int q(int p,int l,int r){
	int mid=(b[p].l+b[p].r)/2;
	if(b[p].l>=l&&b[p].r<=r){
		return b[p].sum;
	}
	pushdown(p);
	int sum=0;
	if(l<=mid){
		sum+=q(p*2,l,r);
	}
	if(r>mid){
		sum+=q(p*2+1,l,r);
	}
	return sum;
}
signed main(){
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	build(1,1,n);
	while(m--){
		int t;
		cin >> t;
		if(t==1){
			int x,y,k;
			cin >> x >> y >> k;
			update(1,x,y,k); 
		}
		else{
			int x,y;
			cin >> x >> y;
			cout << q(1,x,y) << '\n';
		}
	}
	return 0;
}
