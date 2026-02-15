#include <bits/stdc++.h>
#include <string>
using namespace std;
int n;
string a[200010];
map<string,int> ma;
vector<int> v[200010],v2[200010];
int de[200010];
int win[200010],cnt=0;
int id(string a){
	if(ma[a]!=0){
		return ma[a];
	}
	return ma[a]=++cnt;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		
		string suf=a[i].substr(a[i].size()-3,3);
		string pre=a[i].substr(0,3);
		int u=id(pre),x=id(suf);
		v[x].push_back(u);
		de[u]++;
	}
	queue<int> q;
	for(int i=1;i<=cnt;++i){
		if(de[i]==0){
			q.push(i);
			win[i]=-1;
		}
	}
	while(q.size()){
		int nd=q.front();
		q.pop();
		for(int i=0;i<(int)v[nd].size();++i){
			if(win[v[nd][i]]){
				continue;
			}
			if(win[nd]==-1){
				win[v[nd][i]]=1;
				q.push(v[nd][i]);
			}
			else{
				de[v[nd][i]]--;
				if(de[v[nd][i]]==0){
					win[v[nd][i]]=-1;
					q.push(v[nd][i]);
				}
			}
		}
	}
	for(int j=1;j<=n;++j){
		int i=ma[a[j].substr(a[j].size()-3,3)];
		if(win[i]==0){
			cout << "Draw\n";
		}
		else if(win[i]==1){
			cout << "Aoki\n";//int 
		}
		else cout << "Takahashi\n";
	}
	return 0;
} 
