#include <bits/stdc++.h>
using namespace std;
struct fraction{
	int fz,fm;
}a,b;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int fm,fz;
	char c,d;
	cin >> a.fz >> c >> a.fm >> c >> b.fz >> d >> b.fm;
	if(c=='-'){
		b.fz*=-1;
	}
	if(c=='/'){
		swap(b.fm,b.fz);
	}
	if(c=='+'||c=='-'){
		fm=a.fm*b.fm;
		fz=a.fz*b.fm+b.fz*a.fm;
	}
	else{
		fm=a.fm*b.fm;
		fz=a.fz*a.fz;
	}
	int o=gcd(fm,fz);
	fm/=o;
	fz/=o;
	cout << fz << ' ' << fm;
	return 0;
}
