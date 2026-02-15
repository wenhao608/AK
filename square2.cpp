#include <iostream>
#include <algorithm>
using namespace std;
int n,sum=0;
int a[1000010],b[1000010];
bool dfs(int x,int cnt,int l){
	if(x==4){
		return true;
	}
	if(cnt==sum){
		return dfs(x+1,0,0);
	}
	for(int i=l+1;i<=n;++i){
		if(b[i]==0){
			if(cnt+a[i]<=sum&&b[i]==0){
				b[i]=1;
				if(dfs(x,cnt+a[i],i)){
					return true;
				}
				b[i]=0;
			}
		} 
	}
	return false;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		sum=0;
		for(int i=1;i<=n;++i){
			cin >> a[i];
			b[i]=0;
			sum+=a[i];
		}
		if(sum%4!=0){
			cout << "no\n";
			continue;
		}
		sort(a+1,a+1+n,cmp);
		if(a[1]>sum/4){
			cout << "no\n";
			continue;
		}
		sum/=4;
		if(dfs(1,0,1)){
			cout << "yes\n";
		}
		else{
			cout << "no\n";
		}
	}
	return 0;
}
