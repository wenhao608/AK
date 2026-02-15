#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node{
	int a,b;
}a[1000010];
int n,m;
int dis[1010][1010];
bool chk(){
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(dis[i][j]>7){
				return false;
			}
		}
	}
	return true;
}
int main(){
	while(cin >> n >> m){
		for(int j=0;j<n;++j){
			for(int i=0;i<n;++i){
				dis[i][j]=1e9;
			}
		}
		for(int i=0;i<n;++i){
			dis[i][i]=0;
		}
		for(int i=1;i<=m;++i){
			cin >> a[i].a >> a[i].b;
			dis[a[i].a][a[i].b]=1;
			dis[a[i].b][a[i].a]=1;
		}
		if(chk()){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
	return 0;
}
