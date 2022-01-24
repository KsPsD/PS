#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;
	priority_queue<int, vector<int>> max_pq;
	priority_queue<int, vector<int> , greater<int>> min_pq;
int arr[100010];
int main(){
	fastio;
	int n;cin>>n;

	
	
	for(int i= 0; i<n ; i++){	
		cin>>arr[i];
	}
	
	
	for(int i=0 ;i<n ;i++){
		if(max_pq.size() > min_pq.size()) min_pq.push(arr[i]);
		else max_pq.push(arr[i]);
		
		
		if(!max_pq.empty() && !min_pq.empty()){
			if(max_pq.top()> min_pq.top()){
				
				int Max_Value = max_pq.top();
                int Min_Value = min_pq.top();
 
                max_pq.pop(); min_pq.pop();
                
                max_pq.push(Min_Value);
                min_pq.push(Max_Value);
			}
			
			
		}
		cout<<max_pq.top()<<endl;
		
	}
	
	
} 
