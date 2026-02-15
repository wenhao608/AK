#include <bits/stdc++.h>
using namespace std;
int a[1000010],f[1000010],b[1000010];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<=100000;++i){
        f[i]=-2e9;
    }
    f[50000]=0;
	for(int i=1;i<=n;++i){
		int x, y;
		cin >>  x>> y;
		a[i]=x-y;
		b[i]=x+y;
	}
	bool chk=true;
	for(int i=1;i<=n;++i){
		if(a[i]>=0)
		{
		 for(int j=100000;j>=a[i];--j)
			f[j]=max(f[j-a[i]]+b[i],f[j]);
		}
		else
		{
		
		for(int j=0;j>=100000+a[i];++j)
			f[j]=max(f[j-a[i]]+b[i],f[j]);
		}
	}
	cout << f[50000];
	return 0;
} 
