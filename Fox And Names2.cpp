#include <bits/stdc++.h>
using namespace std;
string a[110];
vector<int> v[100];
int c[110];
int b[110];
char ans[110];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=2;i<=n;++i){
		for(int j=0;j<=min(a[i].size(),a[i-1].size());++j){
			if(j==min(a[i].size(),a[i-1].size())){
				if(a[i-1].size()>a[i].size()){
					cout << "Impossible";
					return 0;
				}
				continue;
			}
			
			if(a[i-1][j]!=a[i][j]){
				v[a[i-1][j]-'a'].push_back(a[i][j]-'a');
				c[a[i][j]-'a']++;
				break;
			}
		}
	} 
	int cnt=0;
	queue<int> q;
	for(int i=0;i<=25;i++){
		if(!c[i]){
			q.push(i);
		} 
	} 
	while(q.size()){
		int nd=q.front();
		q.pop();
		ans[++cnt]=char(nd+'a');
		for(int i=0;i<(int)v[nd].size();++i){
			c[v[nd][i]]--;
			if(!c[v[nd][i]]){
				q.push(v[nd][i]);
			}
		} 
	} 
	if(cnt!=26){
		cout << "Impossible";
		return 0;
	}
	for(int i=1;i<=26;++i){
		cout << ans[i];
	}
	return 0;
}
