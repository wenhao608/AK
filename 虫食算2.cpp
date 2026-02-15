#include <bits/stdc++.h>
using namespace std;
int n;
int chk[310],q[310],flag[310],f[310],cnt=-1;
string a,b,c;
int id(char c){
	return c-'A';
}
bool check(){
	int jw=0;
	for(int i=n-1;i>=0;--i){
		int u=f[id(a[i])],v=f[id(b[i])],w=f[id(c[i])];
		if(jw!=-1){
			if(u!=-1&&v!=-1&&w!=-1){
				if((u+v+jw)%n!=w){
					return false;
				}
				jw=(u+v+jw)/n;
			}
			else{
				jw=-1;
			} 
		}
		else{
			if(u!=-1&&v!=-1&&w!=-1){
				if((u+v)%n!=w&&(u+v+1)%n!=w){
					return false;
				}
			}
		}
	}
	if(jw==1){
		return false;
	} 
	return true;
}
void dfs(int id){
	if(id==n){
		for(int i=0;i<n;++i){
			cout << f[i] << ' ';
		}
		cout << '\n';
		exit(0);
	}
	int cc=q[id];
	for(int i=n-1;i>=0;--i){
		if(chk[i]){
			continue;
		}
		chk[i]=1;
		f[cc]=i;
		if(check()){
			dfs(id+1);
		}
		chk[i]=0;
		f[cc]=-1;
	}
}
int main(){
	memset(f,-1,sizeof(f));
	memset(flag,-1,sizeof(flag)); 
	cin >> n >> a >> b >> c;
	for(int i=n-1;i>=0;--i){
		int u=id(a[i]),v=id(b[i]),w=id(c[i]);
		if(flag[u]==-1){
			flag[u]=1;
			q[++cnt]=u;
		}
		if(flag[v]==-1){
			flag[v]=1;
			q[++cnt]=v;
		}
		if(flag[w]==-1){
			flag[w]=1;
			q[++cnt]=w;
		}
	}
	dfs(0); 
	return 0;
}
