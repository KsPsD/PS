#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define pii pair<int,int>
#define ll long long

using namespace std;

// const int MAX = 500001;
// int tree[MAX];
// int arr[MAX];
// int n;
// vector<pii> edge;


// void update(int idx, int val){
// 	while(idx<=n){
// 		tree[idx] +=val;
// 		idx+=(idx & -idx);
// 	}
// }


// ll query(int idx){
// 	ll ret = 0;
// 	while(idx){
// 		ret+=tree[idx];
// 		idx -= (idx & -idx);
// 	}
// 	return ret;
// }


// int main(){
	
	
// 	cin>>n;
	
// 	ll ans=0;
// 	for(int i=0; i<n; i++){
// 		int v;cin>>v;
// 		edge.push_back({v,i+1});
// 	}
	
	
// 	sort(edge.begin(), edge.end());
	
// 	for(int i=edge.size()-1; i>=0; i--){
// 		ans+=query(edge[i].second);
// 		update(edge[i].second, 1);
// 	}
	
	
// 	cout<<ans<<endl;
	
	
// 	return 0;
// } 


int N, arr[500005], sorted[500005];
ll cnt;
void merge(int left, int mid, int right) {
	int s1 = left, s2 = mid + 1, k = left;
	while (s1 <= mid && s2 <= right) {
		if (arr[s1] <= arr[s2]) {
			sorted[k++] = arr[s1++];
		}
		else {
			cnt += (mid - s1 + 1);
			sorted[k++] = arr[s2++];
		}
	}
	if (s1 <= mid) {
		for (int i = s1; i <= mid; i++) sorted[k++] = arr[i];
	}
	else {
		for (int i = s2; i <= right; i++) sorted[k++] = arr[i];
	}
	for (int i = left; i <= right; i++) arr[i] = sorted[i];
}
void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	mergeSort(1, N);
	cout << cnt;
}