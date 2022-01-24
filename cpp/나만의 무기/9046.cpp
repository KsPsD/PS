#include<bits/stdc++.h>


using namespace std;


bool cmp(pair<char,int> &a, pair<char,int> &b){
	return a.second > b.second;
}

int main(){


	int n;cin>>n;
	cin.ignore();
	for(int i=0; i<n; i++){
		map<char,int> m;
		string s;getline(cin,s);
		for(int i=0; i<s.size(); i++){
			if(s[i]==' ')continue;
			m[s[i]]++;
		}
		
		vector<pair<char,int>> v(m.begin(), m.end());
		sort(v.begin(), v.end() ,cmp);
		
		if(v[0].second == v[1].second){
			cout<<"?"<<endl;
		}
		else{
			cout<<v[0].first<<endl;
		}
		
	}
	
	
	
	
	
	
	
	
	return 0;
}
