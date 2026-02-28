#include <bits/stdc++.h>
using namespace std;
int a[100010];
vector<int> v[100010];
map<int,vector<int>> ma;
int cnt=0;
int n;
int read(){
	int f=1,x=0;
	char c;
	c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
void out(int x){
	if(x<0){
		putchar('-');
		out(-x);
		return ;
	}
	if(x<10){
		putchar('0'+x);
		return ;
	}
	out(x/10);
	putchar(x%10+'0');
}
int query(int l1,int r1,int x){
	if(ma.find(x)==ma.end()){
		return 0;
	}
	int l=0,r=ma[x].size()-1;
	int ans2=0,ans1=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(ma[x][mid]<l1){
			ans1=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	l=0,r=ma[x].size()-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(ma[x][mid]>r1){
			ans2=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans2-ans1-1;
}
int main(){
	ios::sync_with_stdio(false);
	int t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			if(ma[a[i]].size()==0)ma[a[i]].push_back(0);
			ma[a[i]].push_back(i);	
		}
		for(int i=1;i<=n;++i){
			if(ma[a[i]][ma[a[i]].size()-1]!=n+1)ma[a[i]].push_back(n+1);
		}
		int q=read();
		while(q--){
			int l=read(),r=read(),x=read();
			out(query(l,r,x));
			putchar('\n');
		}
		ma.clear();
	}
	return 0;
} 
