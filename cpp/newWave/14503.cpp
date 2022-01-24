#include<bits/stdc++.h>

using namespace std;


int n,m;
int s_y, s_x, s_d;

int ch[51][51];

int arr[51][51];
int dy[] ={-1,0,1,0};
int dx[] = {0,1,0,-1};



void changeDir(int &dir){
	if(dir==0){
		dir=1;
	}
	else if(dir==1){
		dir=2;
	}
	else if(dir==2){
		dir=3;
	}
	else {
		dir=0;
	}
}

struct Dir{
	int y,x,dir;
};

int ans=0;

int main(){
	
	cin>>n>>m;
	cin>>s_y>>s_x>>s_d;
	
	for(int i=0; i<n ;i ++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	
	queue<Dir> q;
	q.push({s_y,s_x,s_d});
	
	while(!q.empty()){
		Dir tmp = q.front();
		int origin_dir = tmp.dir;
		
		if(arr[tmp.y][tmp.x] ==0){
			arr[tmp.y][tmp.x]=2;
			ans++;
		}
		
		q.pop();
		
		bool flag=false;
		
	
		for(int i=0; i<4; i++){
		int newDir = (tmp.dir + (3-i)) %4;
		int yy=tmp.y+dy[newDir];
		int xx=tmp.x +dx[newDir];
	
			
			if(yy >=0 && yy<n && xx>=0 && xx<m){
			if(arr[yy][xx]==0){
				q.push({yy,xx,newDir});
				flag=true;
				break;
			}
		}
		}
		
		
		if(!flag){
			int back_y= tmp.y- dy[tmp.dir];
			int back_x = tmp.x - dx[tmp.dir];
			if(back_y >=0 && back_y <n && back_x >=0 && back_x<m && arr[back_y][back_x] !=1){
				q.push({back_y,back_x,tmp.dir});
			}
			else break;
		}
		
		
}
	cout<<ans<<endl;
	
	return 0;
}
