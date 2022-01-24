#include<bits/stdc++.h>


using namespace std;


int n,m;
int arr[9][9]; 
int arr_c[9][9];
int ans =0;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
void go_check(){
	queue<pair<int, int> > q;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr_c[i][j] ==2)
				q.push({i,j});
		}
	}
	
	while(!q.empty()){
		int y= q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int yy = y+dy[i];
			int xx = x+dx[i];
			if(yy>=0 && yy<n && xx>=0 &&xx<m){
				if(arr_c[yy][xx] ==0){
					arr_c[yy][xx] =2;
					q.push({yy,xx});
				}
			}
		}
	}
	
	
	int cnt=0;
	for(int i=0; i< n; i++){
		for(int j=0; j<m; j++){
			if(arr_c[i][j]==0)
				cnt++;
		}
	}
	
	
	ans= max(ans,cnt);
	
	
}





void go(int y , int x, int cnt){
	
	
	if(cnt==0){
		memmove(arr_c, arr,sizeof(arr));
		go_check();
		return;
	}
	
	for(int i=0 ;i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] ==0){
				arr[i][j] =1;
				go(i,j,cnt-1);
				arr[i][j]= 0;
			}
				
		}
	}
}


int main(){
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	
	
	for(int i=0; i<n ;i++){
		for(int j=0; j<m; j++){
			if(arr[i][j]==0){
				arr[i][j]=1;
				go(i,j,2);
				arr[i][j]=0;
			}
			
		}
	}
	
	
	cout<<ans<<endl;
	
	
	
	
	
	
	return 0;
}
