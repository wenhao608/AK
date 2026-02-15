#include <bits/stdc++.h>
using namespace std;
#define int __int128
struct fs{
	int fz,fm;
}a[1000010];
__int128 n,m,de[100010];
vector<signed> v[100010];
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int read(){
	int f=1,x=0;
	char c;
	c=getchar();
	while('0'>c||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
void out(int x){
	if(x==0){
		return ;
	}
	out(x/10);
	putchar(x%10+'0');
}
int outde[100010]; 
signed main(){
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		int b,pre;
		b=read();
		for(int j=1;j<=b;++j){
			int x;
			x=read();
			v[i].push_back(x);
			de[x]++;
			outde[i]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;++i){
		a[i]={0,1};
	}
	for(int i=1;i<=m;++i){
		a[i]={1,1};
		q.push(i);
	} 
	while(q.size()){
		int nd=q.front();
		q.pop();
		if(outde[nd]==0){
			continue;
		}
		fs p={a[nd].fz/gcd(a[nd].fz,a[nd].fm*outde[nd]),a[nd].fm*outde[nd]/gcd(a[nd].fz,a[nd].fm*outde[nd])};
		for(int i=0;i<v[nd].size();++i){
			int x=v[nd][i];
			int fm=a[x].fm*p.fm;
			int fz=a[x].fz*p.fm+p.fz*a[x].fm;
			int o=gcd(fm,fz);
			fm/=o;
			fz/=o;
			a[x].fm=fm;
			a[x].fz=fz;
			de[x]--;
			if(de[x]==0){
				q.push(x);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(outde[i]==0){
			out(a[i].fz);
			putchar(' ');
			out(a[i].fm);
			putchar('\n');
		}
	}
	return 0;
}
