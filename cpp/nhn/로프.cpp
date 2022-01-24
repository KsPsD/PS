#include<bits/stdc++.h>


using namespace std;



int n; 
vector<int> v;

int main(){
	
	cin>>n;
	
	v.resize(n,0);
	for(int i=0; i<n; i++){
		cin>>v[i];
	} 
	
	int res =-1;
	sort(v.begin() ,v.end());
	for(int i=0; i<n; i++){
		res = max(res,v[i]*(n-i));
	}
	
	cout<<res<<endl;
	
	
	
	return 0;
}
