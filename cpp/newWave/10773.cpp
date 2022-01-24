#include<bits/stdc++.h>


using namespace std;

int  k;

int main(){
	cin>>k;
	stack<int> st;
	
	for(int i=0; i<k; i++){
		int a;cin>>a;
		if(a ==0 ){
			st.pop();
		}
		else{
			st.push(a);	
		}
		
		
	}
	
	int ans=0;
	
	while(!st.empty()){
		int val = st.top();
		st.pop();
		ans+=val;
	}
	
	
	
	cout<<ans<<endl;
	
	
	
	
	return 0;
}
