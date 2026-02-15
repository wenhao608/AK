#include <bits/stdc++.h>
using namespace std;
int n,size,ans[100010];
bool dfs(int id){
	if(id>size){
		return ans[id-1]==n;
	}
	if(ans[id-1]*(1<<size-id+1)<n){
		return 0;
	}
	for(int i=id-1;i>=0;--i){
		for(int j=id-1;j>=i;--j){
			if(ans[i]+ans[j]>n){
				break;
			}
			if(ans[i]+ans[j]<=ans[id-1]){
				continue;
			}
			ans[id]=ans[i]+ans[j];
			if(dfs(id+1)==true){
				return true;
			}
		}
	}
	return false;
}
int main(){
	ans[0]=1;
	while(1){
		cin >> n;
		if(n==0){
			break;
		}
		for(size=0;size<=n;size++){
			if(dfs(1)){
				for(int i=0;i<size;++i){
					cout << ans[i] << ' ';
				}
				cout << ans[size];
				cout << '\n';
				break;
			}
			
		}
		
	}
	return 0;
}
