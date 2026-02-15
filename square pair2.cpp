#include <bits/stdc++.h>
using namespace std;
int a[200010];

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		int x;
		cin >> x;
		for(int j=sqrt(x);j>=1;--j){
			if(x%(j*j)==0){
		  		x/=(j*j);
			}
		}
		a[x]++;
		
	}
	int sum=0;
	for(int i=0;i<=200000;++i){
		sum+=a[i]/2;
	}
	cout << sum;
	return 0;
}
