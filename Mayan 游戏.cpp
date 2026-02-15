#include <bits/stdc++.h>
using namespace std;
int n,a[10][10];
int p[10][10];
struct node{
	int x,y,k;
}b[7];
bool chk(){
	for(int i=1;i<=5;++i){
		if(a[i][1]!=0){
			return false;
		}
	}
	return true;
}
void down(){
	for(int i=1;i<=5;++i){
		vector<int> v;
		for(int j=1;j<=7;++j){
			if(a[i][j]!=0){
				
				v.push_back(a[i][j]);
				a[i][j]=0;
			}
		}
		int cnt=0;
		for(int j=0;j<(int)v.size();++j){
			a[i][++cnt]=v[j];
		} 
	}
}
bool del(){
	memset(p,0,sizeof(p));
	for(int i=1;i<=5;++i){
		for(int j=1;j<=7;++j){
			if(a[i][j]==0){
				continue;
			}
			if(a[i-1][j]==a[i][j]&&a[i][j]==a[i+1][j]){
				p[i][j]=1;
				p[i-1][j]=1;
				p[i+1][j]=1;
			}
			if(a[i][j+1]==a[i][j]&&a[i][j]==a[i][j-1]){
				p[i][j]=1;
				p[i][j+1]=1;
				p[i][j-1]=1;
			}
		}
	}
	bool cg=0;
	for(int i=1;i<=5;++i){
		for(int j=1;j<=7;++j){
			if(p[i][j]==1){
				a[i][j]=0;
				cg=1;
			}
		}
	}
	return cg==1;
}
void change(int x,int y,int t){
	swap(a[x][y],a[x+t][y]);
	down();
	while(del()){
		down();
	}
}
void dfs(int id){
	if(id==0){
		
		if(!chk()){
			return ;
		}
		for(int i=1;i<=n;++i){
			printf("%d %d %d\n",b[i].x-1,b[i].y-1,b[i].k);
		}
		exit(0);
		return ;
	}
	int f[10][10];
	for(int i=1;i<=5;++i){
		for(int j=1;j<=7;++j){
			f[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=5;++i){
		for(int j=1;j<=7;++j){
			if(a[i][j]==0){
				break;
			}
			if(i!=5){
				b[n-id+1]={i,j,1};
				change(i,j,1);
				dfs(id-1);
				for(int i=1;i<=5;++i){
					for(int j=1;j<=7;++j){
						a[i][j]=f[i][j];
					}
				}
			}
			if(a[i-1][j]==0&&i!=1){
				b[n-id+1]={i,j,-1};
				change(i,j,-1);
				dfs(id-1);
				for(int i=1;i<=5;++i){
					for(int j=1;j<=7;++j){
						a[i][j]=f[i][j];
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=5;++i){
		int cnt=0;
		while(1){
			int b;
			scanf("%d",&b);
			if(b==0){
				break;
			} 
			a[i][++cnt]=b;
		}
	}
	dfs(n);
	printf("-1");
	return 0;
}
