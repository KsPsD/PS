#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;



int main(){
	
	
	int n;
	while(cin>>n){
		int cnt=1;
		ll k = 1;
		while(1){
			if(k%n ==0){
				cout<<cnt<<endl;
				break;	
			} 
			cnt++;
			k%=n;
			k=k*10 +1;
		}
	}
	
	
	
	
	
	return 0;
}
