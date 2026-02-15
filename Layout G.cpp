#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m1,m2;
vector<int> v[100010];
int dis[1000010];
struct node{
	int a,b,d;
}a[1000010];
int cnt=0;
signed main(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	cin >> n >> m1 >> m2;
	for(int i=1;i<=m1;++i){
		int x,y,d;
		cin >> x >> y >> d;
		a[++cnt]={x,y,d};
	}
	for(int i=1;i<=m2;++i){
		int x,y,d;
		cin >> x >> y >> d;
		a[++cnt]={y,x,-d};
	}
	for(int i=1;i<n;++i){
		a[++cnt]={i+1,i,0};
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=cnt;++j){
			if(dis[a[j].a]!=0x3f3f3f3f){
				dis[a[j].b]=min(dis[a[j].b],dis[a[j].a]+a[j].d);
			}
		}
	} 
	
	bool chk=true;
	for(int i=1;i<=cnt;++i){
		if(dis[a[i].b]>dis[a[i].a]+a[i].d){
			chk=false;
		} 
	}  
	if(chk==false){
		cout << -1;
		return 0;
	}
	if(dis[n]==0x3f3f3f3f3f3f3f3f) dis[n]=-2;
	cout << dis[n];
	return 0;
} 
