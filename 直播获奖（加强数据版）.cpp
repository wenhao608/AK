#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
signed main(){
	int n,w;
	cin >> n >> w;
	priority_queue<int> q;
	priority_queue<int,vector<int>,greater<int> > p;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=1;i<=n;++i){
		q.push(a[i]);
		int t=max(1ll,i*w/100);
		if(p.size()&&q.size()&&p.top()<q.top()){
			int t=p.top();
			p.pop();
			q.push(t);
			int x=q.top();
			q.pop();
			p.push(x);
		}
		if(p.size()>t){
			q.push(p.top());
			p.pop();
		}
		if(p.size()<t){
			p.push(q.top());
			q.pop();
		}
		cout << p.top() << ' '; 
	}
	return 0;
} 
