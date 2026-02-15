#include <bits/stdc++.h>
using namespace std;
int n,a[310],b[310][310][310],xy[310][310],xz[310][310],yz[310][310],xx[610][610];
int l[310],r[310],c[610];
int main(){
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	if(n==1){
		if(a[1]==0){
			cout << "BitAryo";
		}
		else{
			cout << "BitLGM";
		}
		return 0;
	}
	if(n==2){
		for(int i=0;i<=300;++i){
			for(int j=0;j<=300;++j){
				if(l[i]||r[j]||c[i-j+300]){
					continue;
				}
				if(i==a[1]&&j==a[2]){
					cout << "BitAryo";
					return 0;
				}
				l[i]=1;;
				r[j]=1;
				c[i-j+300]=1;
			}
		}
		cout << "BitLGM";
		return 0;
	} 
	for(int i=0;i<=300;++i){
		for(int j=0;j<=300;++j){
			for(int z=0;z<=300;++z){
				if(xy[i][j]||xz[i][z]||yz[j][z]||xx[i-j+300][z-j+300]){
					continue;
				}
				if(i==a[1]&&j==a[2]&&z==a[3]){
					cout << "BitAryo";
					return 0;
				}
				xy[i][j]=1;
				xz[i][z]=1;
				yz[j][z]=1;
				xx[i-j+300][z-j+300]=1;
				
			}
		}
	}
	cout << "BitLGM";
	return 0;
} 
