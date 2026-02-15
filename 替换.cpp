#include <bits/stdc++.h>
using namespace std;
char a[100010];
int main(){
	string s,s1;
	cin >> s >> s1;
	for(int i=0;i<s1.size();++i){
		a[i]=s1[i];
	}
	sort(a+1,a+s1.size());
	int j=s1.size()-1;
	for(int i=0;i<s.size();++i){
		if(a[j]>s[i]){
			s[i]=a[j];
			j--;
		}
		if(j==-1){
			break;
		}
	}
	cout << s;
	return 0;
}
