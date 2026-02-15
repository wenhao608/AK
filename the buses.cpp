#include <bits/stdc++.h>
using namespace std;
int n,ans=17;
int a[1000010];
struct node{
	int fir,nd,sum;
}b[1000010];
int cnt=0;
bool chk(int x,int y){
	for(int i=x;i<=59;i+=y){
		if(a[i]==0){
			return false;
		}
	}
	return true;
}
void f(){
	for(int i=1;i<=29;++i){
		for(int j=i+1;j<=(59-i);++j){
			if(chk(i,j)==false){
				continue;
			}
			b[++cnt].fir=i;
			b[cnt].nd=j;
			b[cnt].sum=(59-i+1)/j;
		}
	}
}
bool cmp(node a,node c){
	return a.sum<c.sum;
}
bool dfs(int x,int k,int y,int sum){
	if(k==x){
		return sum==n;
	}
	if(sum+(x-k)*b[k].sum<n)
		return false;
	for(int i=k;i<=cnt;++i){
		if(sum+b[i].sum>n){
			continue;
		}
		for(int j=b[i].fir;j<=59;j+=b[i].nd){
			if(a[j]==0){
				continue;
				a[j]-=1;
			}
		}
		if(dfs(y+1,sum+b[i].sum)==true){
			return true;
		}
		for(int j=b[i].fir;j<=59;j+=b[i].nd){
			a[j]+=1;
		}
	}
	return false
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		int x;
		cin >> x;
		a[x]++;
	}
	f();
	sort(b+1,b+1+cnt,cmp);
	for(int i=0;i<=17;++i){
		if(dfs(i,0,1,0)==1){
			cout << i;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
