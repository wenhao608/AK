#include <bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100010];
vector<int> v[1010];
int f[100010];
int main(){
	int m,n,t=0;
	cin >> m >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].a >> a[i].b >> a[i].c;
		t=max(t,a[i].c);
		v[a[i].c].push_back(i);
	}
	for(int i=1;i<=t;++i){
		for(int j=m;j>=1;--j){
			for(int z=0;z<v[i].size();++z){
				if(j>=a[v[i][z]].a){
					f[j]=max(f[j],f[j-a[v[i][z]].a]+a[v[i][z]].b);
				}
			}
		}
	}
	cout << f[m];
	return 0;
}

