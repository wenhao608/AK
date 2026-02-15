#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}a[1000010];
int b[100010];
bool cmp(node a,node b){
	if(a.r!=b.r)return a.r>b.r;
	return a.l>b.l;
}
int main(){
	map<int,int> ma;
	set<int> s;
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		int x,y;
		cin >> x >> y;
		a[i].l=x-y;
		a[i].r=x+y;
		ma[a[i].l]++;
		ma[a[i].r]++;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i){
		int x=a[i].l;
		if(s.count(a[i].l)||(!s.count(a[i].r)&&(ma[a[i].r]<=ma[a[i].l]))){
			x=a[i].r;
		}
		s.insert(x);
	}
	cout << s.size();
	return 0;
}
