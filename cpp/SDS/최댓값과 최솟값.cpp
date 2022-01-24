#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define endl '\n'
#define pii pair<int ,int> 
using namespace std;

#define INF 100000009
int n,m;

const int MAX = 100000;

int arr[MAX+1];
pii tree[4*MAX];


pii query(int start, int end, int node, int left, int right){
if (start > right || end < left) return { INT_MAX, 0 };
	
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) >> 1;
	
	pii l = query(start, mid, node * 2, left, right);
	pii r = query(mid + 1, end, node * 2 + 1, left, right);

	pii res;
	res.first = min(l.first, r.first);
	res.second = max(l.second, r.second);

	return res;
}


 pii init(int node, int s,int e){
	if(s==e) {
		tree[node].first=arr[s];
		tree[node].second= arr[s];
		return tree[node];
	}
	ll mid =(s+e)/2;
	pii left =init(2*node, s,mid);
	pii right =init(2*node+1, mid+1,e);
	
	tree[node].first =	min(left.first,right.first);
	tree[node].second =	max(left.second,right.second);

	return tree[node];
}



int main(void)
{
	fastio;

	cin>>n>>m;

	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	init(1,1,n);
	
	for(int i= 0; i<m; i++){
		int lt,rt;cin>>lt>>rt;
		pii tmp = query(1, n, 1, lt, rt);
		
		cout<<tmp.first<<" "<<tmp.second<<endl;
	}

	return 0;
}
