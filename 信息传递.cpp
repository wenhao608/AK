#include <bits/stdc++.h>
using namespace std;
int t[1000010],r[1000010],chk[1000010],ans=1e9,vis[1000010];
void del(int x){
	chk[x]=1;
	r[t[x]]--;
	if(r[t[x]]==0&&chk[t[x]]!=1){
		del(t[x]);
	}
}
void dfs(int x,int mu,int sum){
	if(x==mu&&sum){
        ans=min(ans,sum);
        return;
    }
    if(chk[t[x]]==0){
    	chk[t[x]]=1;  
    	dfs(t[x],mu,sum+1);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> t[i];
		r[t[i]]++;
	}
	for(int i=1;i<=n;i++){
        if(!r[i]&&chk[i]!=1) del(i);
	}
	for(int i=1;i<=n;++i){
		if(chk[i]==0){
			dfs(i,i,0);
		}
	}
	cout << ans;
	return 0;
}
