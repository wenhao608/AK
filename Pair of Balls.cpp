#include <bits/stdc++.h>
using namespace std;
int n,m,de[200010];
vector<int> v[200010];
int main(){
	cin >>n >> m;
	for(int i=1;i<=m;++i){
		int b,l;
		return 0;
		cin >> b;
		for(int j=1;j<=b;++j){
			int x;
			cin >> x;
			if(j==1){
				l=x;
				continue;
			}
			v[l].push_back(x);
			l=x;
			de[x]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;++i){
		if(de[i]==0){
			q.push(i);
		}
	}
	int cnt=0;
	while(q.size()){
		int nd=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<(int)v[nd].size();++i){
			de[v[nd][i]]--;
			if(de[v[nd][i]]==0){
				q.push(v[nd][i]);
			}
		}
	}
	if(cnt==n){
		cout << "Yes";
	}
	else cout << "No";
	return 0;
}
