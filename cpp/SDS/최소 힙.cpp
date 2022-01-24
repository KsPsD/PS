#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;


int main(){
	fastio;
	priority_queue<int, vector<int> ,greater<int>> pq;	
	
	int n;cin>>n;
	for(int i=0; i<n ;i++){
		int cmd;cin>>cmd;
		if(cmd==0){
			if(pq.empty()) cout<<0<<endl;
			else{
					cout<<pq.top()<<endl;
				pq.pop();
			}
		
		}
		else pq.push(cmd);
	}
	
	
} 
