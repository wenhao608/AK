#include <bits/stdc++.h>
using namespace std;
struct node{
	string name;
	int fen,win,los;
}a[100010];
bool cmp(node a,node b){
	if(a.fen!=b.fen){
		return a.fen>b.fen;
	}
	if(a.win-a.los!=b.win-b.los){
		return a.win-a.los>b.win-b.los;
	}
	return a.win>b.win;
}
bool pmc(node a,node b){
	return a.name<b.name;
}
int main(){
	map<string,int> m;
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i].name;
		m[a[i].name]=i;
		a[i].fen=0;
	}
	for(int i=1;i<=n*(n-1)/2;++i){
		string b="",c;
		int d,e;
		char s;
		cin >> s;
		while(s!='-'){
			b+=s;
			cin >> s;
		}
		cin >> c >> d >> s >> e;
		a[m[b]].win+=d;
		a[m[b]].los+=e;
		a[m[c]].win+=e;
		a[m[c]].los+=d;
		if(d==e){
			a[m[b]].fen+=1;
			a[m[c]].fen+=1;
		}
		else if(d>e){
			a[m[b]].fen+=3;
		}
		else a[m[c]].fen+=3;
	}
	sort(a+1,a+1+n,cmp);
	sort(a+1,a+1+n/2,pmc); 
	for(int i=1;i<=n/2;++i){
		cout << a[i].name << '\n';
	}
	return 0;
} 
