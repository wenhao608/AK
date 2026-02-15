#include <bits/stdc++.h>
using namespace std;
int f[100010];
int find(int r){
	if(r!=f[r]){
		f[r]=find(f[r]);
	}
	return f[r];
}
void unity(int x,int y){
	int x2=find(x),y2=find(y);
	f[x2]=y2;
}
int main(){
	while(true){
		int n,m;
		cin >> n;
		if(n==0){
			break;
		}
		cin >> m;
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
		while(m--){
			int x,y;
			cin >> x >> y;
			unity(x,y);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(f[i]==i){
			//	cout << f[i] << ' ' << i << '\n';
				ans++;
			}
		}
		cout << ans-1 << '\n';
	}
	return 0;
} 
