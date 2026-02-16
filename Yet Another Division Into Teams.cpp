#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int id,v,c;
}a[1000010];
bool cmp(node a,node b){
	return a.v<b.v;
}
int f[1000010];
bool pmc(node a,node b){
	return a.id<b.id;
}
int from[1000010];
signed main(){
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	a[0].c=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	a[1].c=1;
	a[2].c=1;
	a[3].c=1;
	for(int i=3;i<=n;++i){
		for(int j=max((int)0,(int)(i-5));j<=i-3;++j){
			if(f[i]>f[j]+a[i].v-a[j+1].v){
				f[i]=f[j]+a[i].v-a[j+1].v;
				from[i]=j;
				
			}
		}
	}
	int cnt=0,cur=n;
	while(cur>0){
		cnt++;
		int pre=from[cur];
		for(int k=pre+1;k<=cur;++k){
			a[k].c=cnt;
		}
		cur=pre;
	}
	cout<< f[n] << ' ' << cnt << '\n';
	sort(a+1,a+1+n,pmc);
	for(int i=1;i<=n;++i){
		cout << a[i].c << ' ';
	}
	return 0;
} 
