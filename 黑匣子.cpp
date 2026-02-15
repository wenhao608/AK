#include <bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
int main(){
	int m,n;
	cin >> m >> n;
	for(int i=1;i<=m;++i){
		cin >> a[i];
	}
	for(int i=1;i<=n;++i){
		cin >> b[i];
	}
	priority_queue<int> q;
	priority_queue<int,vector<int>,greater<int> > p;
	int j=0;
	for(int i=1;i<=n;++i){
		while(j<b[i]){
			++j;
			p.push(a[j]);
		}
		q.push(p.top());
		p.pop();
		while(p.size()&&q.size()&&(q.top()>p.top())){
			int x=p.top();
			p.pop();
			int y=q.top();
			q.pop();
			p.push(y);
			q.push(x);
		}
		cout << q.top() << '\n';
	}
	
	return 0;
}
