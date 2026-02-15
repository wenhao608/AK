#include <bits/stdc++.h>
using namespace std;
struct node{
	int id,c,l;
}a[1010];
long long f[2010];
int ans=1e9,n,l;
int main(){
	int sum=0;
	cin >> n >> l;
	for(int i=1;i<=n;++i){
		f[i]=1e9;
		a[i].id=i;
		scanf("%d%d",&a[i].c,&a[i].l) ;
		a[i].l=min(a[i].l,l);
		sum+=a[i].l;
	}
	if(sum<l){
		cout << "no solution";
		return 0;
	}
	for(int i=1;i<=l;i++){
		f[i]=1e9;
	}
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=l;j>=0;--j){
			f[min(j+a[i].l,l)]=min(f[j]+a[i].c,f[min(j+a[i].l,l)]);
		}
	}
	ans=f[l];
	if(ans==1e9){
		cout << "no solution";
	}
	else{
		cout << ans;
	}
	return  0;
}
