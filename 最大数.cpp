#include <bits/stdc++.h>
using namespace std;
int a[200010][30];
int main(){
    int m,d,r=0,t=0;
    cin >> m >> d;
    while(m--){
        char c;
        cin >> c;
        if(c=='Q'){
            int l;
            cin >> l;
            l=r-l+1; 
            int x=log2(r-l+1);
            t=max(a[l][x],a[r-(1<<x)+1][x]);
            cout << t << '\n';
        }
        else{
            r++;
            int x=0;
            cin >> x;
            a[r][0]=(x+t)%d;
            for(int i=1;(1<<i)<=r;++i){
                a[r-(1<<i)+1][i]=max(a[r][i-1],a[r-(1<<(i-1))+1][i-1]);
            }
        }
    }
    return 0;
}
