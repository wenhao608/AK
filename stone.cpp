#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[110],f[1000010];
int main(){
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	f[0]=0;
	for(int i=1;i<=k;++i){
		bool chk=false;
		for(int j=1;j<=n;++j){
			if(i-a[j]<0){
				break;
			}
			if(f[i-a[j]]==0){
				f[i]=1;
				chk=1;
				break;
			}
		}
		if(!chk){
			f[i]=0;
		}
	}
	if(f[k]==0){
		cout << "Second";
	}
	else{
		cout << "First";
	}
	return 0;
}
