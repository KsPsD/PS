#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define INF 1000000000

using namespace std;

int dp[501][501];
int arr[501][2];
int n; 

int main(){
	fastio;
	cin>>n;
	for(int i=1; i<= n; i++){
		cin>>arr[i][0]>>arr[i][1];
	}
	
	for(int i=1; i<n; i++){
		for(int j= 1; i+j<=n ; j++){
			dp[j][i+j] = INF;
			for(int k=j; k<=i+j; k++){
				dp[j][i+j] =  min(dp[j][i+j] ,dp[j][k] + dp[k+1][i+j] + arr[j][0] * arr[k][1] * arr[i+j][1]);
			}
		}
	}

cout<<dp[1][n]<<endl;
	
	return 0;
}
