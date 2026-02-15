#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010][1010];
struct node{
	int l,r;//左右 
	int u,d;//上下 
	int ri,c;//所在列数，行数
	int size;//若为哨兵节点，该列节点数 
}b[50010];
int cnt=0;
int row[1000010];
int ans[100010];
void init(){
	for(int i=0;i<=m;++i){
		b[i].size=0;
		b[i].r=i+1;
		b[i].l=i-1;
		b[i].ri=i;
		b[i].c=0;
		b[i].d=i;
		b[i].u=i;
	}
	memset(row,-1,sizeof(row));
	b[0].l=m;
	b[m].r=0;
	cnt=m+1; 
}
void add(int x,int y){
	b[y].size++;
	b[cnt].c=y;
	b[cnt].ri=x;
	b[cnt].d=y;
	b[cnt].u=b[y].u;
	b[b[y].u].d=cnt;
	b[y].u=cnt;
	if(row[x]==-1){
		row[x]=cnt;
		b[cnt].l=cnt;
		b[cnt].r=cnt;
		cnt++;
	}
	else{
		b[cnt].r=row[x];
		b[cnt].l=b[row[x]].l;
		b[b[row[x]].l].r=cnt;
		b[row[x]].l=cnt;
		cnt++;
	}
}
void del(int x){
	b[b[x].l].r=b[x].r;
	b[b[x].r].l=b[x].l;
	int h=b[x].d;
	while(h!=x){
		for(int j=b[h].r;j!=h;j=b[j].r){
			b[b[j].d].u=b[j].u;
			b[b[j].u].d=b[j].d;
			b[b[j].c].size--;
		}
		h=b[h].d;
	}
}
void cha(int x){
	for(int i=b[x].u;i!=x;i=b[i].u){
		for(int j=b[i].r;j!=i;j=b[j].r){
			b[b[j].u].d=j;
			b[b[j].d].u=j;
			b[b[j].c].size++;
		}
	}
	b[b[x].l].r=x;
	b[b[x].r].l=x;
}
void dfs(int x){
	if(b[0].l==0){
		for(int i=0;i<x;++i){
			cout << ans[i] << ' ';
		}
		exit(0);
	}
	int g=b[0].r;
	for(int i=g;i!=0;i=b[i].r){
		if(b[i].size<b[g].size){
			g=i;
		}
	}
	del(g);
	for(int i=b[g].d;i!=g;i=b[i].d){
		ans[x]=b[i].ri;
		for(int j=b[i].r;j!=i;j=b[j].r){
			del(b[j].c);
		}
		dfs(x+1);
		for(int j=b[i].l;j!=i;j=b[j].l){
			cha(b[j].c);
		}
	}
	cha(g);
}
int main(){
	cin  >> n >> m;
	init();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin  >> a[i][j];//fkti
			if(a[i][j]==1){
				add(i,j);
			}
		}
	}
	dfs(0);
	cout << "No Solution!";
	return 0;
}
