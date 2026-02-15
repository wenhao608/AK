#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	for(int i=n+1;i<=2*n;++i){
		a[i]=a[i-n];
	}
	long long sum=-1e18,cnt=0,j=1;
	int minn,maxn;
	for(int i=1;i<=2*n;++i){
		cnt+=a[i];
		while(i-j+1>n){
			cnt-=a[j];
			j++;
		}
		
		sum=max(sum,cnt);
		
		if(cnt<0){
			j=i;
			cnt=max(0,a[i]);
		}
	}
	cout << sum;
	return 0;
}
