#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=1,maxn=1;
int p[20]={0,2,3,5,7,11,13,17,19,23,29};
void dfs(int k,int id,int t,int la){
	if(t>maxn||(t==maxn&&k<ans)){
		ans=k;
		maxn=t;
	}
	int i=0,sum=k;
	while(i<la){
		i++;
		sum*=p[id];
		if(sum<=n){
			dfs(sum,id+1,t*(i+1),i);
		}
		else{
			break;
		}
	}
}
signed main(){
	cin >> n;
	dfs(1,1,1,30);
	cout << ans;
	return 0;
} 
