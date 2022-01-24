#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

int main(){
	fastio;
	int n;
	stack<int> st;
	cin>>n;
	string cmd;
	int num;
	for(int i=0; i<n; i++){
		cin>>cmd;
		if(cmd=="push"){
			cin>> num;
			st.push(num);
		}
		else if(cmd=="top"){
			if(st.empty()) {
				cout<<-1<<endl;
				continue;
			}
			cout<<st.top()<<endl;
		}
		else if(cmd=="size"){
			cout<<st.size()<<endl;
		}
		else if(cmd=="empty"){
			if(st.empty())cout<<1<<endl;
			else cout<<0<<endl;
		}
		else{
			if(st.empty()) {
				cout<<-1<<endl;
				continue;
			}
			cout<<st.top()<<endl;
			st.pop();
		}
	}
	
	
	
	
	return 0;
} 
