#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int ans=0,x=0;
	for(int i=1,j=0;i<=n;++i){
		while(j+1<=n&&(x+a[1+j]==x^a[j+1])){
			x+=a[++j];
		}
		ans+=j-i+1;
		x-=a[i];
	}
	cout << ans;
	return 0;
}
