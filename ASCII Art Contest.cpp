#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	cin >> a[1] >> a[2] >> a[3];
	sort(a+1,a+4);
	if(a[3]-a[1]>10){
		cout << "check again";
	}
	else{
		cout << "final" << ' ' << a[2];
	}
	return 0;
} 
