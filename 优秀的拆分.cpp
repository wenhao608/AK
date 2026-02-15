#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	int n;
	cin >> n;
	if(n%2==1){
		cout << -1;
		return 0;
	}
	a[1]=2;
	int i=2;
	for(;;++i){
		
		a[i]=a[i-1]+a[i-1];
		if(2*a[i]>n){
			break;
		}
	}
	for(;i>=1;--i){
		if(n==0){
			break;
		}
		if(n>=a[i]){
			cout << a[i] << ' ';
			n-=a[i];
		}
	}
	return 0;
}
