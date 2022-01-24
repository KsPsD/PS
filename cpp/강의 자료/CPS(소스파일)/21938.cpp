#include<bits/stdc++.h>

using namespace std;


int n,m,t;

int arr[3003][3003];
int arr2[1001][1001];
int ch[1001][1001];
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void bfs(int y,int x){
	queue<pair<int,int> > q;
	q.push({y,x});
	
	while(!q.empty()){
		auto tmp  = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int yy = tmp.y+dy[i];
			int xx = tmp.x+dx[i];
		
			if(0<=yy<n && 0<=xx<m && ch[yy][xx]==0 && arr2[yy][xx] >=t){
				q.push({yy,xx});
				ch[yy][xx]=1;
			}
			
		
		}
	}
}


int main(){
	
	
	cin>>n>>m;
	int num=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			arr2[i][j] = (a + b + c) / 3;
		}
	}
	
	
	cin>>t;
	
	int cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr2[i][j]>=t && ch[i][j]==0){
				bfs(i,j);
				cnt++;
			}
		}
	}
	
	cout<<cnt<<endl;
	return 0;
}
