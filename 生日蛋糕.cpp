#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
int n,m,h[1000010],r[1000010],ans=1e9;
void dfs(int x,int y,int k,int z){
	if(y<0){
		return ;
	}
	if(y==0&&x==m+1){
		k+=r[1]*r[1];
		ans=min(ans,k);
		return ;
	}
	if(x>=2&&k+z+r[1]*r[1]>=ans){
		return ;
	}
	if(y-r[x-1]*r[x-1]*h[x-1]*z>0){
		return ;
	}
	for(int i=r[x-1]-1;i>=z;--i){
		for(int j=h[x-1]-1;j>=z;--j){
			if(x+1<=m+1&&y-i*i*j>=0){
				r[x]=i;
				h[x]=j;
				dfs(x+1,y-i*i*j,k+(i*2*j),z-1);
				r[x]=0;
				h[x]=0;
			}
			
		}
	}
}
signed main(){
	cin >> n >> m;
	h[0]=n;
	r[0]=sqrt(n);
	dfs(1,n,0,m);
	if(ans==1e9){
		ans=0;
	}
	cout << ans;
	return 0;
}
