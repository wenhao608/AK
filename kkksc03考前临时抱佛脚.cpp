#include <bits/stdc++.h>
using namespace std;
int e[30],f[20],g[30],h[30];
int sum[5];
int z[30];
int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	for(int i=1;i<=a;++i){
		cin >> e[i];
		sum[1]+=e[i];
	}
	for(int i=1;i<=b;++i){
		cin >> f[i];
		sum[2]+=f[i];
	}
	for(int i=1;i<=c;++i){
		cin >> g[i];
		sum[3]+=g[i];
	}
	for(int j=1;j<=d;++j){
		cin >> h[j];
		sum[4]+=h[j];
	}
	int ans=0;
	for(int i=1;i<=a;++i){
		int x=sum[1]/2;
		for(int j=x/2;j>=e[i];--j){
			z[j]=max(z[j],z[j-e[i]]+e[i]);
		}
		ans+=max(z[x],sum[1]-z[x]);
	}
	memset(z,0,sizeof(z));
	for(int i=1;i<=b;++i){
		int x=sum[2]/2;
		for(int j=x/2;j>=f[i];--j){
			z[j]=max(z[j],z[j-f[i]]+f[i]);
		}
		ans+=max(z[x],sum[2]-z[x]);
	}
	memset(z,0,sizeof(z));
	for(int i=1;i<=c;++i){
		int x=sum[3]/2;
		for(int j=x/2;j>=g[i];--j){
			z[j]=max(z[j],z[j-g[i]]+g[i]);
		}
		ans+=max(z[x],sum[3]-z[x]);
	}
	memset(z,0,sizeof(z));
	for(int i=1;i<=d;++i){
		int x=sum[4]/2;
		for(int j=x/2;j>=h[i];--j){
			z[j]=max(z[j],z[j-h[i]]+h[i]);
		}
		ans+=max(z[x],sum[4]-z[x]);
	}
	memset(z,0,sizeof(z));
	cout << ans;
	return 0;
}
