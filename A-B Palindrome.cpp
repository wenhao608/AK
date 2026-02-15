#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		bool ans=true;
		int a,b;
		cin >> a >> b;
		string s;
		cin >> s;
		if(a+b!=s.size()){
			cout << -1 << '\n';
			continue;
		}
		if(a%2==0&&b%2==0&&s.size()%2==0){
		}
		else if(s.size()%2!=0&&a%2){
			s[(s.size()+1)/2]='0';
			a--;
		}
		else if(s.size()%2!=0&&b%2){
			s[(s.size()+1)/2]='1';
			b--;
		}
		else {
			cout << -1 << '\n';
			continue;
		}
		for(int i=0;i<s.size();++i){
			if(s[i]=='0'){
				a-=1;
			}
			if(s[i]=='1'){
				b-=1;
			}
			if(s[i]=='0'&&s[s.size()-i-1]=='1'){
				ans=false;
			}
			if(s[i]=='1'&&s[s.size()-i-1]=='0'){
				ans=false;
			}
		}
		for(int i=0;i<s.size();++i){
			if(s[i]=='?'&&s[s.size()-i-1]=='0'){
				s[i]='0';
				a-=1;
			}
			if(s[i]=='?'&&s[s.size()-i-1]=='1'){
				s[i]='1';
				b-=1;
			}
			if(s[i]!='?'&&s[i]!=s[s.size()-i-1]){
				ans=false;
			}
			
		}
		if(!ans){
			cout << -1 << '\n';
			continue; 
		}
		for(int i=0;i<s.size();++i){
			if(s[i]=='?'){
				if(a){
					s[i]='0';
					s[s.size()-i-1]='0';
				}
				else {
					s[i]='1';
					s[s.size()-i-1]='1';
				}
			}
		}
		if(!a&&!b) cout << s << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}//1512c
