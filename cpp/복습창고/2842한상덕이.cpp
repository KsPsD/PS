#include<bits/stdc++.h>

 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"

using namespace std;

int n;
int arr[51][51];
int start;
int ch[50][50];
vector<pair<int,int>>k;
int dy[] ={-1,-1,0,1,1,1,0,-1};
int dx[] = {0,-1,-1,-1,0,1,1,1};
pii start;
int ans= 1000002;
int lo,hi;





void dfs(int y,int x){
	if(y<0 || x<0|| y>=n || x>=0|| ch[y][x] || h[y][x] < lo || h[y][x] > hi) return ;
	ch[y][x]=1;
	for(int i=0; i< 8; i++){
		dfs(y+dy[i] , x+dx[i]);
	}
	return ;
}

void check(){
	int cnt=0;
	for(int i=0; i<k.size(); i++){
		if(ch[k[i].first][k[i].second] ==0 ) cnt++;
	}

return cnt== k.size();
}




int main(){
	
	fastio;
	cin>>n;
for(int i=0; i< n; i++){
		for(int j=0; j<n ;j++){
			cin>>arr[i][j];
			if(arr[i][j] =='P') {
				start.first=i;
				start.second=j;
			}			
			else if(arr[i][j] =='K'){
				k.push_back({i,j});
			}
		}
	}
	
	
	set<int>s;
	for(int i= 0;i<n; i++){
		for(int j=0; j<n; j++){
			cin>>h[i][j];
			s.insert(h[i][j]):
		}
	}
	
	auto l = s.begin(); auto r = s.begin();
	
	while(r!=s.end()){
		while(l!=s.end()){
			memset(ch,0,sizeof(ch));
			lo = *l ; hi= *r;
			dfs(start.first,start.second);
			if(!check()) break;
			ans =min(ans, *r -*l);
			l++;
		}
		r++;
	}
	
	
	
	
	
	
	return 0;
}
