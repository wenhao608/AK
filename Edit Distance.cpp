#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	int cnt0=0,cnt1=0;
	for(int i=0;i<s.size();++i){
		if(s[i]=='0'){
			cnt0++;
		}
		else{
			cnt1++;
		}
	}
	if(cnt0>cnt1){
		for(int i=1;i<=s.size();++i){
			cout << 1;
		}
		return 0;
	}
	if(cnt0<cnt1){
		for(int i=1;i<=s.size();++i){
			cout << 0;
		}
		return 0;
	}
	if(s[0]=='0'){
		cout << 1;
		for(int i=2;i<=s.size();++i){
			cout << 0;
		}
		return 0;
	}
	cout << 0;
	for(int i=2;i<=s.size();++i){
		cout << 1;
	}
	return 0;
}
