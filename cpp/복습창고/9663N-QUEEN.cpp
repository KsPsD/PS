#include<bits/stdc++.h>

#define ll long long
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
using namespace std;



int n;
int arr[15];
int cnt =0;
bool check(int r){
	for(int i=0; i<r; i++){
		if(arr[r] == arr[i] || abs(arr[r] - arr[i] ) == abs(r-i) ) return false;
	}
	return true;
}


void dfs(int r){
	if(r==n){
		cnt++;
		return;
	}
	
	for(int i=0; i<n ;i++){
			arr[r]= i;
			if(check(r)) dfs(r+1);
		}
}


int main(){
	fastio;
	cin>>n;
	
	
	dfs(0);
	

	cout<<cnt<<endl;
	
	
	
	
	return 0;
}
