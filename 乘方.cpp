#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	double ans=pow(a,b);
	if(ans>1e9){
		cout << -1;
	}
	else{
		cout << int(ans);
	}
	return 0;
}
