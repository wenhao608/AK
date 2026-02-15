#include <bits/stdc++.h>
using namespace std;
int f[300010],front[1000010],num[1000010];
int find(int n){
    if(f[n]==n)return f[n];
    int fn=find(f[n]);
    front[n]+=front[f[n]];
	return f[n]=fn;
}
int main(){
	int t;
	cin >> t;
	for(int i=1;i<=300000;++i){
		f[i]=i;
		num[i]=1;
	}
	for(int i=1;i<=t;++i){
		char c;
		int a,b;
		cin >> c >> a >> b;
		int x=find(a),y=find(b);
		if(c=='M'){
			front[x]+=num[y];
			f[x]=y;
			num[y]+=num[x];
		}
		if(c=='C'){
			if(x!=y){
				cout << -1 << '\n';
			}
			else{
				cout << abs(front[a]-front[b])-1 << '\n';
			}
		}
	}
	return 0;
} 
