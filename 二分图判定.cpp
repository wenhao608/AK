#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],b[1010],vis[1010],is=0;
vector<int> v[100010];
bool chk=false;
int n;
bool bfs(int x){
	queue<int> q;
	b[x]=0;
	q.push(x);
	while(q.size()){
		int d=q.front();
		q.pop();
		for(int i=0;i<v[d].size();++i){
			if(v[d][i]!=-1&&b[v[d][i]]==b[d]){
				return false;
			}
			if(!vis[v[d][i]]){
				q.push(v[d][i]);
			}
		}
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		chk=true;
		memset(vis,0,sizeof(vis));
		memset(b,-1,sizeof(b));
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&a[i][j]);
				if(a[i][j]==1){
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		chk=bfs(1);
		if(chk){
			cout << "Yes" << '\n';
		}
		else{
			cout << "No" << '\n';
		}
	}
}
