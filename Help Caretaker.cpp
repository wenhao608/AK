#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010][1010];
int b[1010][1010];
char c[1010][1010];
int ans=0,cnt=0;
bool chk(int x,int y,int z){
	if(z==1){
		if(y+1>m||y+2>m){
			return false;
		}
		if(x+1>n||x+2>n){
			return false;
		}
		if(b[x][y+1]!=0||b[x][y+2]!=0||b[x+1][y+1]!=0||b[x+2][y+1]!=0){
			return false;
		}
		return true;
	}
	if(z==2){
		if(y-1<1||y-2<1){
			return false;
		}
		if(x+1>n||x+2>n){
			return false;
		}
		if(b[x+1][y]!=0||b[x+2][y]!=0||b[x+1][y-1]!=0||b[x+1][y-2]!=0){
			return false;
		}
		return true;
	}
	if(z==3){
		if(y-1<1||y+1>m){
			return false;
		}
		if(x+1>n||x+2>n){
			return false;
		}
		if(b[x+1][y]!=0||b[x+2][y]!=0||b[x+2][y-1]!=0||b[x+2][y+1]!=0){
			return false;
		}
		return true;
	}
	if(z==4){
		if(y+1>m||y+2>m){
			return false;
		}
		if(x+1>n||x+2>n){
			return false;
		}
		if(b[x+1][y]!=0||b[x+2][y]!=0||b[x+1][y+1]!=0||b[x+1][y+2]!=0){
			return false;
		}
		return true;
	}
	return true;
}
void fg(int x,int y,int z,int cnt){
	b[x][y]=cnt;
	if(z==1){
		b[x][y+1]=b[x][y+2]=b[x+1][y+1]=b[x+2][y+1]=cnt;
	}
	if(z==2){
		//b[x][y+1]=b[x][y+2]=b[x+1][y+1]=b[x+2][y+2]=z;
		b[x+1][y]=b[x+2][y]=b[x+1][y-1]=b[x+1][y-2]=cnt;
	}
	if(z==3){
		b[x+1][y]=b[x+2][y]=b[x+2][y-1]=b[x+2][y+1]=cnt;
	}
	if(z==4){
		b[x+1][y]=b[x+2][y]=b[x+1][y+1]=b[x+1][y+2]=cnt;
	}
}
void fg2(int x,int  y,int i){
	int z=0;
	b[x][y]=z;
	if(i==1){
		b[x][y+1]=b[x][y+2]=b[x+1][y+1]=b[x+2][y+1]=z;
	}
	if(i==2){
		//b[x][y+1]=b[x][y+2]=b[x+1][y+1]=b[x+2][y+2]=z;
		b[x+1][y]=b[x+2][y]=b[x+1][y-1]=b[x+1][y-2]=z;
	}
	if(i==3){
		b[x+1][y]=b[x+2][y]=b[x+2][y-1]=b[x+2][y+1]=z;
	}
	if(i==4){
		b[x+1][y]=b[x+2][y]=b[x+1][y+1]=b[x+1][y+2]=z;
	}
}
void dfs(int x,int y,int sum){
	if(sum+(n*m-((x-1)*m+y))/5<=ans){
		return ;
	} 
	if(y==m+1){
		dfs(x+1,1,sum);
		return ;
	}
	if(x==n+1){
		ans=max(ans,sum);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				c[i][j]=b[i][j];
			}
		}
		return ;
	}
	
	if(b[x][y]==0){
		for(int i=1;i<=4;++i){
			if(chk(x,y,i)){
				fg(x,y,i,++cnt);
				dfs(x,y+1,sum+1);
				cnt--;
				fg2(x,y,i);
			}
		}
	}
	dfs(x,y+1,sum);
}
int main(){
	cin >> n >> m;
	if(n<3||m<3){
		cout << 0 << '\n';
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cout << '.';
			} 
			cout << '\n';
		}
		return 0;
	}
	dfs(1,1,0);
	cout << ans << '\n';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(c[i][j]==0){
				cout << '.';
			}
			else cout << char(c[i][j]+'A'-1);
		}
		cout << '\n';
	}
	return 0;
}
