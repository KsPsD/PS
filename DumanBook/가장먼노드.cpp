#include<bits/stdc++.h>


using namespace std;


queue<int> q;
vector<int> v[20001];
int ch[20001];
int dist[20001];
int solution(int n, vector<vector<int>> edge) {
    
    for(int i=0; i<edge.size(); i++){
    	int s, d;
    	s=edge[i][0];
    	d=edge[i][1];
    	v[s].push_back(d);
	}
	
	ch[1]=1;
	q.push(1);
	while(!q.empty()){
		int tmp =q.front();
		q.pop();
		for(int i=0; i<arr[tmp].size(); i++){
			int cur= arr[tmp][i];
			if(ch[cur] ==1) continue;
			dist[cur] = dist[tmp]+1;
			ch[cur]=1;
			maxi = max(maxi, dist[cur]);
			q.push(cur);
		}
	}
	int answer=0;
	for(int i=1; i<=n; i++){
		if(dist[i] ==maxi){
			answer++;
		}
	}
	
	return answer;
   
}


int main(){
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
