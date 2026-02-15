#include <bits/stdc++.h>
using namespace std;
int a[10000010],b[10000010];
int n;
bool cmp(int a,int b){
	return a>b;
}
bool dfs(int k,int s,int t,int l){
	bool o;
	if(k==4){
		return true;
	}
	if(s==l){
		return dfs(k+1,0,0,l);
	}
	for(int i=t+1;i<=n;++i){
		if(s+a[i]<=l&&b[i]==0){
			b[i]=1;
			o=dfs(k,s+a[i],i,l);
			if(o==true){
				return o;
			}
			b[i]=0;
		}
	}
	return false;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		memset(b,0,sizeof(b));
		int sum=0;
		cin >> n;
		for(int i=1;i<=n;++i){
			cin >> a[i];
			sum+=a[i];
		}
		sort(a+1,a+1+n,cmp);
		if(sum%4!=0||a[1]>sum/4){
			cout << "no\n";
			continue;
		}
		
		if(dfs(1,0,0,sum/4)){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
	return 0;
}
