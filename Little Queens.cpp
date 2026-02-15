#include <bits/stdc++.h>
using namespace std;
int sum=0;
int a[110];
int n,k;
bool chk(int x,int y){
	for(int i=1;i<=x-1;++i){
		int x_=i,y_=a[i];
		if(y_==y){
			return false;
		}
		if(abs(y-y_)==abs(x-x_)){
			return false;
		}
	}
	return true;
}
void dfs(int id,int ans){
	if(ans>k){
		return ;
	}
	if(id==n+1){
		if(ans==k){
			sum++;
		}
		return; 
	}
	a[id]=-id-abs(rand()%30000)*id;
	dfs(id+1,ans);
	for(int i=1;i<=n;++i){
		if(chk(id,i)){
			a[id]=i;
			dfs(id+1,ans+1); 
			a[id]=-id-abs(rand()%30000)*id;
		}
	}
}
int main(){
	srand(time(0));
	cin >> n >> k;
	dfs(1,0);
	cout << sum;
	return 0;
}
