#include <bits/stdc++.h>
using namespace std;
int a[1010][1010],vis[1000010],n;
void dfs(int x){
	vis[x]=1;
	for(int i=1;i<=n;++i){
		if(vis[i]==0&&a[x][i]!=0){
			dfs(i);
		}
	}
}
int main(){
//	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin >> a[i][j];
		}
	}
	int sum=0;
	for(int i=1;i<=n;++i){
		if(vis[i]==0){
			dfs(i);
			sum++;
		}
	}
	cout << n-sum;
	return 0;
} 
