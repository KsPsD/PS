#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 1000000009
#define f(i,a,b) for(int i=a ; i<b;i++)
#define input(k) int k;cin>>k;



int main(){
	fastio;
	string s;getline(cin,s);
	stack<char> st;
	bool flag =false;
	for(int i=0; i<=s.size() ; i++){
		
		if(s[i] =='<'){
			while(!st.empty()){
				cout<<st.top();
				st.pop();
			}
			flag= true;
			cout<<s[i];
		}
		
		else if(s[i] =='>'){
			flag=false;
			cout<<s[i];
		}
		
		else if(flag){
			cout<<s[i];
		}
		
		else{
			if(s[i] ==' ' || s[i]=='\0'){
				while(!st.empty()){
					cout<<st.top();
					st.pop();
				}
				if(s[i] != '\0')
					cout<<s[i];
			}
			else{
				st.push(s[i]);
			}
		}
	
		
	}
	return 0;
}
