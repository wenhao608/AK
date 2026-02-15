#include <bits/stdc++.h>
using namespace std;
int aa[10];
string p="";
queue<string> q;
map<string,string> m;
const int n=8;
bool a(string s){
	string x="34563456";
	for(int i=0;i<=3;++i){
		x[i]=s[i+4];
	}
	for(int i=0;i<=3;++i){
		x[i+4]=s[i];
	}
	if(m.count(x)==0){
		m[x]=m[s]+'A';
		q.push(x);
	}
	if(x==p){
		cout << m[x].size() << '\n' << m[x];
		return true;
	}
	return false;
}
bool b(string s){
	string x="34534633";
	for(int i=1;i<=3;++i){
		x[i]=s[i-1];
	}
	x[0]=s[3];
	x[4]=s[7];
	for(int i=5;i<=7;++i){
		x[i]=s[i-1];
	}
	if(m.count(x)==0){
		m[x]=m[s]+'A';
		q.push(x);
	}
	if(x==p){
		cout << m[x].size() << '\n' << m[x];return true;
	}
	return false;
}
bool c(string s){
	string x="34563456";
	x[0]=s[0];
	x[1]=x[5];
	x[2]=s[1];
	x[3]=s[3];
	x[4]=s[4];
	x[5]=s[6];
	x[6]=s[2];
	x[7]=s[7];
	if(m.count(x)==0){
		m[x]=m[s]+'A';
		q.push(x);
	}
	if(x==p){
		cout << m[x].size() << '\n' << m[x];
		return true;
		
	}
	return false;
}
void bfs(){
	
	q.push("12345678");
	while(q.size()){
		string d=q.front();
		q.pop();
		bool chk=false;
		chk=a(d);
		if(chk){
			return ;
		}
		chk=b(d);
		if(chk){
			return ;
		}
		chk=c(d);
		if(chk){
			return ;
		}
	}
}
int main(){
	for(int i=1;i<=n;++i){
		cin >> aa[i];
		p+=(char)(aa[i]+48);
	}
	bfs();
	return 0;
}
