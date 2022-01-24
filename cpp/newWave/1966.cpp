#include<bits/stdc++.h>

using namespace std;

int t;
int cnt;
int main(){
	
	cin>>t;
	int n,m;
	while(t--){
		cin>>n>>m;
		queue<pair<int,int>> q;
		priority_queue<int> pq;
		for(int i=0; i<n; i++){
			cnt=0;
			int num;cin>>num;
			q.push({i,num});	
			pq.push(num);
		}
		
		while(!q.empty()){
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if(pq.top() == val){
				pq.pop();
				cnt++;
				if(idx == m){
					cout<<cnt<<endl;
					break;
				}
				
			}
			else{
				q.push({idx,val});
			}
		}
		
	}
	
	
	
	
	
	
	
	return 0;
} 
