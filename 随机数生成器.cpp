#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	srand(time(0));
	while(1){
		cout << "请输入生成数量：\n输出0视为退出\n";
		long long n;
		cin >> n;
		if(n==0){
			return 0;
		}
		long long maxn,minn;
		cout << "请输入生成最小值和生成最大值\n"; 
		cin >> minn >> maxn;
		while(n--){
			int a=minn+rand()%(maxn-minn+1);
			while(a==15){
				a=minn+rand()%(maxn-minn+1);
			}
			cout << a << '\n';
		}
		
	
	}
	
	return 0;
} 
