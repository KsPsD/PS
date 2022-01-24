#include<bits/stdc++.h>




using namespace std;

int dy[] ={-1,0,1,0};
int dx[] = {0,-1,0,1}; 

int arr[101][101];
int n;
int ch[101][101];
int cnt;
int ans =-1;
void dfs(int y,int x){
	
	for(int i=0; i<4; i++){
		int yy = y+dy[i];
		int xx=  x+dx[i];
		if(yy <1  || xx< 1|| yy>n || xx>n) continue;
		
		
		if(ch[yy][xx] == 0) {
			ch[yy][xx] =1;
			dfs(yy,xx);	
	}
}
}

int main(){
	cin>>n;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>arr[i][j];
			
		}
	}
	
	
	for(int t=1; t<=100; t++){
		memset(ch, 0 ,sizeof(ch));
		int cnt=0;
		
	for(int i=1;i<=n; i++){
		for(int j=1;j<=n; j++){
			if(arr[i][j] <= t) ch[i][j]=-1;
		}
	}
	
	for(int i=1;i<=n; i++){
		for(int j=1;j<=n; j++){
			if(ch[i][j]==0){
				ch[i][j]=1;
				dfs(i,j);
				cnt++;
			}
		}
	}
	
	
	
	
	
	ans  = max(ans,cnt);
		
	}
	
	
	
	
	cout<<ans<<endl;
}
