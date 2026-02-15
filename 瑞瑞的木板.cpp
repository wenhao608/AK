#include <bits/stdc++.h>
using namespace std;
int l[1000010];
int main(){
	priority_queue<int,vector<int>,greater<int> > q;
	int ans=0,n,t;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> l[i];
		q.push(l[i]);
	}
	for(int i=1;i<n;++i){
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		ans=ans+x+y;
		q.push(x+y);
	}
	cout << ans;
	return 0;
}
