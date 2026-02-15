#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int maxn=0;
int ans=1e18;
int n;
void dfs(int k,int cnt,int last,int t){
	if(k<0){
		return ;
	}
	if(cnt>n){
		return ;
	}
	if(k>ans){
		return ; 
	}
	if(cnt==n){
		ans=min(ans,k);
		return ;
	}
	int sum=k;
	for(int i=1;i<=last;++i){
		sum*=p[t];
		if(n%(cnt*(i+1))==0) dfs(sum,cnt*(i+1),i,t+1);
	}
}
signed main(){
	cin >> n;
	dfs(1,1,64,0);
	cout << ans;
	return 0;
}
