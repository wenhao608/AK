#include <bits/stdc++.h>
using namespace std;
string s[100010];
int de[1000010];
vector<int> v[100010];
char ans[27];
int main(){
	map<char,int> m;
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> s[i];
	}
	for(int i=2;i<=n;++i){
		int j=0;
		for(;j<min((int)s[i-1].size(),(int)s[i].size());++j){
			if(s[i][j]!=s[i-1][j]){
				v[s[i-1][j]-96].push_back(s[i][j]-96);
				de[s[i][j]-96]++;
				break;
			}
		}
		if(j==min((int)s[i-1].size(),(int)s[i].size())&&s[i-1].size()>s[i].size()){
			cout << "Impossiple";
			return 0;
		}
	}
	queue<int> q;
	for(int i=1;i<=26;i++){
		if(!de[i]){
			q.push(i);
		}
	}
	int cnt=0;
	while(q.size()){
		int nd=q.front();
		q.pop();
		ans[++cnt]=char(nd+96);
		for(int i=0;i<(int)v[nd].size();++i){
			de[v[nd][i]]--;
			if(!de[v[nd][i]]){
				q.push(v[nd][i]);
			}
		}
	}
	if(cnt!=26){
		cout << "Impossiple";
		return 0;
	}
	for(int i=1;i<=26;++i){
		cout << ans[i];
	}
	return 0;
}
