#include<bits/stdc++.h>

using namespace std;


int n,m;
int arr[1001][1001];
int dp[1001][1001];

int ans=0;
int main(){
	
	
	while(1){
		
		cin>>n>>m;
		
		if(n==0 && m==0)break;
		memset(arr,0 ,sizeof(arr));
		memset(dp,0 ,sizeof(dp));
		
		ans =0;
		for(int i=1 ;i<=n; i++){
			for(int j=1; j<=m; j++){
				cin>>arr[i][j];
				if(arr[i][j] ==1){
					dp[i][j] = 1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
					ans = max(ans,dp[i][j]);
				}
			}
		}
		
		cout<<ans<<endl;
		
	}
	
	
	
	
	return 0;
}
