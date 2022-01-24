#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m;
	cin>>n>>m;
	
	vector<int> v(n,0);
	
	for(int i=0; i<n; i++){
		cin>>v[i];
	} 
	
	int lt= 0, rt =0;
	
	int cur =v[lt];
	int cnt=0;
	while(lt<n){
		if(cur<m && rt != n-1){
			cur+=v[++rt];
			
		}
		else{
			if(cur == m){
				cnt++;
			}	
			cur-=v[lt++];
		}
	}
	
	cout<<cnt<<endl;
}
