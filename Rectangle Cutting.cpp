#include <bits/stdc++.h>
using namespace std;
int f[1010][1010];
int main(){
	memset(f,0x3f,sizeof(f));
	int a,b;
	cin >> a >> b;
	for(int i=1;i<=max(a,b);++i){
		f[i][i]=0;
	}
	for(int i=1;i<=a;++i){
		for(int j=1;j<=b;++j){
			int minn=0;
			for(int k=1;k<=i;++k){
				f[i][j]=min(1+f[k][j]+f[i-k][j],f[i][j]);
			}
			for(int k=1;k<=j;++k){
				f[i][j]=min(1+f[i][k]+f[i][j-k],f[i][j]);
			}
		}
	}
	cout << f[a][b];
	return 0;
}
