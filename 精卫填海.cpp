#include <bits/stdc++.h>
using namespace std;
int f[1000010];
struct node{
	int c,w;
}a[1000010];
int main(){
	int v,n,c,sum=0;
	cin >> v >> n >> c;
	for(int i=1;i<=n;++i){
		cin >> a[i].c >> a[i].w;
		sum+=a[i].c;
	}
	if(sum<v){
		cout << "Impossible";
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=c;j>=a[i].w;--j){
			f[j]=max(f[j],f[j-a[i].w]+a[i].c);
		}
	}
	for(int i=0;i<=v;i++){
		if(f[i]>=v){
			cout<< c-i << '\n';
			return 0;
		}
	}
	cout << "Impossible" << '\n';
	return 0;
} 
