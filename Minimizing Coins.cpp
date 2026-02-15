#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int f[1000010];
int main(){
	int n,x;
	cin >> n >> x;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=x;++i){
		for(int j=1;j<=n;++j){
			if(i<a[j]){
				break;
			}
			f[i]=min(f[i],f[i-a[j]]+1);
		}
	}
	if(f[x]==0x3f3f3f3f){
		f[x]=-1;
	}
	cout << f[x];
	return 0;
}
