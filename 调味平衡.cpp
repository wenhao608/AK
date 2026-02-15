#include <bits/stdc++.h>
using namespace std;
int a[1000010],f[105][1000010],b[1000010];
int main(){
	int n;
	cin >> n;
	for(int j=0;j<=100;++j){
		for(int i=0;i<=100000;++i){
	        f[j][i]=-2e9;
	    }
	}
	
    f[0][50000]=0;
	for(int i=1;i<=n;++i){
		int x, y;
		cin >>  x>> y;
		a[i]=x-y;
		b[i]=x+y;
	}
	bool chk=true;
	for(int i=1;i<=n;++i){
		for(int j=100000+a[i];j>=a[i];--j){
			f[i][j]=f[i-1][j];
			if(j-a[i]>=0&&j-a[i]<=100000&&f[i-1][j-a[i]]!=-2e9) f[i][j]=max(f[i-1][j-a[i]]+b[i],f[i][j]);			
		}
	}
	cout << max(0,f[n][50000]);
	return 0;
}
