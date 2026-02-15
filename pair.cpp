#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
bool chk[1000010];
int main(){
	int n;
	cin >> n;
	memset(chk,true,sizeof(chk));
	for(int i=1;i<=n;++i){
		cin >> a[i];
	} 
	long long m=pow(2,30),ans=0;
	while(m){
		int j=n;
		for(int i=1;i<j;++i){
			while(a[i]+a[j]>m){
				j--;
			}
			while(chk[j]=false){
				j--;
			}
			if(a[i]+a[j]==m&&i!=j&&i<j){
			//	cout << i << ' ' << j << '\n';
				ans++;
				chk[i]=false;
				chk[j]=false;
			}
			j--;
			if(j==0){
				break;
			}
		}
		
		m/=2;
	}
	cout << ans;
	return 0;
}
