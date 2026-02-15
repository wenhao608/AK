#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010];
int c[1000010];
vector<int> v[100010];
int n,ans=0;
void get(int x){
	for(int i=2;i<=x/i;++i){
		if(x%i==0){
			int cnt=0;
			while(x%i==0){
				x/=i;
				cnt++;
			}
			v[i].push_back(cnt);
		}
	}
	if(x!=1){
		v[x].push_back(1);
	}
}
signed main(){
	
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=n;++i){
		get(a[i]);
	}
	for(int i=2;i<=1e5;++i){
		if(v[i].size()==0){
			continue;
		}
		sort(v[i].begin(),v[i].end());
		int zero=n-v[i].size();
		int mid=(n+1)/2;
		if(zero>=mid){
			for(int j=0;j<v[i].size();++j){
				ans+=v[i][j];
			}
		}
		else{
			
			mid=mid-zero-1;
			ans+=zero*v[i][mid];
			for(int j=0;j<v[i].size();++j){
				ans+=abs(v[i][j]-v[i][mid]);
			}
		}
	}
	cout << ans;
	return 0;
}
