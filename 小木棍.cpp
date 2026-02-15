#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n==1) cout<<-1;
		else if(n==2) cout<<1;
		else if(n==3) cout<<7;
		else if(n==4) cout<<4;
		else if(n==5) cout<<2 ;
		else if(n==6) cout<<6;
		else if(n==7) cout<<8;
		else if(n%7==0){
			for(int i=1;i<=n/7;++i){
				cout << 8; 
			}
		}
		else if(n%7==1){
			cout << 10;
			for(int i=1;i<=(n-8)/7;++i){
				cout << 8;
			}
		}
		else if(n%7==2){
			cout << 1;
			for(int i=1;i<=(n-2)/7;++i){
				cout << 8;
			}
		}
		else if(n%7==3){
			if(n==10) cout<<22;
			else {
				cout << 200;
				for(int i=1;i<=(n-17)/7;++i){
					cout << 8;
				}
			}
		}
		else if(n%7==4){
			cout << 20;
			for(int i=1;i<=(n-11)/7;++i){
				cout << 8;
			}
		}
		else if(n%7==5){
			cout << 2;
			for(int i=1;i<=(n-5)/7;++i){
				cout << 8;
			}
		}
		else if(n%7==6){
			cout << 6;
			for(int i=1;i<=(n-6)/7;++i){
				cout << 8;
			}
		}
		cout << '\n';
	}
	return 0;
} 
