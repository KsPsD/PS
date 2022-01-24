#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;



int main(){
	fastio;
	int n; cin>>n;
	priority_queue<int , vector<int> , greater<int> > pq; 
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int a;
			cin>>a;
			pq.push(a);
			if(pq.size() > n)
				pq.pop();
		}
	}
	
	cout<<pq.top();
	
	
	
	
	
	
	
	
	return 0;
}
