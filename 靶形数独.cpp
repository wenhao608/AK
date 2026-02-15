#include <bits/stdc++.h>
using namespace std;
int a[110][110];
int r[10][10];//ÐÐ 
int c[10][10];//ÁÐ 
int o[10][10];//¿é 
int id[10][10];
struct node{
	int num,id;
}num[10];
constexpr int n=9;
int u[10][10]={
{1,1,1,2,2,2,3,3,3},
{1,1,1,2,2,2,3,3,3},
{1,1,1,2,2,2,3,3,3},
{4,4,4,5,5,5,6,6,6},
{4,4,4,5,5,5,6,6,6},
{4,4,4,5,5,5,6,6,6},
{7,7,7,8,8,8,9,9,9},
{7,7,7,8,8,8,9,9,9},
{7,7,7,8,8,8,9,9,9}
};
int t[10][10]={
6,6,6,6,6,6,6,6,6,
6,7,7,7,7,7,7,7,6,
6,7,8,8,8,8,8,7,6,
6,7,8,9,9,9,8,7,6,
6,7,8,9,10,9,8,7,6,
6,7,8,9,9,9,8,7,6,
6,7,8,8,8,8,8,7,6,
6,7,7,7,7,7,7,7,6,
6,6,6,6,6,6,6,6,6,
};
int ans=0;
bool chk=false;
bool dfs(node a,node b){
	return a.num<b.num;
}
void dfs(int x,int sum,int y,int fre){
	if(fre*7*9+y<=ans){
		return ;
	}
	if(sum==n+1){
		int sum=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(a[i][j]==0){
					return ;
				}
				sum+=a[i][j]*t[i][j];
			}
		}
		chk=true;
		ans=max(ans,sum);
		return ;
	}
	int z=0;
	for(int i=1;i<=n;++i){
		if(a[x][i]==0){
			continue;
		}
		for(int j=1;j<=9;++j){
			if(r[x][j]==0&&c[i][j]==0&&o[u[x][i]][j]==0){
				z+=j*t[i][j];
				r[x][j]=1;
				c[i][j]=1;
				o[u[x][i]][j]=1;
			}
		}
		dfs(id[sum+1],sum+1,y+z,fre-num[x].num);
	}
	
}
int main(){
	int sum=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin >> a[i][j];
			sum+=a[i][j]*t[i][j];
			if(a[i][j]==0){
				num[i].num+=1;
				num[i].id=i;
				continue;
			}
			c[i][a[i][j]]+=1;
			r[j][a[i][j]]+=1;
			o[u[i][j]][a[i][j]]+=1;
		}
	}
	int fre=0;
	for(int i=1;i<=n;++i){
		fre+=num[i].num;
		for(int j=1;j<=n;++j){
			if(r[i][a[i][j]]>1||c[j][a[i][j]]>1||o[u[i][j]][a[i][j]]>1){
				cout << -1;
				return 0;
			}
		}
	}
	sort(num+1,num+1+n,cmp);
	for(int i=1;i<=n;++i){
		id[i]=num[i].id;
	}
	dfs(1,1,sum,fre);
	if(chk){
		cout << ans;
	}
	else{
		cout << -1;
	}
	return 0;
}
