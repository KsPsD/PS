#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
using namespace std;




int n;

int maxi, mini;

int mina[3];
int maxa[3];
int cur[3];

int main(){
	cin>>n;
		
	cin>>maxa[0]>>maxa[1]>>maxa[2];
	mina[0]=maxa[0];
	mina[1]=maxa[1];
	mina[2]=maxa[2];
	
	for(int i=1 ;i<n ;i++){
		cin>>cur[0]>>cur[1]>>cur[2];
		int prev0 = maxa[0];
		int prev1 = maxa[1];
		int prev2 = maxa[2];
		
		maxa[0]= max(prev0, prev1) + cur[0]; 
		maxa[1]= max(prev0, max(prev1,prev2)) + cur[1];
		maxa[2]= max(prev1, prev2) + cur[2];
		
		
		prev0 = mina[0];
		prev1 = mina[1];
		prev2 = mina[2];
		
		mina[0]= min(prev0, prev1) + cur[0]; 
		mina[1]= min(prev0, min(prev1,prev2)) + cur[1];
		mina[2]= min(prev1, prev2) + cur[2];
		
	}
	
	
	maxi =max(maxa[0],max(maxa[1],maxa[2]));
	mini = min (mina[0], min(mina[1], mina[2]));
	
	cout<<maxi << " "<<mini<<endl;
	
	
	
	
	return 0;
	
} 
