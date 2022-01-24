#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
using namespace std;

int n,k;
vector<int> v;
int dp[201][201];


int go(int lt, int rt){
	if(lt==rt) return 0;
	
	int &ret  = dp[lt][rt];
	if(ret != -1 ) return ret;
	
	ret =1e9;
	
	for(int k=lt; k<rt ;k++){
		int w = (v[k+1] !=v[lt]);
		ret = min(ret, go(lt,k)+ go(k+1,rt)+w );
	}
return ret;	
}



int main(){
	
	fastio;
	
	
	cin>>n>>k;
	
	
	v.resize(n+1);
	
	for(int i=1; i<=n ;i++){
		cin>>v[i];
	}
	
	memset(dp, -1 ,sizeof(dp));
	
	cout<<go(1,n)<<endl;
	
	
	
	return 0;
} 
