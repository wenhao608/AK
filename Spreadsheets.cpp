#include<bits/stdc++.h>
using namespace std;
bool ch(string s){
	if(s.empty()||s[0]!='R') return false;
	int j=s.find('C');
	if(j<0||j>=s.size()||j==i+1){
		return false;
	}
	for(;i<j;++i){
		if(s[i]<'0'||s[i]>'9'){
			return false;
		}
	}
	j++;
	for(;j<s.size();++j){
		if(s[j]<'0'||s[j]>'9'){
			return false;
		}
	}
	return true;
}
void chang(int sum){
	string ans="";
	while(sum>0){
		sum--;
		ans+=char('A'+sum%26);
		sum/=26;
	}
	reverse(ans.begin(),ans.end());
    cout << ans;
}
int fid(string s){
	for(int i=0;i<s.size();++i){
		if(s[i]>='0'&&s[i]<='9'){
			return i;
		}
	}
}
void out(string s){
	int ans=0;
	for(int i=0;i<s.size();++i){
		if(s[i]<='9'&&s[i]>='0'){
			break;
		}
		ans=ans*26+s[i]-'A'+1;
	}
	cout << ans;
}
int main(){
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		bool chk=ch(s);
		if(chk){
			int i=s.find('R'),j=s.find('C');
			i++;
			for(;i<j;++i){
				cout << s[i];
			}
			int sum=0;
			for(int t=j+1;t<s.size();++t){
				sum=sum*10+s[t]-'0';
			}
			chang(sum);
		}
		else{
			int i=fid(s);
			cout << 'R';
			for(;i<s.size();++i){
				cout << s[i];
			} 
			cout << 'C';
			out(s);
		}
		cout << '\n';
	}
	return 0;
}//1b
