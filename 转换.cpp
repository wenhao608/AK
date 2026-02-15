#include <bits/stdc++.h>
using namespace std;
struct tree{
	char c;
	int lc,rc,f;
}a[100010];
struct tree2{
	char c;
	int f;
	vector<int> ch;
}b[1000010];
void dfs(int root){
	a[root].c=b[root].c;
	for(int i=0;i<b[root].ch.size();++i){
		if(i==0){
			a[root].lc=b[i].c-'A'+1;
			a[b[i].c-'A'+1].c=b[i].c;
		}
		else {
			a[b[i-1].c-'A'+1].rc=b[i].c-'A'+1;
		}
		dfs(b[i].c-'A'+1);
	}
}
int main(){
	int n,root;
	cin >> n;
	for(int i=1;i<=n;++i){
		char c;
		cin >> c;
		int f;
		cin >> f;
		if(f==0){
			root=c-'A'+1;
		}
		b[c-'A'+1].c=c;
		b[c-'A'+1].f=f;
		b[f].ch.push_back(c-'A'+1);
	}
	dfs(root);
} 
