#include<bits/stdc++.h>



using namespace std;


int main(){
	
	int n,b;
	vector<int>v;
	cin>>n>>b;
	
	while(n>1){
		v.push_back(n%b);
		n /= b;
	}	
	if(n==1) v.push_back(1);
	
	reverse(v.begin(),v.end());
	
	
	for(int a: v){
		if(a>=10) cout<<char(a+55);
		else cout<<a;
	}
	
	
	
	
	
	
	return 0;
}
