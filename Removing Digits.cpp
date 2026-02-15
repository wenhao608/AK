#include <bits/stdc++.h>
using namespace std;
int n,a[1000010];
int dfs(int x){
	if(x==0){
		return a[x]=0;
	}
	if(a[x]!=-1){
		return a[x];
	}
	
	return a[x];
}
int main(){
	memset(a,0x3f,sizeof(a));
	cin >> n;
	a[0]=0;
	for(int x=1;x<=n;++x){
		vector<int> v;
		int m=x;
		while(m){
			v.push_back(m%10);
			m/=10;
		}
		if(v[0]!=0)a[x]=a[x-v[0]];
		for(int i=1;i<v.size();++i){
			if(v[i]==0){
				continue;
			}
			a[x]=min(a[x],a[x-v[i]]);
		}
		a[x]+=1;
	}
	cout << a[n];
	return 0;
} 
