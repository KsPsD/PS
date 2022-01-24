#include<bits/stdc++.h>
#include<regex>

using namespace std;

int main(){
	
	string s;
	getline(cin,s);
	
	
	s=std::regex_replace(s, regex("[^A-Za-z0-9]"), "");
	
//	for(auto e:s){
//		if(!isalnum	(e)){
//			s.erase(remove(s.begin(), s.end(), e), s.end());
//		}
//	}
	
	transform(s.begin(),s.end(),s.begin(),::tolower);

	cout<<s<<endl;

	if(s == string(s.rbegin(),s.rend())){
		cout<<"true"<<endl;
	}	
	else cout<<"false"<<endl;
	
	return 0;
}
