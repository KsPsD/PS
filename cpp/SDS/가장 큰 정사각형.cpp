#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;



int n,m;
int arr[1001][1001];
int dp[1001][1001]; 

int main(){
	
fastio;
	cin>>n>>m;
	for(int i=1; i<= n; i++){
		string s;cin>>s;
		for(int j=1; j<= s.size() ;j++){
			int num =s[j-1]-'0';
			arr[i][j] = num;
		
		}
	}
	
	
	int maxi=0;
	for(int i=1; i<=n ;i++)
		for(int j=1; j<=m ;j++)
			if(arr[i][j]!=0){
				arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j] , arr[i][j-1]) )+1;
				if(maxi < arr[i][j]) maxi=arr[i][j];				
			}

	cout<<maxi*maxi<<endl;
	
	return 0;
}
