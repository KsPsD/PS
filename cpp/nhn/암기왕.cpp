#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; int n,x[1000001]={};
    while(t--){
         cin >> n;
        for(int i=0; i<n; i++){
            cin >> x[i];
        }
        sort(x,x+n);
        int m,y; cin >> m;
        for(int i=0; i<m; i++){
            cin >> y;
            int flag=0, max=n, min=0;
            if(binary_search(x,x+n,y)) cout <<"1\n";
            else cout << "0\n";
        }
    }
}
