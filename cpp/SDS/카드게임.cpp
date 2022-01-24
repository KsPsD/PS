#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

int arr[1001];
int dp[1001][1001];

int go(int lt, int rt, int turn){
	if(lt>rt) return 0;
	if(dp[lt][rt]) return dp[lt][rt];
	
	if(turn %2){
		return dp[lt][rt] =max(arr[lt] + go(lt+1,rt, turn+1) ,arr[rt]+go(lt,rt-1,turn+1) );
		
	}
	else return dp[lt][rt] =min(go(lt+1,rt, turn+1) ,go(lt,rt-1,turn+1));
}


int main(){
	
	fastio;
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=0; i<n ;i++){
			cin>>arr[i];
		}
		go(0,n-1,1);
		cout<<dp[0][n-1]<<endl;
		
		memset(dp,0,sizeof(dp));
		
		
	}
	
	
	
	return 0;
}
