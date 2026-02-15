#include <bits/stdc++.h>
using namespace std;
int f[500010],ans[500010];
vector<int> v[500010];
vector<pair<int,int> > qus[500010];
int n,m,s,vis[500010];
int find(int x){
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}
void unon(int x,int y){
    x=find(x);
    y=find(y);
    f[y]=x;
}
void tarjan(int x){
	vis[x]=true;
	for(int i=0;i<v[x].size();++i){
		if(vis[v[x][i]]){
			continue;
		}
		tarjan(v[x][i]);
		unon(x,v[x][i]);
	}
	for(int i=0;i<qus[x].size();i++){
        if(qus[x][i].first) {
        	ans[qus[x][i].second]=find(qus[x][i].first);
		}
    }
}
int main(){
	for(int i=1;i<=500000;++i){
		f[i]=i; 
	}
	cin >> n >> m >> s;
	for(int i=1;i<n;++i){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=m;++i){
		int a,b;
		cin >> a >> b;
		qus[a].push_back({b,i});
        qus[b].push_back({a,i});
	}
	tarjan(s);
	for(int i=1;i<=m;++i){
		cout << ans[i] << '\n';
	}
	return 0;
}
