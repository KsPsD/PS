#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;


int main(){
	
	string s;cin>>s;
	stack<char> st;
	int sum=0;
	bool flag= false;
	int cur =1;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='('){
			st.push(s[i]);
			cur*=2;
			continue;
		}
		else if(s[i] =='['){
			st.push(s[i]);
			cur*=3;
		continue;
		}
		else if(s[i] ==']'){
			if(st.empty()){
				flag=true;
				sum=0;
				break;
			}
			else if(st.top()=='['){
				if(s[i-1] !=']' && s[i-1] !=')'){
						sum+=cur;
					}
					st.pop();
			}
			else {
					flag=true;
					sum=0;
					break;
					
				}
				cur /=3;
			
		}
		else if(s[i] == ')'){
			if(st.empty()){
				flag=true;	
				sum=0;
				break;
			}
			else if(st.top()=='('){
				if(s[i-1] !=']' && s[i-1] !=')'){
						sum+=cur;
					}
					st.pop();
			}
			else {
					flag=true;
					sum=0;
					break;
				}
				
				cur /=2;
			
			}
			
		
		}
		
		if(flag) {
			cout<<0<<endl;
			return 0;
		}
		if(!st.empty()) {
			cout<<0<<endl;
			return 0;
		}
		else cout<<sum<<endl;

		
	}
	
	

