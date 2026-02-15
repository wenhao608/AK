#include <bits/stdc++.h>
using namespace std;
int cnt,n;
int g[30][30],vis[30],use[30];
int minn=1e9,path[30];
vector<int> v,ans;
void dfs(int id,int sum){
	if(sum>=minn){
		return ;
	}
	if(id==(int)v.size()){
		minn=sum;
		ans.clear();
		for(int i=0;i<(int)v.size();++i){
			ans.push_back(path[i]);
		}
		return ;
	}
	for(int i=0;i<(int)v.size();++i){
		if(use[v[i]]==0){
			
			int maxn=0;
			for(int j=0;j<id;++j){
				if(g[v[i]][path[j]]){
					maxn=max(maxn,id-j); 
				}
			}
			if(max(sum,maxn)>=minn){
				continue;
			}
			path[id]=v[i];
			use[v[i]]=1;
			dfs(id+1,max(sum,maxn));
			use[v[i]]=0;
		}
	}
}
int main(){
	string s;
	while(s!="#"){
		v.clear();
		cin >> s;
		if(s=="#"){
			break;
		}
		cnt=0;
		minn=1e9;
		memset(vis,0,sizeof(vis));
		memset(g,0,sizeof(g));
		s=s+';';
		char st,ed;
		for(int i=0;i<s.size();i++){
			int u=s[i]-'A';
			vis[u]=1;
			char c=s[i];
			i+=2;
			while(s[i]!=';'){
				int v=s[i]-'A';
				vis[v]=1;
				g[u][v]=1;
				g[v][u]=1;
				i++;
			}
		}
		for(int i=0;i<26;++i){
			if(vis[i]==1){
				v.push_back(i);
			}
		}
		sort(v.begin(),v.end());
		minn=1e9;
		memset(use,0,sizeof(use));
		dfs(0,0);
		for(int i=0;i<ans.size();++i){
			cout << (char)('A'+ans[i]) << ' ';
		}
		cout << "-> " << minn << '\n';
	}
	return 0;
} 
