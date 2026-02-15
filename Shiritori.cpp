#include <bits/stdc++.h>
using namespace std;
string s[1000010];
int in[1000010],win[1000010];
string k[1000010],t[1000010];
string ans[10]={"Draw","Takahashi","Aoki"};
map<string,int> m;
vector<int> v[100010];
int cnt=0;
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> s[i];
		for(int j=0;j<3;++j){
			k[i]+=s[i][j];
		}
		for(int j=s[i].size()-3;j<(int)s[i].size();++j){
			t[i]+=s[i][j];
		}
		if(!m[k[i]]){
			m[k[i]]=++cnt;
		}
		if(!m[t[i]]){
			m[t[i]]=++cnt;
		}
		v[m[k[i]]].push_back(m[t[i]]);
		in[m[k[i]]]++;
	}
	queue<int> q;
	for(int i=1;i<=cnt;++i){
		if(in[i]==0){
			q.push(i);
			win[i]=1;
		}
	}
	while(q.size()){
		int nd=q.front();
		q.pop();
		for(int i=0;i<(int)v[nd].size();++i){
			int x=v[nd][i];
			if(win[x]==0){
				if(win[nd]==2){
					win[x]=1;
					q.push(x);
				}
				else{
					in[x]--;
					if(in[x]==0){
						win[x]=2;
						q.push(x);
					}
				}
			}
		} 
	}
	for(int i=1;i<=n;++i){
		cout << ans[win[m[t[i]]]] << '\n';
	}
	return 0;
}
