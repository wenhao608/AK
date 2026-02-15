#include <bits/stdc++.h>
using namespace std;
int p[100010],d[100010],e[100010],s[100010],c[100010];
struct bode{
	int 
};
int main(){
	int n;
	cin >> n;
	for(int i=2;i<=n;++i){
		cin >> p[i] >> d[i] >> e[i];
		e[i]+=e[p[i]];
		
	}
	int m;
	cin >> m;
	for(int i=1;i<=m;++i){
		cin >> s[i] >> c[i];
	}
	for(int i=1;i<=m;++i){
		int l=1,r=n,sum=0,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			sum=0;
			int x=mid;
			while(sum<=c[i]&&s[i]>d[x]){
				sum++;
				x=p[x];
			}
			if(sum<=c[i]){
				l=mid+1;
				ans=max(ans,mid);
			}
			else{
				r=mid-1;
			}
		}
		cout << e[ans] << '\n';
	}
	return 0;
} 
