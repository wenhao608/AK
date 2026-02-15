#include <bits/stdc++.h>
using namespace std;
int n;
string s[1010];
int cnt[150];
char a[110][110],sum=0;
char ch[15]={'1','2','3','4','5','6','7','8','9','0','+','*','='};
char f[110];
void dfs(int )
int id(char x){
	return x-'*';
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> s[i];
		for(int j=0;j<s[i].size();++j){
			if(s[i][j]<'a'||s[i][j]>'m'){
				cout << "noway\n";
				return 0;
			} 
			if(j==0||j==s[i].size()-1) continue;
			cnt[s[i][j]-'a']++;
		}
	}
	for(int i=0;i<=(int)('z'-'a');++i){
		if(cnt[i]==n){
			f[i]='=';
			dfs(1);
		}
	}
//	cout << (int)'='-'*' << ' ' << (int)'*' << ' ' << (int)'+';
} 
