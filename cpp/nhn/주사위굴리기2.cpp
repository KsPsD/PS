#include<bits/stdc++.h>

using namespace std;

int n,m,k; 
int arr[21][21];
int dy[] ={0,1,0,-1};
int dx[] ={1,0,-1,0};
int ch[21][21];
vector<int> dice ={1,2,3,4,5,6};

void rolling(int& y, int& x,int d){
	vector<int> tmp(6);
	
	if(d==0){ //µ¿
		y= y+dy[0];
		x = x+dx[0];
		tmp[0]= dice[3];
		tmp[1]= dice[1];
		tmp[2]= dice[0];
		tmp[3] = dice[5];
		tmp[4] = dice[4];
		tmp[5] = dice[2];
	
	}
	else if(d==1){//³² 
		y= y+dy[1];
		x = x+dx[1];
		tmp[0]= dice[1];
		tmp[1]= dice[5];
		tmp[2]= dice[2];
		tmp[3] = dice[3];
		tmp[4] = dice[0];
		tmp[5] = dice[4];
	}
	else if(d==2){//¼­ 
		y= y+dy[2];
		x = x+dx[2];
		tmp[0]= dice[2];
		tmp[1]= dice[1];
		tmp[2]= dice[5];
		tmp[3] = dice[0];
		tmp[4] = dice[4];
		tmp[5] = dice[3];
	}
	else{//ºÏ 
		y= y+dy[3];
		x = x+dx[3];
		tmp[0]= dice[4];
		tmp[1]= dice[0];
		tmp[2]= dice[2];
		tmp[3] = dice[3];
		tmp[4] = dice[5];
		tmp[5] = dice[1];
	}
	
	
	dice =tmp;
}


int main(){
	
	
	cin>>n>>m>>k;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>arr[i][j];
		}
	}

	int score=0;
	int y=1,x=1;
	int dir = 0;
	
	

	
	while(k--){
		int prey=y;
		int prex= x;
		vector<int> predice = dice;
		rolling(y,x,dir);
		if(y>n || y<1 || x>m || x<1){
			y=prey;
			x=prex;
			dice= predice;
			
			if(dir==0){
				rolling(y,x,2);
				dir=2;
			}
				
			else if(dir==1){
				rolling(y,x,3);
				dir=3;
			}
				
			else if(dir==2){
				rolling(y,x,0);
				dir=0;
			}
				
			else{
				rolling(y,x,1);
				dir=1;
			}
				
		}
		
	
		
		if(dice[5]>arr[y][x]){
			if(dir==0)
				dir=1;
			
			else if(dir==1)
				dir=2;
			else if(dir==2)
				dir =3;
			else
				dir=0;
		}
		else if(dice[5]<arr[y][x]){
			if(dir==0)
				dir=3;
			else if(dir==1)
				dir=0;
			else if(dir==2)
				dir=1;
			else 
				dir=2;
		}
	
		queue<pair<int,int> > q;
		
		memset(ch,0,sizeof(ch));
		ch[y][x]=1;
		q.push({y,x});
		int cnt=1;
		while(!q.empty()){
			int zy =q.front().first;
			int zx =q.front().second;
			q.pop();
			for(int i=0; i<4; i++){
				int zzy = zy+dy[i];
				int zzx = zx+dx[i];
				if(zzy <1 || zzy>n || zzx<1 || zzx>m) continue;
				if(arr[zzy][zzx] == arr[y][x] && ch[zzy][zzx] ==0){
					ch[zzy][zzx]=1;
					cnt++;
					q.push({zzy,zzx});
//					cout<<cnt<<endl;
				}
			}
		}
		
		int now_s = cnt * arr[y][x];
	
		score+=now_s;
		
	}
	
	
	cout<<score<<endl;
	
	
	
	return 0;
	
	
}
