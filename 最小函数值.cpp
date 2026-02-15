#include <bits/stdc++.h>
using namespace std;
int a[100010],b[1000010],c[1000010];
int main(){
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > q;
	int n,m;
	cin >> n b>> m;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> b[i] >> c[i];
		q.push({a[i]*a[i]+b[i]+c[i],i});
	}
	while(m--){
		cout << q.top().front << ' ';
		int i=q.top().second;
		q.push({q.top().front+a[i]*a[i]+b[i],i});
		q.pop();
	}
	return 0;
}
