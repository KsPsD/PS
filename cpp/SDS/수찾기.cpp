#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;


int arr[100001];
int main(){
	fastio;
	int n;cin>>n;
	 for(int i=0; i<n ;i++){
	 	cin>>arr[i];
	 }
	 sort(arr,arr+n);
	 int k;cin>>k;
	 
	 for(int i=0; i<k; i++){
	 	int a;cin>>a;
	if(binary_search(arr,arr+n, a)) {
			cout<<1<<"\n";
	}
	else cout<<0<<"\n";
	 }
	
	
} 
