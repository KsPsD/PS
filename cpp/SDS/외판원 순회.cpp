#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define MAX 16
#define INF 987654321

using namespace std;


int n;
int arr[MAX][MAX];

int cost[MAX][1<<MAX];
int ans_state=0;

int count(int state){
	int cnt=0;
	
	while(state!=0){
		cnt= cnt +(state &1);
		state = state >>1;
	}
	

	return cnt;
}

int dfs(int cur, int state){
	if(count(state) ==n) {
		if(arr[cur][0] == 0) return INF;
		else return arr[cur][0];
	}
	if(cost[cur][state] !=-1) return cost[cur][state];
	cost[cur][state] =INF;
	
	
	
	for(int i=0; i<n; i++){
		if(arr[cur][i] ==0) continue;
		if((state & (1<<i )) == (1<<i)) continue;
		
		cost[cur][state] = min(cost[cur][state], arr[cur][i] + dfs(i, state|(1<<i)) );
	}
	
	
	return cost[cur][state];
	
}



int main(){
	fastio;
	
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n ;j++){
			cin>>arr[i][j];
		}
	}
	ans_state = (1<<n) -1;
	
	memset(cost,-1,sizeof(cost));
	
	
	
	
	cout<<dfs(0,1)<<endl;	
	
	return 0;
} 
