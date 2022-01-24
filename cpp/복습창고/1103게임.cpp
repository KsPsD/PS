#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n,m; 

int dy[] ={-1,0,1,0};
int dx[] = {0,-1,0,1};
char arr[51][51] ;
int dp[51][51];
int ch[51][51];
int ans =-1;
void dfs(int y, int x){
	
	if(arr[y][x] == 'H') {
		ans =max(cnt,ans);
		return 0;
	}
	if(y<0 || y>=n || x<0 || x>=m) {
		ans = max(cnt,ans);
		return 0;
	}
	
	if(ch[yy][xx] == 1) {
			cout<<-1<<endl;
			exit(0);
		}
	
	if (dp[y][x] != -1)
		return dp[y][x];

	ch[y][x] = 1;
	dp[y][x] = 0;
	
	for(int i=0; i<4; i++){
		int yy= y+(arr[y][x] - '0' )* dy[i];
		int xx= x+(arr[y][x]-'0')* dx[i];
		dp[y][x] = max(dp[y][x] ,dfs(yy,xx)+1);
	}
	
	ch[y][x] = 0;
	
	return dp[y][x];
	
}



int main(){
	fastio;
	cin>>n>>m;
	for(int i=0; i<n ;i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	} 
	memset(dp, -1 ,sizeof(dp));
	
	
	ans =dfs(0,0);
	
	cout<<ans<<endl;
	
	
	
	
	
	return  0;
}
