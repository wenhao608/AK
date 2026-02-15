#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int f[100010],siz[100010],dp[100010];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
int cnt=0,a[100010];
int main(){
	cin >> n >> m >> k;
	if(k==0){
		cout << m;
		return 0;
	}
	for(int i=1;i<=n;++i){
		f[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=k;++i){
		int a,b;
		cin >> a >> b;
		if(find(a)!=find(b)){
			siz[find(b)]+=siz[find(a)];
			f[find(a)]=find(b);
			
		}
	}
	for(int i=1;i<=n;++i){
		if(f[i]==i){
			a[++cnt]=siz[i];
		}
	}
	for(int i=1;i<=cnt;++i){
		for(int j=m*2;j>=a[i];--j){
			dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
		}
	}
	int ans=2e9,minn=2e9;
	for(int i=1;i<=2*m;++i){
		if(minn>abs(dp[i]-m)){
			minn=abs(dp[i]-m);
			ans=dp[i];
		}
	}
	if(ans==2e9){
		ans=0;
	}
	cout << ans;
	return 0;
}
