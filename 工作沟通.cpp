#include <bits/stdc++.h>
using namespace std;
int n,f[310],a[310]; 
int g[310][310];//i存在编号为j的上司 
int main(){
	cin >> n;
	for(int i=1;i<n;++i){
		cin >> f[i];
	}
	for(int i=1;i<n;++i){
		int t=i;
		g[i][i]=1;
		while(f[t]){
			
			t=f[t];
			g[i][t]=1;
		}
	}
	int q;
	cin >> q;
	while(q--){
		int m;
		cin >> m;
		for(int i=1;i<=m;++i){
			cin >> a[i];
		}
		int mx=0;
		bool flag=true;
		for(int i=1;i<=n;++i){
			flag=true;
			for(int j=1;j<=m;++j){
				if(g[a[j]][i]==0){
					flag=false;
					break;
				}
			} 
			if(flag){
				mx=max(mx,i);
			}
		}
		cout << mx << '\n';
	} 
	return 0;
}
