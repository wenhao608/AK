#include <bits/stdc++.h>
using namespace std;
struct tree{
	char data;
	int lc,rc;
}a[1000010];
void built(string s1,string s2){
	if(s1==""||s2==""){
		return ;
	}
	a[s1[0]-'A'+1].data=s1[0];
	if(s1.size()>=1) a[cnt].lc=(int)s1[1]-'A'+1;
	if(s2.find(s1[0])&&s2.find(s1[0])+1<=s1.size()) a[cnt].rc=(int)s1[s2.find(s1[0])+1]-'A'+1;
	
	int pos=s2.find(s1[0]);
	if(pos>=s1.size()||pos<0){
		return ;
	}
	built(s1.substr(1,pos),s2.substr(0,pos));
	built(s1.substr(pos+1),s2.substr(pos+1));
}
void out(int id){
	if(a[id].lc){
		out(a[id].lc);
	}
	if(a[id].rc){
		out(a[id].rc);
	}
	cout << a[id].data;
	return ;
}
int main(){
	string s1,s2;
	cin >> s2 >> s1;
	built(s2,s1);
	out(s1[0]-'A'+1);
	return 0;
}
