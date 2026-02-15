#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	int i=1;
	for(;i<=n&&k>0;++i){
		int minn=1e9,ans=0;
		for(int j=i;j<=min(k+i,n);++j){
			if(minn>a[j]){
				minn=a[j];
				ans=j;
			}
		}	
		for(int j=ans;j>i;--j) {
            swap(a[j],a[j-1]);
            k--;
        }
	}
	for(int i=1;i<=n;++i){
		cout << a[i] << ' ';
	}
	return 0;
}
