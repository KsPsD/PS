#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;


ll dp[100001];


ll dfs(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	
	ll & ret =dp[n];
	if(ret !=-1) return ret;
	dp[n]=0;
	
	return ret = dfs(n-1) + dfs(n-2);
}





int main(){
	
	int n;cin>>n;
	
	memset(dp, -1, sizeof(dp));	
	cout<<dfs(n)<<endl;	
	
	
	
	
	return 0;
} 
