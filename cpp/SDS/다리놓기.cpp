#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;
int dp[31][31];

int c(int  y, int x){
	if(dp[y][x]) return dp[y][x];
	if(y==x|| x==0) return 1;
	else return dp[y][x] = c(y-1, x)  + c(y-1,x-1);
} 



int main(){
	
	int t;cin>>t;
	
	for(int i=0 ;i<t;i++){
		int a,b;cin>>a>>b;
		
	    cout<<C(b,a)<<endl;
	
	}
	
	return 0;
}
