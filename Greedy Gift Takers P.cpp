#include <bits/stdc++.h>
using namespace std;
int c[1000010],a[1000010];
int n;
bool chk(int x){
	for(int i=1;i<x;++i){
		a[i]=c[i];
	}
	sort(a+1,a+x);
	int cnt=n-x;
	for(int i=1;i<x;++i){
		if(a[i]<cnt){
			cnt++;
		}
		else return false;
	}
	return true;
} 
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> c[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(chk(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout << n-l;
	return 0;
}
