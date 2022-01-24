#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;




int n,m;
char arr[50][50];
int dp[50][50];
int dy[] ={-1,0,1,0};
int dx[]= {0,-1,0,1};
int ans= -1;
int ch[50][50];
int dfs(int y,int x){
	if (x < 0 || y < 0 || x >= m || y >= n || arr[y][x] =='H') 
		return 0;
	if(ch[y][x]){
		cout<<-1<<endl;
		exit(0);
	}
	
	if (dp[y][x] != -1)
		return dp[y][x];

	ch[y][x] = true;
	dp[y][x] = 0;
	
	

	for(int i=0; i<4; i++){
		int yy=y+(dy[i]*(arr[y][x]-'0'));
		int xx = x+(dx[i]*(arr[y][x]-'0'));
		dp[y][x] = max(dp[y][x], dfs(yy, xx) + 1);
	}
	
	ch[y][x] = false;

	return dp[y][x];
	
	
}

int main(){
	fastio;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0; j<m; j++){
			dp[i][j] =-1;
			cin>>arr[i][j];
		}
	}
	
	
	ans=dfs(0,0);
	cout<<ans<<endl;
	
	return 0;
	
} 
