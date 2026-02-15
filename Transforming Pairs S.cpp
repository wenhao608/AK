#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int a,b,c,d,ans=0;
		cin >> a >> b >> c >> d;
		if(a>c||b>d){
			cout << -1 << '\n';
			continue;
		}
		while(c!=a||d!=b){
			if(c==a&&d==b) break;
			bool chk=false;
			if(c<a&&b<d){
				ans=-1;
			}
			if(d-b>=c){
				ans+=(d-b)/c;
				d=d-c*((d-b)/c);
				chk=true;
			}
			if(!chk&&c-a>=d){
				ans+=(c-a)/d;
				c=c-d*((c-a)/d);
				chk=true;
			}
			if(!chk){
				ans=-1;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
