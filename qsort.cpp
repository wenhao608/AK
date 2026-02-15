#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010];
void qsort(int l,int r){
	if(l>=r){
		return ;
	}
	//int x=a[rand()%(r-l+!)+1]
	int x=a[(l+r)/2];
	int i=l-1,j=r+1;
	while(i<j){
		while(a[++i]<x);
		while(a[--j]>x);
		if(i<j){
			swap(a[i],a[j]);
		}
	}
	qsort(l,j);
	qsort(j+1,r);
}
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	
	qsort(1,n);
	for(int i=1;i<=n;++i){
		cout << a[i] << ' ';
	} 
	return 0;
}
