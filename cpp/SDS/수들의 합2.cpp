#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
using namespace std;

int cnt=0;
int main(){
	int n,m;cin>>n>>m;
	vector<int> v;
	for(int i=0 ;i<n; i++){
		int a;cin>>a;
		v.push_back(a);
	}
	int lt=0;
	int rt=0;
	int sum=0;
	while(lt<n){
		if(sum >=m){
			sum-=v[lt++];
		}
		else if(rt==n){
			break;
		}
		else{
			sum+=v[rt++];
		}
		
		
		if(sum==m)cnt++;
	}
	
	cout<<cnt<<endl;
	
	
	
	return 0;
} 
