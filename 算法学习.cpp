#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}a[1000010];
int cnt[1000010];
vector<int> v[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int m,n,k;
	cin >> m >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i].a;
	}
	for(int i=1;i<=n;++i){
		cin >> a[i].b;
		v[a[i].a].push_back(a[i].b);
	}
	for(int i=1;i<=m;++i){
		sort(v[i].begin(),v[i].end(),cmp);
	}
	int ans=0,maxn=0,maxx=1;
	for(int i=1;i<=m;++i){
		int sum=0;
		for(int j=0;j<v[i].size();++j){
			sum+=v[i][j];
			cnt[i]++;
			if(sum>=k){
				break;
			}
		}
		if(sum<k){
			cout << -1;
			return 0;
		}
		if(maxn<cnt[i]){
			maxn=cnt[i];
			maxx=i;
		}
		ans+=cnt[i];
	}
	if(ans-maxn>=maxn-1){
		cout << ans;
		return 0;
	}
	for(int i=1;i<=m;++i){
		if(i==maxx){
			continue;
		}
		ans+=min(maxn,(int)v[i].size())-cnt[i];
		if(ans-maxn>=maxn-1){
			cout << ans;
			return 0;
		}
	}
	cout << -1;
	
	return 0;
}
