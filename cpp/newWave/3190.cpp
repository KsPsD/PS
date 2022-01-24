#include<bits/stdc++.h>


using namespace std;

const int MAX = numeric_limits<int>::max();
const int MIN = numeric_limits<int>::min();


int n, k,l;
vector<pair<int,char> > timer;
int dy[] ={0,1,0,-1};
int dx[] = {1,0,-1,0};
int Time;
int d;
int arr[101][101];
int y,x;
int idx;

int change_dir(int d, char cmd){
	if(cmd=='L'){
		if(d==0) return 3;
		else if(d==1) return 0;
		else if(d==2) return 1;
		else if(d==3) return 2;
	}
	else{
		if(d==0) return 1;
		else if(d==1) return 2;
		else if(d==2) return 3;
		else if(d==3) return 0;
	}
}






int main(){
	
	cin>>n>>k;
	arr[0][0] = 2;
	for(int i=0; i<k; i++){
		int a,b;cin>>a>>b;
		arr[a-1][b-1]=1;
	}
	cin>>l;
	for(int i=0; i<l; i++){
		int t;char c;
		cin>>t>>c;
		timer.push_back({t,c});
	}
	
	deque<pair<int, int> > dq;
	dq.push_back({y,x});
	while(true){
		Time+=1;
		int yy= y+dy[d];
		int xx= x+dx[d];
		
		if(yy<0 || xx<0 ||  yy>=n || xx >=n || arr[yy][xx]==2){
			break;
		}
		
		else if(arr[yy][xx]  == 0){
			arr[yy][xx]=2;
			arr[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
			dq.push_front({yy,xx});
		}
		else if(arr[yy][xx]==1){
			arr[yy][xx]=2;
			dq.push_front({yy,xx});
		}
		
		
		if(idx<timer.size()){
			if(Time==timer[idx].first){
				if(timer[idx].second == 'L')
					d=change_dir(d,'L');
				else if(timer[idx].second == 'D')
					d=change_dir(d,'D');
				
				idx+=1;
			}
		}
	
		y=yy;
		x=xx;
		
	}
	
	cout<<Time<<endl;
	return 0;
}

