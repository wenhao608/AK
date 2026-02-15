#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
struct node{
	int a,b,l;
}a[10000010];
int dis[1010][1010],p[1010][1010],g[1010][1010];
vector<int> ans;
void get(int i,int j){
	int k=p[i][j];
	if(p[i][j]!=0){
		get(i,k);
		ans.push_back(k);
		get(k,j);
	}
}
signed main(){
	int n,m;
	cin >>n >> m;
	for(int i=1;i<=1000;++i){
		for(int j=1;j<=1000;++j){
			dis[i][j]=g[i][j]=2e9;
		}
	}
	for(int i=1;i<=m;++i){
		cin >> a[i].a >> a[i].b >> a[i].l;
		dis[a[i].a][a[i].b]=g[a[i].a][a[i].b]=min(g[a[i].a][a[i].b],a[i].l);
		dis[a[i].b][a[i].a]=g[a[i].b][a[i].a]=g[a[i].a][a[i].b];
	}
	int minn=1e9;
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if((g[i][k]+g[k][j]+dis[i][j]<minn)&&(i!=j)&&dis[i][j]!=0){
					minn=g[i][k]+g[k][j]+dis[i][j];
					ans.clear();
					ans.push_back(i);
					
					get(i,j);
					ans.push_back(j);
					ans.push_back(k);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					p[i][j]=k;
				}
			}
		} 
	}
	if(ans.size()){
		for(int i=0;i<(int)ans.size();++i){
			cout << ans[i] << ' ';
		}
	}
	else cout << "No solution.\n";
	return 0;
} 
