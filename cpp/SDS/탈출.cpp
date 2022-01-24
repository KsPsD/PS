#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

#define INF 100000009

int r,c; 
char arr[50][50];
int ch[50][50];
int dy[]= {-1, 0, 1, 0};
int dx[] ={0,-1, 0,1};

struct pos{
	int y;
	int x;
	
};

queue<pos> q;
queue<pos> nextq;
queue<pos> qq;
bool End =false;
int ans=0;
void water(){
	nextq= queue<pos>();
	while(!qq.empty()){
		pos tmp =qq.front();
		qq.pop();
		for(int i=0; i<4; i++){
			int yy=  tmp.y+dy[i];
			int xx = tmp.x+dx[i];
			
			if(yy >=r || xx>=c || yy<0 || xx<0 || arr[yy][xx] =='D') continue;
			if(arr[yy][xx] =='.' && ch[yy][xx] != 1){
				ch[yy][xx] =1;
				nextq.push({yy,xx});
			}
		}
	}
}

void move(int y,int x){
		for(int i=0 ;i<4; i++){
			int yy = y+dy[i];
			int xx = x+dx[i];
			if(yy >=r || xx>=c || yy<0 || xx<0) continue;
			if(arr[yy][xx] =='D'){
				cout<<ans<<endl;
				End =true;
				return;
			}
			if(arr[yy][xx]=='.' && ch[yy][xx] !=1){
				ch[yy][xx]=1;
				q.push({yy,xx});
			}
		}
	}


int main(){


	cin>>r>>c;
	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>arr[i][j];
			if(arr[i][j]=='*'){
				qq.push({i,j});
				ch[i][j] =1;
			}
			else if(arr[i][j] =='S'){
				q.push({i,j});
				ch[i][j]=1;
			}
		}
	}
	
	
	
	while(1){
		water();
		qq=nextq;
		int num = q.size();
		if(num==0) {
			cout<<"KAKTUS"<<endl;
			break;
		}
		ans++;
		while(num--){
			pos tmp = q.front();
			q.pop();
			move(tmp.y,tmp.x);
			if(End) break;
			}
		
		if(End) break;
	
	}
	
	

	return 0;
}
