#include <bits/stdc++.h> 
using namespace std;
int a[5];
int cnt[110];
int main(){
	cin >> a[1] >> a[2] >> a[3];
	int maxn=0,x=0;
	for(int i=1;i<=3;++i){
		cnt[a[i]]++;
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=maxn;++i){
		while(cnt[i]){
			cnt[i]--;
			a[++x]=i;
		}
	}
	string s;
	cin >> s;
	for(int i=0;i<3;++i){
		cout << a[s[i]-'A'+1] << ' ';
	}
	return 0;
}
