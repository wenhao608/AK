#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s[s.size()-1]=='0'){
            cout << 'E';
        }
        else{
            cout << "B";
        }
    }
    return 0;
}
