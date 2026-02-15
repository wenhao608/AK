#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,s;
	cin >> n >> s;
	long long ans=s,cnt=0;
	stack<int> st;
	while(n--){
		char c;
		cin >> c;
		if(st.size()&&c=='U'&&st.top()!='U'){
			st.pop();
		}
		
		else{
			st.push(c);
		}
	}
	stack<int> p;
	while(st.size()){
		p.push(st.top());
		st.pop();
	}
	while(p.size()){
		if(p.top()=='U'){
			ans=max((long long)1,ans/2)
		}
		else if(p.top()=='L'){
			ans=ans*2;
		}
		else{
			ans=ans*2+1;
		}
		p.pop();
	}
	cout << ans;
	return 0;
}
