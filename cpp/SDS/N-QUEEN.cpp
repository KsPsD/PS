#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;

int n;
int cnt;
int arr[16];

bool check(int r){
	for(int i=0 ;i<r; i++){
		if(arr[r] ==arr[i] || abs(arr[r] - arr[i] ) == r-i) return false;
	}
	return true;
}


void queen(int r){
	if(r==n){
		cnt++;
	}
	else{
		for(int i=0 ;i<n; i++){
			arr[r]=i;
			if(check(r)) queen(r+1);
		}
	}
}


int main(){
	fastio;
	cin>>n;
	queen(0);
	
	cout<<cnt;
	
	
	return 0;
}
