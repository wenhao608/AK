#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int x){
	for(int i=20;i>=0;--i){
		if(pow(2,i)<=x){
			if(i==1){
				cout << 2;
			}
			
			else if(i==0){
				cout << "2(0)";
			}
			else{
				cout << "2(";
				dfs(i);
				cout << ")";		
			}	
			x-=pow(2,i);
				if(x!=0){
				cout << '+';
			}
		}
	}
}
int main(){
	cin >> n;
	dfs(n);
	return 0;
} 
