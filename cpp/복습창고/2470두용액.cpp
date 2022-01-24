#include<bits/stdc++.h>

 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define endl "\n"
#define INF 2000000000
using namespace std;


const int MAX = 100001;
int n;

int arr[MAX];
int res[2];


int main(){


cin>>n;
for(int i=0;i<n; i++){
	cin>>arr[i];
}	
	
	
sort(arr, arr+n);	
	
int l=0;
int r=n-1;
int mini =  INF;

while(l<r){
	int sum = arr[l]+arr[r];
	
	if(mini> abs(sum)){
		mini = abs(sum);
		res[0] = arr[l];
		res[1] = arr[r];
		
		
		if(sum==0){
			break;
		}
	}
	
	
	if(sum<0){
		l++;
	}
	
	else r--;
	
}


cout<<res[0]<<" "<<res[1];

	
	
	
	
	
	return 0;
} 
