#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

int r,c;


int dy[] ={ -1,0,1,0};
int dx[] = {0,-1,0,1};

char arr[51][51]; 
int ch[51][51];
queue<pii> waterq;
queue<pii> bq;

pii water;
pii biber;


int main(){
	
	int cnt=0;
	
	
	cin>>r>>c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>arr[i][j];
			if(arr[i][j] =='*'){
				water.first = i;
				water.second =j;
				waterq.push({i,j});
			}
			else if(arr[i][j] == 'S'){
				biber.first =i;
				biber.second=j;
				bq.push({i,j});
				ch[i][j] = 1;
				}
			}
			
		}
		
		while(!bq.empty()){
		
			int size= waterq.size();
			for(int i=0; i<size; i++){
			int y = waterq.front().first;
			int x = waterq.front().second;
			waterq.pop();
			for(int i=0; i<4; i++){
				int yy= y+dy[i];
				int xx = x+dx[i];
				if(yy >=r || yy<0 || xx>=c || xx<0) continue;
				if(arr[yy][xx] == '.' ) {
						arr[yy][xx] ='*';
						waterq.push({yy,xx});
						
				}
			}
		} 
		
		
	int bsize = bq.size();
		cnt++;
	for(int i=0; i<bsize; i++){
		
		int y  = bq.front().first;
		int x =  bq.front().second;
		bq.pop();
		
	
		
		for(int i=0 ;i< 4; i++){
			int yy= y+dy[i];
			int xx=  x+dx[i];
			if(yy >=r || yy<0 || xx>=c || xx<0) continue;
			if(arr[yy][xx] == '.' && ch[yy][xx] == 0){
				
				ch[yy][xx]=1;
				bq.push({yy,xx});
				cout<<" cnt: "<<cnt<<" yy: :" <<yy<< " xx: "<<xx<<endl;
				
			}
			else if(arr[yy][xx]=='D'){
				
				cout<<cnt<<endl;
				exit(0);
			}
		
			
		}
	}
		
	
		
	}
	
	
	cout<<"KAKTUS"<<endl;
	
		
	
	
	
	
	
	
	return 0;
} 
