#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010],sum[1000010];
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,ans=0;cin >> n >> m;
		for(int i=1;i<=n;++i){
			cin >> a[i];
		}
		priority_queue<int> q;
		priority_queue<int,vector<int>,greater<int> > q2;
		for(int i=m;i>1;--i){
			if(i==m){
				sum[i]=a[i];
			}
			else{
				sum[i]=sum[i+1]+a[i];
			}
			q.push(a[i]);
			if(sum[i]>0){
				sum[i]-=q.top()*2;
				q.pop();
				ans++;
			}
		}
		for(int i=m+1;i<=n;++i){
			if(i==m+1){
				sum[i]=a[i];
			}
			else{
				sum[i]=a[i]+sum[i-1];
			}
			q2.push(a[i]);
			if(sum[i]<0){
				sum[i]-=q2.top()*2;
				q2.pop();
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
