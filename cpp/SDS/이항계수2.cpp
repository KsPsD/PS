#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 10007;
int n,m;
int dp[1001][1001];


int main(){
	
	
	cin>>n>>m;
	
	for(int i=1; i<=n ;i++){
        for(int j =0; j<=m ;j++){
            if (i == j || j == 0) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j-1] +dp[i-1][j]) % MOD;
  
        }
    }
    }
        cout<<dp[n][m]<<endl;
    
	return 0;
	
        
        

}
