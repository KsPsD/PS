#include<bits/stdc++.h>
 
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ll long long

using namespace std;

map<string, int> m;

int main(){
	fastio;
	string s;
	int cnt=0;
	while(getline(cin,s)){
		if(m.find(s)==m.end()){
			m[s]=1;
		}
		else{
			++m[s];
		}
		
		++cnt;
	}
	
	cout<<fixed;
	cout.precision(4);
	for(auto it=m.begin() ; it!=m.end() ;it++){
		cout<<it->first <<" " <<it->second *100 /(double) cnt<<endl;
	}
	
	
} 
