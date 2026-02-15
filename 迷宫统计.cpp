#include <bits/stdc++.h>
using namespace std;
int main(){
	int  n,m,ans=0,cnt=0;
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int x;
			cin >> x;
			if((i==m)&&(x==1)){
				ans++;
			}
			if((j==m)&&(x==1)){
				cnt++;
			}
		}
	}
	cout << ans << ' ' << cnt << ' ' << ans+cnt;
	return 0;
}
