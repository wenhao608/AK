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
	for(int i=0;i<=29;++i){
		for(int j=i+1;j<=(59-i);++j){
			if(chk(i,j)==false){
				continue;
			}
			b[++cnt].fir=i;
			b[cnt].nd=j;
			b[cnt].sum=(59-i)/j+1;
		}
	}
}
bool cmp(node a,node c){
	return a.sum>c.sum;//kfljlitnskdjfjtnskdkklkdklkfljlsdkkjdjjfne
}
bool can(int fir,int nd){
	for(int j=fir;j<60;j+=nd){
		if(a[j]<=0){
			return false;
		}
	}
	return true;
}
void dfs(int y,int sum,int pos){
	if(y>=ans){
		return ;
	}
	if(sum==n){
		ans=min(ans,y);
		return ;
	}
	for(int i=pos;i<=cnt;++i){
		if(y+(n-sum+b[i].sum-1)/b[i].sum>=ans){
			break;
		}
		if(sum+b[i].sum>n){
			continue;
		}
		if(!can(b[i].fir,b[i].nd)){
			continue;
		}
		for(int j=b[i].fir;j<=59;j+=b[i].nd){
			if(a[j]>0){
				a[j]-=1;
				continue;
			}
		}
		dfs(y+1,sum+b[i].sum,i);
		for(int j=b[i].fir;j<=59;j+=b[i].nd){
			a[j]+=1;
		}
	}
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
	dfs(0,0,1);
	cout << ans;
	return 0;
}
