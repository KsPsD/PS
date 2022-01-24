#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b; i++)
#define input(k) int k;cin>>k;



vector<int> v;

int go(){
	priority_queue<int, vector<int> , greater<int>> pq;
	for(int i=0; i<v.size(); i++){
		pq.push(v[i]);
	}
	
	int ret=0;
	
	while(pq.size()>1){
		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();
		pq.push(min1+min2);
		ret+=min1+min2;
	}
	
	return ret;
}



int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		v.clear();
		for(int i=0; i<n; i++){
			int num;cin>>num;
			v.push_back(num);
		}
		
		cout<<go()<<endl;
	}	
	
	
}
