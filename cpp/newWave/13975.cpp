#include<bits/stdc++.h>
#define fastio  ios::sync_with_stdio(false), cin.tie(NULL), cin.tie(NULL)
#define endl "\n"
using namespace std;


int main(){
	
	fastio;
	
	int t;cin>>t;
	
	
	while(t>0){
		
		int k;cin>>k;
		long long sum=0;
		priority_queue<long long, vector<long long> ,greater<long long>> pq;
		
		for(int i=0; i<k ;i++){
			int a;
			cin>>a;
			pq.push(a);
		}

		while(1){
			long long first=pq.top();
			pq.pop();
			long long second=pq.top();
			pq.pop();
			
			long long cur=first+second;
			sum+=cur;
			
			pq.push(cur);
			
			if(pq.size()==1){
				cout<<sum<<endl;
				break;
			}
				
		}

		t--;
	}

	
	return 0;
}
