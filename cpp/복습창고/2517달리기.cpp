#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"

using namespace std;

const int MAX  = 500001;

int arr[MAX];
vector<int> sarr;
ll tree[MAX];
int n;


//ll update(int node, int s, int e, int idx, int val){
//	if(idx< s || idx>e) return tree[node];
//	if(s==e) return tree[node] =val;
//	int mid = (s+e)/2;
//	return tree[node] = update(2*node, s, mid , idx,val) + update(2*node+1, mid+1, e, idx,val);
//}
//
//ll sum(int node ,int s,int e, int l ,int r){
//	if(r<s || l> e) return 0;
//	if(l<=s && e<=r) return tree[node];
//	int mid= (s+e)/2;
//	return sum(2*node, s , mid , l,r) + sum(2*node+1 ,mid+1, e, l,r);
//}
void update(int idx, int val){
	while(idx<=n){
		tree[idx] +=val;
		idx+=(idx & -idx);
	}
}
int query(int idx){
	int ret= 0;
	while(idx){
		ret+=tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}


int main(){
	fastio;
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sarr.push_back(arr[i]);
	}
	
	sort(sarr.begin(), sarr.end());

	
	for(int i=0; i< n; i++){
		
		int idx = (lower_bound(sarr.begin(), sarr.end() , arr[i]) - sarr.begin()) +1;
		cout<<"arr: "<<arr[i] << " idx:  "<<idx<<endl;
		update(idx,1);
		cout<<(i+1) - query(idx-1)<<endl;
	}
	
	
	
	
	return 0;
}
