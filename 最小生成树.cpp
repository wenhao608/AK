#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> > v[200010];
int n,m;
int vis[200010];
struct node{
	int x,y,z;
}a[200010];
bool cmp(node a,node b){
	return a.z<b.z;
}
int f[1000010];
int find(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
signed main(){
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin >>x  >> y >> z;
		v[x].push_back({y,z});
		v[y].push_back({x,z});
		a[i].x=x;
		a[i].y=y;
		a[i].z=z;
	}
	for(int i=1;i<=n;++i){
		f[i]=i;
	}
	int add=0,ans=0,r=n;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;++i){
		if(find(a[i].x)==find(a[i].y)){
			continue;
		}
		ans+=a[i].z;
		merge(a[i].x,a[i].y);
	}
	int x=find(1);
	for(int i=1;i<=n;++i){
		if(find(i)!=x){
			cout << "orz";
			return 0;
		}
	}
	cout << ans;
	return 0;
} 
