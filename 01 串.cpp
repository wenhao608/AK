#include <bits/stdc++.h>
using namespace std;
int n,a0,b0,l0,a1,b1,l1,dis[1000010],cnt=0;
struct node{
	int u,v,w;
}a[100010];
int main(){
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	cin >> n >> a0 >> b0 >> l0 >> a1 >> b1 >> l1;
	for(int i=1;i<=n;++i){
		a[++cnt]={i,i-1,0};
		a[++cnt]={i-1,i,1};
	}
	for(int i=l0;i<=n;++i){
		a[++cnt]={i,i-l0,-(l0-b0)};
		a[++cnt]={i-l0,i,+(l0-a0)};
	}
	for(int i=l1;i<=n;i++){
		a[++cnt]={i,i-l1,-a1};
		a[++cnt]={i-l1,i,b1};
	}	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=cnt;++j){
			if(dis[a[j].u]!=0x3f3f3f3f){
				dis[a[j].v]=min(dis[a[j].v],dis[a[j].u]+a[j].w);
			}
		}
	}
	bool chk=true;
	for(int i=1;i<=cnt;++i){
		if(dis[a[i].v]>dis[a[i].u]+a[i].w){
			chk=false;
		} 
	} 
	if(chk==false){
		cout << -1;
		return 0;
	}
	cout << dis[n];
	return 0;
}
