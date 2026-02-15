#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010],sum[1000010];
int read(){
	int f=1,x=0;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return f*x;
}
signed main(){
	sum[0]=1;
	int n;
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		for(int j=sqrt(a[i]);j>=1;--j){
			if(a[i]%(j*j)==0){
				a[i]/=(j*j);
				break;
			}
		}
		int j=__gcd(sum[i-1],a[i]);
		sum[i]=sum[i-1]*a[i]/j/j;
	} 
	long long ans=0;
	map<int,int> m;
	m[1]++;
	for(int i=1;i<=n;++i){
		ans+=m[sum[i]];
		m[sum[i]]++;
	}
	printf("%lld",ans);
	return 0;
}
