#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

int n;
int dp[301];

int arr[301]; 

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	dp[1] =arr[1];
	dp[2] =arr[2];
	dp[3] = max(dp[1]+arr[3], dp[2]+arr[3]);
	for(int i=1; i<=n ;i++){
		dp[i] = max(arr[i-1]+ dp[i-3]+arr[i] , dp[i-2]+arr[i]);
	}
	
	cout<<dp[n]<<endl;
	
	return 0;
}
