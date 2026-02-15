#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n%2==1){
			cout << 0 << '\n';
			continue;
		}
		cout << (2+n/2)/2 << '\n';
	}
	return 0;
}
