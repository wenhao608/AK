#include <bits/stdc++.h>
using namespace std;
void solve(string s1,string s2){
    if(s1==""||s2==""){
        return ;
    }
    int pos=s2.find(s1[0]);
    solve(s1.substr(1,pos),s2.substr(0,pos));
    solve(s1.substr(pos+1),s2.substr(pos+1));
    cout << s1[0];
}
int main(){
    string s1,s2;
    cin >> s2 >> s1;
    solve(s1,s2);
    return 0;
} 
