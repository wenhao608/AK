#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n >> a[1];
		int chk=a[1]%2;
		for(int i=2;i<=n;++i){
			cin >> a[i];
			if(a[i]%2!=chk){
				chk=2;
			}
		}
		if(chk==2){
			sort(a+1,a+1+n);;
		}
		for(int i=1;i<=n;++i){
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
} 
