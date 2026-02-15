#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin >> k;
	while(k--){
		long long n,d,e;
		cin >> n >> d >> e;
		long long he=n+2-e*d;
		long long cha=sqrt((n-e*d+2)*(n-e*d+2)-4*n);
		long long p=(he-cha)/2;
		long long q=(he+cha)/2;
		if(p>q){
			swap(p,q);
		}
		if(p*q!=n||e*d!=(p-1)*(q-1)+1){
			cout << "NO" << '\n';
		}
		else{
			cout << p << ' ' << q << '\n';
		}
	} 
	return 0;
}
