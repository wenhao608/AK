#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
	double r,d;
	bool operator>(const node a) const{
		return d<a.d;
	}
}a[1000010];
int n,e,s,t,f[1000010],pre[1000010];
double dis[1000010];
bool chk[100010];
double maxn;
struct pir{
	int x;
	double r,d,sum;
	bool operator<(const pir& a) const{
		return d>a.d;
	}
};
vector<pir> v[100010];
double sum=0;
void dij(){
	priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > q;
	q.push({0,s});
	pre[s]=0;
	dis[s]=0;
	while(q.size()){
		auto d=q.top();
		int nd=d.second;
		q.pop();
		if(chk[nd]){
			continue;
		}
		chk[nd]=true;
		if(nd==t){
			sum=dis[t];
			return ;
		}
		for(int i=0;i<v[nd].size();++i){
			if(v[nd][i].r>maxn){
				continue;
			}
			if(dis[v[nd][i].x]>dis[nd]+v[nd][i].d){
				pre[v[nd][i].x]=nd;
				dis[v[nd][i].x]=dis[nd]+v[nd][i].d;
				q.push({dis[v[nd][i].x],v[nd][i].x});
			}
		}
	}
}
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
}
void ad(int x,int y){
	x=find(x);
	y=find(y);
	f[x]=y;
}

bool cmp(node a,node b){
	return a.r<b.r;
}
void out(int x){
	if(x==0){
		return ;
	}
	out(pre[x]);
	if(x!=t) cout << x << ' ';
	else cout << x;
}
int main(){
	while(cin >> n >> e){
		for(int i=1;i<=n;++i){
			v[i].clear();
			f[i]=i;
			dis[i]=1e18;
		}
		memset(pre,0,sizeof(pre));
		memset(chk,false,sizeof(chk));
		cin >> s >> t;
		for(int i=1;i<=e;++i){
			cin >> a[i].x >> a[i].y >> a[i].r >> a[i].d;
			v[a[i].x].push_back({a[i].y,a[i].r,a[i].d});
			v[a[i].y].push_back({a[i].x,a[i].r,a[i].d});
		}
		sort(a+1,a+1+e,cmp);
		for(int i=1;i<=e;++i){
			ad(a[i].x,a[i].y);
			if(find(s)==find(t)){
				maxn=a[i].r;
				break;
			}
		}
		pre[s]=0;
		dij();
		out(t);
		cout << '\n';
		cout << fixed << setprecision(1) << sum << ' ' << fixed << setprecision(1) << maxn << '\n'; 
	}
	return 0;
}
