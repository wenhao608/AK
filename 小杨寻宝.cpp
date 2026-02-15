#include <bits/stdc++.h>
using namespace std;
int a[100010],sum[100010];
vector<int> v[100010];
bool flag=true;
int z=0;
int dfs(int x,int fa){
	sum[x]+=a[x];
	for(int i=0;i<(int)v[x].size();++i){
		if(v[x][i]==fa){
			continue;
		}
		sum[x]+=dfs(v[x][i],x);
	}
	return sum[x];
}
void chk(int x,int fa){
	if(!flag){
		return ;
	}
	int ans=0;
	for(int i=0;i<(int)v[x].size();++i){
		if(v[x][i]==fa){
			continue;
		}
		if(sum[v[x][i]]!=0){
			ans++;
		}
		chk(v[x][i],x);
	}
	if(ans>1&&x!=z){
		flag=false;
	}
	if(x==z&&ans>2){
		flag=false;
	}
	return ;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		flag=true;
		for(int i=1;i<=n;++i){
			cin >> a[i];
			if(a[i]==1){
				z=i;
			}
			sum[i]=0;
			v[i].clear();
		}
		for(int i=1;i<n;++i){
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(z,0); 
		chk(z,0);
		if(!flag){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}
	return 0;
} 
