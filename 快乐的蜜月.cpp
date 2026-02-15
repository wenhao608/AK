#include <bits/stdc++.h>
using namespace std;
int f[410][110];
int p[110];
int m[14]={31,59,90,120,151,182,212,243,273,303,334,365};
//			1,2 ,3 , 4 , 5 , 6 , 7 ,8 , 9  ,10 ,11 ,12
struct node{
	int s,t,c;
}a[20010];
bool rn(int x){
	if((x%4==0&&x%100!=0)||x%400==0){
		return true;
	}
	return false;
}
int cnt=0,chk[110];
bool cmp(node a,node b){
	return a.t<b.t;
}
int s[110],t[110],id[110];
int main(){
	int k,o;
	cin >> k >> o;
	int y,r;
	cin >> y >> r;
	for(int i=1;i<=r;++i){
		int m1,d1,m2,d2;
		scanf("%d/%d TO %d/%d %d",&m1,&d1,&m2,&d2,&id[i]);
		s[i]=m[m1-1]+d1;
		t[i]=m[m2-1]+d2;
		if(m1>2&&rn(y)){
			s[i]+=1;
		}
		if(m2>2&&rn(y)){
			t[i]+=1;
		}
		if(!chk[id[i]]){
			cnt++;
			chk[id[i]]=1;
		}
	}
	for(int i=1;i<=o;++i){
		cin >> p[i];
	}
	for(int i=1;i<=r;++i){
		id[i]=(t[i]-s[i])*p[id[i]];
	}
	int sum=0;
	cnt=0;
	int add=365;
	if(rn(y)){
		add+=1;
	}
	for(int i=1;i<=r;++i){
		for(int j=1;j<=r;++j){
			if(i==j){
				continue;
			} 
			if(s[i]>s[j]&&t[i]<t[j]){
				continue;
			}
			if(s[i]<s[j]&&t[i]>t[j]){
				continue;
			}
			if(s[i]<s[j]&&s[i]>t[j]){
				continue;
			}
			if(t[i]>s[j]&&t[i]<s[j]){
				continue;
			}
			a[++cnt].s=s[i];
			a[cnt].t=t[i];
			a[cnt].c=id[i];
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=add;++i){
		priority_queue<int> q;
		map<int,int> ma;
		for(int j=1;j<=k;++j){
			q.push(f[i-1][j]);
			for(int t=1;t<=cnt;++t){
				if(a[t].t==j){
					if(!ma[a[t].c+f[a[t].s][j]]){
						q.push(a[t].c+f[a[t].s][j]);
						ma[a[t].c+f[a[t].s][j]]=1;
					}
				}
				
			}
		}
		for(int j=1;j<=k;++j){
			f[i][j]=q.top();
			q.pop();
		}
	}
	if(f[add][k]==0) cout << -1;
	else cout << f[add][k]+sum;
	return 0;

}
