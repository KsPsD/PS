#include<bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

string otob(char c){
	string res ="";
	int num = c-'0';
	if(num==0){
		return "0";
	}
	
	while(num!=0){
		res+=to_string(num%2);
		num/=2;
	}
	
	reverse(res.begin(), res.end());
	return res;
}



int main(){
	
	
	fastio;
	
	string s;cin>>s;
	for(int i=0; i<s.size(); i++){
		if(i==0)
			cout<<otob(s[i]);
		else{
			string tmp = otob(s[i]);
			while(tmp.size() !=3){
				tmp='0'+tmp;
			}
			cout<<tmp;
				
		
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}
