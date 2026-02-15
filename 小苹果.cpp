#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int ans=0,ans2=0;
	for(int i=1;;++i){
		if(n==0){
			break;
		}
		if(ans==0&&n%3==1){
			ans=i;
		}
		n-=ceil(n/3.0);
		ans2=i;
	}
	cout << ans2 << ' ' << ans;
	return 0;
}
