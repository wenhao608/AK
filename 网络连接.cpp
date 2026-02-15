#include <bits/stdc++.h>
using namespace std;
int f(int x){
    int c=0;
    for(;x;x /= 10,c++);
    return c?c:1;
}
bool chk(string s) {
    string tmp;
    int x=0,c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            x=x*10+s[i]-'0';
			c++;
		}
        else{
            if (!c||c>3||x>255||f(x)!=c)
                return 0;
            tmp+=s[i];
			x=c=0;
        }
    }
    return tmp=="...:"&&c>0&&c<6&&x<65536&&f(x) == c;
}
int main(){
	map<string,int> m;
	int t;
	cin >> t;
	while(t--){
		m.clear();
		int cnt=0;
		string op,od;
		cin >> op >> od;
		if(op=="Server"){
			if(chk(od)){
				if(m.find(od)==m.end()){
					m[od]=++cnt;
					cout << "OK" << '\n';
					
				}
				else{
					cout << "FAIL" << '\n';
				}
			}
			else{
				cout<< "EER" << '\n';
				continue;
			}
		}
		else{
			if(chk(od)){
				if(m.find(od)==m.end()){
					cout << "FAIL" << '\n';
				}
				else{
					cout << m[od] << '\n';
				}
			}
			else{
				cout<< "EER" << '\n';
				continue;
			}
		}
	}
}
