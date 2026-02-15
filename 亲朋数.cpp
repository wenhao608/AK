#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
int a[1000010];
int a_[100010],p;
string s;
 
signed main(){
	cin >> p;
	cin >> s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;++i){
		for(int j=0;j<p;++j){
			a_[(j*10+s[i]-'0')%p]+=a[j];
			
		}
		a_[(s[i]-'0')%p]+=1;
		for(int j=0;j<p;++j){
			a[j]=a_[j];
			a_[j]=0;
		}
		ans+=a[0];
	}
	cout << ans;
	return 0;
} 
