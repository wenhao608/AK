#include <bits/stdc++.h>
using namespace std;
int n,a[1010][1010];
int meet[1010][1010];
int main(){
	int t;
	cin >> t;
	while(t--){
		memset(meet,0,sizeof(meet));
		cin >> n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				char c;
				cin >> c;
				a[i][j]=c-'0';
				a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j];
			} 
		}
		for(int i=1;i<2*n;++i){
			meet[i][i+1]=1;
		}
		meet[n*2][1]=1;
		for(int len=2;len<=n;++len){
			for(int i=1;i<=n*2;++i){
				int j=i+len;
				for(int k=i+1;k<j;++k){
					if(meet[i][k]==1&&meet[k][j]==1&&(a[i][k]||a[j][k])){
						meet[i][j]=1;
						break;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			if(meet[i][i+n]){
				ans++;
			}
		}
		cout << ans << '\n';
		for(int i=1;i<=n;++i){
			if(meet[i][i+n]){
				cout << i << '\n';
			}
		}
	}
	return 0;
}
