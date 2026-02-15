#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000010],b[100010];
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	memset(b,0x3f,sizeof(b));
	b[1]=0;
	b[2]=abs(a[2]-a[1]);
	
	for(int i=3;i<=n;++i){
		
		for(int j=1;j<=k;++j){
			if(i-k<1) continue;
			b[i]=min(b[i-j]+abs(a[i]-a[i-j]),b[i]);
		}
	} 
	cout << b[n];
	return 0;
}
