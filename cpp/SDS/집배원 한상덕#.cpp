#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

//중요한 문제중 하나!!  최대의 차이를 최소로 구간을 정해서 bfs 돌림 근데 그걸 투 포인터로 


using namespace std;



int n;
char arr[50][50];
int h[50][50];
int ch[50][50];
int hi, lo;
vector<pair<int,int>>k;
int C=0;
int dy[] ={-1,-1,0,1,1,1,0,-1};
int dx[] = {0,-1,-1,-1,0,1,1,1};
pair<int ,int> start;
int ans=1000009;


void dfs(int y,int x){
	if(y<0|| x<0||y>=n||x>=n||ch[y][x]||h[y][x] <lo || h[y][x]>hi) return;
	ch[y][x]=1;
	for(int i= 0;i<8;i++)
		dfs(y+dy[i], x+dx[i]);
	return;
	
}

bool check(){
	int cnt=0;
	for(int i=0;i<k.size(); i++){
		if(ch[k[i].first][k[i].second]) ++cnt;
		
	}
	
	return cnt==k.size();
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
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			cin>>h[i][j];
			s.insert(h[i][j]);
		}
	
	set<int> ::iterator l=s.begin(), r=s.begin();
	while(r!=s.end()){
		while(l!=s.end()){
			memset(ch,0,sizeof(ch));
			lo=*l ;hi=*r;
			dfs(start.first,start.second);
			if(!check()) break;
		
			ans=min(ans, *r-*l);
			++l;
		}
		r++;
	}
	
	
	
	
	cout<<ans<<endl;
	
	

	
	
	return 0;
} 
