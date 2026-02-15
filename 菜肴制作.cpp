#include <bits/stdc++.h>
using namespace std;
int ans[1000010];
vector<int> v[100010];
int de[100010];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >>n >> m;
		for(int i=1;i<=n;++i){
			de[i]=0;
			v[i].clear();
		}
		for(int i=1;i<=m;++i){
			int x,y;
			cin >> x >> y;
			v[y].push_back(x);
			de[x]++;
		}
		priority_queue<int> q;
		for(int i=1;i<=n;++i){
			if(de[i]==0){
				q.push(i);
			}
		}
		int cnt=0;
		while(q.size()){
			int nd=q.top();
			q.pop();
			ans[++cnt]=nd;
			for(int i=0;i<v[nd].size();++i){
				de[v[nd][i]]--;
				if(de[v[nd][i]]==0){
					q.push(v[nd][i]);
				}
			}
		}
		if(cnt!=n){
			cout << "Impossible!\n";
		}
		else{
			for(int i=n;i>=1;--i){
				cout << ans[i] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
