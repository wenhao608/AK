#include <bits/stdc++.h>
using namespace std;
int f[5010];
int k[5010][5010],r[5010],c[5010];
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int a,b;
		cin >> a >> b;
		k[a][b]=1;
		r[b]++;
		c[a]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(r[i]==0) {
			f[i]=1;
			q.push(i);
		}
	}
	int maxn=0;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=n;++i){
			if(k[x][i]==0){
				continue;
			}
			f[i]+=f[x];
			f[i]%=80112002;
			r[i]--;
			if(r[i]==0){
				if(c[i]==0){
					maxn+=f[i];
					maxn%=80112002;
					continue;
				}
				q.push(i);
			}
		
		}
	}
	cout << maxn;
	return 0;
}
