#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,c;
}a[200010];
int f[200010];
bool cmp(node a,node b){
	return a.a<b.a;
} 
signed main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	int maxn=0,ans=0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		if(q.size()){
			while(q.size()&&q.top().first<a[i].a){
				maxn=max(maxn,q.top().second);
				q.pop();
			}
		}
		f[i]=maxn+a[i].c;
		q.push({a[i].b,f[i]});
		ans=max(ans,f[i]);
	}
	cout << ans;
	return 0;
}
